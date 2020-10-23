# Running your Impulse locally/On your zephyr board

Impulses can be deployed as a C++ library. This packages all your signal processing blocks, configuration and learning blocks up into a single package. You can include this package in your own application to run the impulse locally. In this tutorial you'll export an impulse, and build an application for the nRF52840DK board running Zephyr RTOS to classify sensor data.

> **Knowledge required**  
> This tutorial assumes that you're familiar with building applications for the [nRF52840DK](nrf52840dk_docs) or other **Zephyr RTOS** supported board, and have your environment set up to compile applications for this platform. Currently application is optimized for [NRF Connect SDK v1.3.0](ncs_130_docs) which uses [Zephyr RTOS v2.3.0-rc1](zephyr_230_docs)

## Prerequisites

Make sure you followed the Continuous motion recognition tutorial, and have a trained impulse. If the build system is not in place you should follow these guides:
* [install NRF Connect SDK](ncs_install) - this will install Zephyr and all dependencies
* [install Segger J-Link tools](jlink_tools) for firmware flashing. 
