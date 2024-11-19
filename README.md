[![Test Build](https://github.com/edgeimpulse/example-standalone-inferencing-zephyr/actions/workflows/test-build.yml/badge.svg?branch=master)](https://github.com/edgeimpulse/example-standalone-inferencing-zephyr/actions/workflows/test-build.yml)
# Edge Impulse Example: standalone inferencing (Zephyr)

This runs an exported impulse on most Zephyr development boards. See the documentation at [Running your impulse locally (Zephyr)](https://docs.edgeimpulse.com/docs/running-your-impulse-locally-zephyr).

## Tested on

This example has been tested on the following Zephyr targets:
* [apollo4p_blue_kxr_evb](https://docs.zephyrproject.org/latest/boards/ambiq/apollo4p_blue_kxr_evb/doc/index.html)
* [nrf52dk_nrf52832](https://docs.zephyrproject.org/latest/boards/nordic/nrf52dk/doc/index.html)
* [nrf52840dk_nrf52840](https://docs.zephyrproject.org/latest/boards/nordic/nrf52840dk/doc/index.html)
* [nrf5340dk_nrf5340_cpuapp](https://docs.zephyrproject.org/latest/boards/nordic/nrf5340dk/doc/index.html)
* [nrf9160dk_nrf9160](https://docs.zephyrproject.org/latest/boards/nordic/nrf9160dk/doc/index.html)

You can also run the example with Nordic nRF Connect SDK and the following boards:
* [thingy91_nrf9160_ns](https://developer.nordicsemi.com/nRF_Connect_SDK/doc/latest/nrf/working_with_nrf/nrf91/thingy91.html#building-and-programming-from-the-source-code)
* [thingy53_nrf5340_cpuapp](https://developer.nordicsemi.com/nRF_Connect_SDK/doc/latest/nrf/working_with_nrf/nrf53/thingy53.html#building-and-programming-from-the-source-code)

If you run this example on a non-Arm development board you'll want to disable the CMSIS-DSP and CMSIS-NN macros in [CMakeLists.txt](CMakeLists.txt), by adding the following definition:

```
-DEIDSP_USE_CMSIS_DSP=0
```
