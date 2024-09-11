
#include "stm32f4xx.h"

void delay(void){

	for(uint32_t  i = 0; i< 500000; i++ );

}

int main(void){

	GPIO_Handle_t GpioLed ;

	GpioLed.pGPIOx = GPIO_D;

	GpioLed.pGPIO_PinConfig->GPIO_PinNumber = 14;

	GpioLed.pGPIO_PinConfig->GPIO_PinMode = GPIO_MODE_OUT;

	GpioLed.pGPIO_PinConfig->GPIO_PinSpeed = GPIO_HS;

	GpioLed.pGPIO_PinConfig->GPIO_PinOType = GPIO_OP_TYPE_PP;

	GpioLed.pGPIO_PinConfig->GPIO_PinPuPdControl = GPIO_NOPUPD;

	GPIO_PeriClkControl(GPIO_D, ENABLE);

	GPIO_Init(&GpioLed);

	while(1){

			GPIO_ToggleOutputPin(GpioLed.pGPIOx, GpioLed.pGPIO_PinConfig->GPIO_PinNumber);

			delay();

	}

	return 0;

}

