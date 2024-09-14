file setup:
- drivers/inc/stm32f4xx.h contains mcu specific registers and struct declarations.
- drivers/inc/stm32f407xx_gpio_driver.h contains gpio driver related functions declaration. Drivers full API support can be viewd here.
- drivers/src/stm32f407xx_gpio_driver.c implements all supported API's
- Src/.. contains files to test the driver

PS: I have tried to include inline comments wherever necessary to describe the design descision.
