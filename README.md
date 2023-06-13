[![Test Build](https://github.com/edgeimpulse/example-standalone-inferencing-zephyr/actions/workflows/test-build.yml/badge.svg?branch=master)](https://github.com/edgeimpulse/example-standalone-inferencing-zephyr/actions/workflows/test-build.yml)
# Edge Impulse Example: standalone inferencing (Zephyr)

This runs an exported impulse on most Zephyr development boards. See the documentation at [Running your impulse locally (Zephyr)](https://docs.edgeimpulse.com/docs/running-your-impulse-locally-zephyr).

## Tested on

This example has been tested on the following Zephyr targets:

* [nrf52dk_nrf52832](https://docs.zephyrproject.org/latest/boards/arm/nrf52dk_nrf52832/doc/index.html)
* [nRF52840dk_nrf52840](https://docs.zephyrproject.org/latest/boards/arm/nrf52840dk_nrf52840/doc/index.html)
* [nrf5340dk_nrf5340_cpuapp](https://docs.zephyrproject.org/latest/boards/arm/nrf5340dk_nrf5340/doc/index.html)
* [nrf9160dk_nrf9160](https://docs.zephyrproject.org/latest/boards/arm/nrf9160dk_nrf9160/doc/index.html)

You can also run the example with Nordic nRF Connect SDK and the following boards:
* [thingy91_nrf9160_ns](https://developer.nordicsemi.com/nRF_Connect_SDK/doc/latest/nrf/working_with_nrf/nrf91/thingy91.html#building-and-programming-from-the-source-code)
* [thingy53_nrf5340_cpuapp](https://developer.nordicsemi.com/nRF_Connect_SDK/doc/latest/nrf/working_with_nrf/nrf53/thingy53.html#building-and-programming-from-the-source-code)

With nRF Connect SDK 1.6.0 and above, but should run as-is on most Zephyr development boards. If you run this example on a non-Arm development board you'll want to disable the CMSIS-DSP and CMSIS-NN macros in [CMakeLists.txt](CMakeLists.txt), by adding the following definition:

```
-DEIDSP_USE_CMSIS_DSP=0
```
