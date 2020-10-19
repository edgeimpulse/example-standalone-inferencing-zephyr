# example standalone inferencing nrf52 zephyr
This runs an exported impulse on any Mbed-enabled development board. 

## Overview



## Building and Running


This application can be built and executed on [nRF52840dk_nrf52840](https://docs.zephyrproject.org/latest/boards/arm/nrf52840dk_nrf52840/doc/index.html) as follows:

```bash
# From the root of the application repository
west build -b nrf52840dk_nrf52840
west flash
```

## Sample Output

```bash
Features (0 ms.): 1.573805 0.496032 2.039807 1.984127 0.366191 2.976190 0.214352 0.435654 0.017216 0.013104 0.001996 5.901122 0.496032 6.714868 5.456349 0.126027 0.000000 0.000000 4.733998 1.646608 0.216359 0.026275 1.976011 0.496032 1.886032 3.472222 0.177765 0.000000 0.000000 0.372830 0.271108 0.061800 0.002095 ␍␊
Running neural network...␍␊
Predictions (time: 0 ms.):␍␊
idle:⇥	0.000000␍␊
snake:⇥	0.000000␍␊
updown:⇥	0.996094␍␊
wave:⇥	0.003906␍␊
run_classifier returned: 0␍␊
Predictions (DSP: 0 ms., Classification: 0 ms., Anomaly: 0 ms.): ␍␊
[0.00000, 0.00000, 0.99609, 0.00391]␍␊
```
