# LSM6DSL example for the B-L475E-IOT01A board
This example shows how to use the LSM6DSL sensor

## Supported Hardware
This example can run on the [B-L475E-IOT01A](https://www.st.com/content/st_com/en/products/evaluation-tools/product-evaluation-tools/mcu-mpu-eval-tools/stm32-mcu-mpu-eval-tools/stm32-discovery-kits/b-l475e-iot01a.html) and on the [B-L4S5I-IOT01A](https://www.st.com/content/st_com/en/products/evaluation-tools/product-evaluation-tools/mcu-mpu-eval-tools/stm32-mcu-mpu-eval-tools/stm32-discovery-kits/b-l4s5i-iot01a.html)

The example can be generated to support any STM32 and LSM6DSL. It can be a Nucleo board + X-NUCLEO

## Supported IDEs
This project was tested with IAR 8.50.6
This project can be generated for STM32CubeIDE and Keil

## Required Hardware
* [B-L475E-IOT01A](https://www.st.com/content/st_com/en/products/evaluation-tools/product-evaluation-tools/mcu-mpu-eval-tools/stm32-mcu-mpu-eval-tools/stm32-discovery-kits/b-l475e-iot01a.html) or [B-L4S5I-IOT01A](https://www.st.com/content/st_com/en/products/evaluation-tools/product-evaluation-tools/mcu-mpu-eval-tools/stm32-mcu-mpu-eval-tools/stm32-discovery-kits/b-l4s5i-iot01a.html)

* USB Micro cable

## Required software
* IAR
* [STM32CubeMX](www.st.com/STM32CubeMX)
* [STMicroelectronics.X-CUBE-COMPONENTS.1.4.1.pack](https://github.com/SlimJallouli/X-CUBE-COMPONENTS/blob/main/Pack/STMicroelectronics.X-CUBE-COMPONENTS.1.4.1.pack)
* Teraterm or any other terminal software (Termite)

## Install STMicroelectronics.X-CUBE-COMPONENTS.1.4.1.pack
1. Download [STMicroelectronics.X-CUBE-COMPONENTS.1.4.1.pack](https://github.com/SlimJallouli/X-CUBE-COMPONENTS/blob/main/Pack/STMicroelectronics.X-CUBE-COMPONENTS.1.4.1.pack)
1. Open STM32CubeMX
1. Click **INSTALL/REMOVE**
1. Click **From Local**
1. Select the **STMicroelectronics.X-CUBE-COMPONENTS.1.4.1.pack** you just downloaded
1. Click **Open**
1. Accept the license

## How to run
1. Connect your STM32 board to your computer through the ST-Link USB
1. Open Teraterm and set it to your ST-Link COM port, 115200, 8 bits, 1 stop, no parity
1. Open IAR project
1. Build and run

## Output
![Termonal](media/Terminal.png)