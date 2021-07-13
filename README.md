# Edge Impulse Example: stand-alone inferencing (Zephyr)

This runs an exported impulse on most Zephyr development boards. See the documentation at [Running your impulse locally (Zephyr)](https://docs.edgeimpulse.com/docs/running-your-impulse-locally-zephyr).

## Tested on

This example has been tested on the following Zephyr targets:

* [nrf52dk_nrf52832](https://docs.zephyrproject.org/latest/boards/arm/nrf52dk_nrf52832/doc/index.html)
* [nRF52840dk_nrf52840](https://docs.zephyrproject.org/latest/boards/arm/nrf52840dk_nrf52840/doc/index.html)
* [nRF5340dk_nrf5340](https://docs.zephyrproject.org/latest/boards/arm/nrf5340dk_nrf5340/doc/index.html)
* [nrf9160dk_nrf9160](https://docs.zephyrproject.org/latest/boards/arm/nrf9160dk_nrf9160/doc/index.html)

With nRF Connect SDK 1.6.0, but should run as-is on most Zephyr development boards. If you run this example on a non-Arm development board you'll want to disable the CMSIS-DSP and CMSIS-NN macros in [CMakeLists.txt](CMakeLists.txt).
