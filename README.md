# X-CUBE-COMPONENTS

***This is not an official ST pack. This pack is provided as is and without support***

## About
This is a [CMSIS pack](https://www.keil.com/pack/doc/CMSIS/Pack/html/index.html) enhanced for [STM32CubeMX](www.st.com/STM32CubeMX) (or [STM32Cube Expansion Package](https://wiki.st.com/stm32mcu/wiki/How_to_develop_a_STM32Cube_Expansion_Package)). The pack brings generic components (LED, Button, Sensors, Wi-Fi) drivers to be used in any project with any STM32. You do not need any specefic BSP files to able to use these divers in your project. This CMSIS pack allows you to use STM32CubeMX to import the components and to customise the driver to fit your hardware. This makes integrating sensors or any components in your project and port the projects to a new hardware ver easy.

More details on how to develop a STM32Cube Expansion Package can be found [here](https://wiki.st.com/stm32mcu/wiki/How_to_develop_a_STM32Cube_Expansion_Package)

## Supported components:
* LED in GPIO, PWM or Custom driver. Custome driver can be used in the case the LED is behind an IO expander or an LED driver. In PWM mode you can dim the LED luminosity
* [Grove - LCD RGB Backlight](https://wiki.seeedstudio.com/Grove-LCD_RGB_Backlight/). The driver is drived from this [Git repo](https://github.com/mahmood-ul-hassan/Grove_LCD_RGB_Backlight)
* [HTS221](https://www.st.com/en/mems-and-sensors/hts221.html) Humidity and temperature sensor in I2C mode
* [LIS3MDL](https://www.st.com/content/st_com/en/products/mems-and-sensors/e-compasses/lis3mdl.html) magnetomiter in I2C mode
* [LPS22HB](https://www.st.com/content/st_com/en/products/mems-and-sensors/e-compasses/lis3mdl.html) Pressure sensor in I2C mode
* [LSM6DSL](https://www.st.com/content/st_com/en/products/mems-and-sensors/inemo-inertial-modules/lsm6dsl.html) iNEMO 6DoF inertial measurement unit in I2C or SPI mode
* [ISM43362]() Wi-Fi module supported in SPI mode


## Install X-CUBE-COMPONENTS
1. Download [STMicroelectronics.X-CUBE-COMPONENTS.x.y.z.pack](https://github.com/SlimJallouli/X-CUBE-COMPONENTS/blob/main/Pack/STMicroelectronics.X-CUBE-COMPONENTS.1.4.1.pack)
1. Open [STM32CubeMX](www.st.com/STM32CubeMX)
1. Click **INSTALL/REMOVE**
1. Click **From Local**
1. Select the **STMicroelectronics.X-CUBE-COMPONENTS.x.y.z.pack** you just downloaded
1. Click **Open**
1. Accept the license

## Examples

This repo conatins multiple examples that shows how to use the components.

Click on the links below to get to the examples

You do not need to install **X-CUBE-COMPONENTS**  or **STM32CubeMX** to run the examples unless you want to regenerate the project using **STM32CubeMX**

* LED in GPIO mode for [B-L475E-IOT01A    ](Sources/Examples/Projects/LED/GPIO/B-L475E-IOT01A)
* LED in GPIO mode for [STM32F746ZG_NUCLEO](Sources/Examples/Projects/LED/GPIO/STM32F746ZG_NUCLEO)
* LED in PWM mode for [B-L475E-IOT01A    ](Sources/Examples/Projects/PWM/GPIO/B-L475E-IOT01A)
* LED in PWM mode for [STM32F746ZG_NUCLEO](Sources/Examples/Projects/PWM/GPIO/STM32F746ZG_NUCLEO)
* HTS221 for [B-L475E-IOT01A    ](Sources/Examples/Projects/Sensors/Environmental/HTS221)
* LIS3MDL for [B-L475E-IOT01A    ](Sources/Examples/Projects/Sensors/Motion/LIS3MDL)
* LPS22HB for [B-L475E-IOT01A    ](Sources/Examples/Projects/Sensors/Motion/LPS22HB)
* LSM6DSL for [B-L475E-IOT01A    ](Sources/Examples/Projects/Sensors/Motion/LSM6DSL) ***Still have some issues***
* WiFi_Client_Server for [B-L475E-IOT01A    ](Sources/Examples/Projects/Wi-Fi/WiFi_Client_Server)
* WiFi_HTTP_Server for [B-L475E-IOT01A    ](Sources/Examples/Projects/Wi-Fi/WiFi_Client_Server) ***Not fully tested***
* LCD for [STM32F746ZG_NUCLEO](Sources/Examples/Projects/LCD/Grove) ***Not fully tested***

## How to use
Watch this [Video](https://www.youtube.com/watch?v=eyxtEf7uuOw) to see how CMSIS pack are created and how to use them.

You do not have to create the pack your self. The ***PDSC*** file is available [here](https://github.com/SlimJallouli/X-CUBE-COMPONENTS/raw/main/Pack/STMicroelectronics.X-CUBE-COMPONENTS.1.4.1.pack)
