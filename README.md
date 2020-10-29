# example standalone inferencing nrf52 zephyr
This runs an exported impulse on Nordic Semi Zephyr enabled development board. 

## Overview

Working on boards:
* nrf52dk_nrf52832
* nrf52840dk_nrf52840
* nrf9160dk_nrf9160


## Building and Running


This application can be built and executed on [nRF52840dk_nrf52840](https://docs.zephyrproject.org/latest/boards/arm/nrf52840dk_nrf52840/doc/index.html) as follows:

```bash
# From the root of the application repository
west build -b nrf52840dk_nrf52840
west flash
```

## Sample Output

```bash
*** Booting Zephyr OS build v2.3.0-rc1-ncs1  ***
Edge Impulse standalone inferencing (Zephyr)
Features (14 ms.): 1.573805 0.496032 2.039807 1.984127 0.366190 2.976190 0.214352 0.435654 0.017216 0.013104 0.001996 5.901122 0.496032 6.714868 5.456349 0.126 
Running neural network...
Predictions (time: 0 ms.):
idle:   0.000000
snake:  0.000000
updown: 0.996094
wave:   0.003906
run_classifier returned: 0
Predictions (DSP: 14 ms., Classification: 0 ms., Anomaly: 0 ms.): 
[0.000000, 0.000000, 0.996094, 0.003906]
```
