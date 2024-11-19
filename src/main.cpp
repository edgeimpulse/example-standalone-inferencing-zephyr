// Zephyr 3.1.x and newer uses different include scheme
#include <version.h>
#if (KERNEL_VERSION_MAJOR > 3) || ((KERNEL_VERSION_MAJOR == 3) && (KERNEL_VERSION_MINOR >= 1))
#include <zephyr/kernel.h>
#else
#include <zephyr.h>
#endif
#include "edge-impulse-sdk/classifier/ei_run_classifier.h"
#include "edge-impulse-sdk/dsp/numpy.hpp"
#ifdef EI_NORDIC
#include <nrfx_clock.h>
#endif

static const float features[] = {
    // copy raw features here (for example from the 'Live classification' page)
    // see https://docs.edgeimpulse.com/docs/running-your-impulse-locally-zephyr
};

int raw_feature_get_data(size_t offset, size_t length, float *out_ptr) {
    memcpy(out_ptr, features + offset, length * sizeof(float));
    return 0;
}

int main() {
    // This is needed so that output of printf is output immediately without buffering
    setvbuf(stdout, NULL, _IONBF, 0);

#ifdef CONFIG_SOC_NRF5340_CPUAPP // this comes from Zephyr
    // Switch CPU core clock to 128 MHz
    nrfx_clock_divider_set(NRF_CLOCK_DOMAIN_HFCLK, NRF_CLOCK_HFCLK_DIV_1);
#endif

    printk("Edge Impulse standalone inferencing (Zephyr)\n");

    if (sizeof(features) / sizeof(float) != EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE) {
        printk("The size of your 'features' array is not correct. Expected %d items, but had %u\n",
            EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE, sizeof(features) / sizeof(float));
        return 1;
    }

    ei_impulse_result_t result = { 0 };

    while (1) {
        // the features are stored into flash, and we don't want to load everything into RAM
        signal_t features_signal;
        features_signal.total_length = sizeof(features) / sizeof(features[0]);
        features_signal.get_data = &raw_feature_get_data;

        // invoke the impulse
        EI_IMPULSE_ERROR res = run_classifier(&features_signal, &result, false);
        printk("run_classifier returned: %d\n", res);

        if (res != 0) return 1;

        printk("Predictions (DSP: %d ms., Classification: %d ms., Anomaly: %d ms.): \n",
                result.timing.dsp, result.timing.classification, result.timing.anomaly);
#if EI_CLASSIFIER_OBJECT_DETECTION == 1
        bool bb_found = result.bounding_boxes[0].value > 0;
        for (size_t ix = 0; ix < result.bounding_boxes_count; ix++) {
            auto bb = result.bounding_boxes[ix];
            if (bb.value == 0) {
                continue;
            }
            printk("    %s (%f) [ x: %u, y: %u, width: %u, height: %u ]\n", bb.label, bb.value, bb.x, bb.y, bb.width, bb.height);
        }
        if (!bb_found) {
            printk("    No objects found\n");
        }
#else
        for (size_t ix = 0; ix < EI_CLASSIFIER_LABEL_COUNT; ix++) {
            printk("    %s: %.5f\n", result.classification[ix].label,
                                    result.classification[ix].value);
        }
#if EI_CLASSIFIER_HAS_ANOMALY == 1
        printk("    anomaly score: %.3f\n", result.anomaly);
#endif
#endif
        k_msleep(2000);
    }
}
