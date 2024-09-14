
#include "stm32f4xx.h"

void delay(){

	for(int i = 0; i < 500000 / 2;  i++);

}

int main(){

	GPIO_Handle_t GpioLed;

	GPIO_Handle_t GpioButton;

	GpioLed.pGPIOx = GPIO_D;

	GpioLed.pGPIO_PinConfig->GPIO_PinNumber = 14;

	GpioLed.pGPIO_PinConfig->GPIO_PinMode = GPIO_MODE_OUT;

	GpioLed.pGPIO_PinConfig->GPIO_PinSpeed = GPIO_HS;

	GpioLed.pGPIO_PinConfig->GPIO_PinOType = GPIO_OP_TYPE_PP;

	GpioLed.pGPIO_PinConfig->GPIO_PinPuPdControl = GPIO_NOPUPD;

	GPIO_PeriClkControl(GPIO_D, ENABLE);

	GPIO_Init(&GpioLed);

	// configuring user button

	GpioButton.pGPIOx = GPIO_A;

	GpioButton.pGPIO_PinConfig->GPIO_PinNumber = 0;

	GpioButton.pGPIO_PinConfig->GPIO_PinMode = GPIO_MODE_IN;

	GpioButton.pGPIO_PinConfig->GPIO_PinSpeed = GPIO_HS;

	GpioButton.pGPIO_PinConfig->GPIO_PinPuPdControl = GPIO_NOPUPD;

		GPIO_PeriClkControl(GPIO_A, ENABLE);

		GPIO_Init(&GpioButton);

		while(1){

			if(GPIO_ReadFromInputPin(GPIO_A, 0) == 1){

				delay(); // handling button debouncing

				GPIO_ToggleOutputPin(GPIO_D, 14);


			}

		}








	return 0;
}
