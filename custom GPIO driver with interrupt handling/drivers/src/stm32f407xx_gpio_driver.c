
#include "stm32f407xx_gpio_driver.h"

void GPIO_PeriClkControl(GPIO_RegDef_t *pGPIOx, uint8_t status){		// here status is ENABLE or DISABLE

	if(status == 1){

		if(pGPIOx == GPIO_A){

			GPIOA_CLK_EN;

		}

		else if(pGPIOx == GPIO_B){

			GPIOB_CLK_EN;

		}

		else if(pGPIOx == GPIO_C){

			GPIOC_CLK_EN;

		}

		else if(pGPIOx == GPIO_D){

			GPIOD_CLK_EN;

		}

		else if(pGPIOx == GPIO_E){

			GPIOE_CLK_EN;

		}

		else if(pGPIOx == GPIO_F){

			GPIOF_CLK_EN;

		}

		else if(pGPIOx == GPIO_G){

			GPIOG_CLK_EN;

		}

		else if(pGPIOx == GPIO_H){

			GPIOH_CLK_EN;

		}

		else if(pGPIOx == GPIO_I){

			GPIOI_CLK_EN;

		}

	}

	else{

		if(pGPIOx == GPIO_A){

			GPIOA_CLK_DIS;

		}

		else if(pGPIOx == GPIO_B){

			GPIOB_CLK_DIS;

		}

		else if(pGPIOx == GPIO_C){

			GPIOC_CLK_DIS;

		}

		else if(pGPIOx == GPIO_D){

			GPIOD_CLK_DIS;

		}

		else if(pGPIOx == GPIO_E){

			GPIOE_CLK_DIS;

		}

		else if(pGPIOx == GPIO_F){

			GPIOF_CLK_DIS;

		}

		else if(pGPIOx == GPIO_G){

			GPIOG_CLK_DIS;

		}

		else if(pGPIOx == GPIO_H){

			GPIOH_CLK_DIS;

		}

		else if(pGPIOx == GPIO_I){

			GPIOI_CLK_DIS;

		}

	}



}

/*GPIO configurations supported by this api are pin mode, pin speed, pull up/down, output type, alt. func. (evident in the GPIO_PinConfig_t)*/

void GPIO_Init(GPIO_Handle_t *pGPIOHandle){

	uint32_t temp = 0;		// temporarily holds reg values to be encoded

	/*configure gpio mode*/								// select  the gpio mode from the possible gpio mode macros

	/*structuring  mode config int two categories; interrupt driven and non-interrupt driven */

	if(pGPIOHandle->pGPIO_PinConfig->GPIO_PinMode <= 3){

		temp = pGPIOHandle->pGPIO_PinConfig->GPIO_PinMode << (2 * pGPIOHandle->pGPIO_PinConfig->GPIO_PinNumber); 		// logic; temp = pin_mode << (2 * pin_number) since each pin is assigned 2 reg for mode config.

		pGPIOHandle->pGPIOx->MODER &= ~(0x3<<pGPIOHandle->pGPIO_PinConfig->GPIO_PinNumber); 		// precautionary: always rest the bits befor setting them

		pGPIOHandle->pGPIOx->MODER |= temp;			// always use bitwise op for assignment not assignment operator

		temp = 0;
	}

	else{

		/* step 1: configure falling edge*/

		if(pGPIOHandle->pGPIO_PinConfig->GPIO_PinMode == GPIO_MODE_INT_F){

			/*configure FTSR*/

			EXTI->FTSR |= (1<<pGPIOHandle->pGPIO_PinConfig->GPIO_PinNumber);

			/*ensure that the RTSR is disabled*/

			EXTI->RTSR &= ~(1 << pGPIOHandle->pGPIO_PinConfig->GPIO_PinNumber);

		}

		/*configure rising edge*/

		else if(pGPIOHandle->pGPIO_PinConfig->GPIO_PinMode == GPIO_MODE_INT_R){

			/*configure RTSR*/

			EXTI->RTSR |= (1<<pGPIOHandle->pGPIO_PinConfig->GPIO_PinNumber);

			/*ensure that the FTSR is disabled*/

			EXTI->FTSR &= ~(1 << pGPIOHandle->pGPIO_PinConfig->GPIO_PinNumber);

		}

		/*configure falling and rising edge*/

		else if(pGPIOHandle->pGPIO_PinConfig->GPIO_PinMode == GPIO_MODE_INT_F_R){

			/*configure FTSR and RTSR*/

			EXTI->FTSR |= (1<<pGPIOHandle->pGPIO_PinConfig->GPIO_PinNumber);

			EXTI->RTSR |= (1 << pGPIOHandle->pGPIO_PinConfig->GPIO_PinNumber);

		}

		/*step 2: configure gpio port selection in SYSCFG_EXTI reg*/

		uint8_t temp1 = pGPIOHandle->pGPIO_PinConfig->GPIO_PinNumber / 4;

		uint8_t temp2 = pGPIOHandle->pGPIO_PinConfig->GPIO_PinNumber %4;

		uint8_t portcode = GPIO_BASEADDR_TO_CODE(pGPIOHandle->pGPIOx);				// macro to to encode the a gpio port to a number (eg: port a = 1)

		SYSCFG_CLK_EN;			// enable peripheral clk before configuring registers

		SYSCFG->EXTICR[temp1] |= portcode <<  (temp2 * 4);


		/*step 3: enable the exti interrupt delivery using interrupt mask register */

		EXTI->IMR |= (1<<pGPIOHandle->pGPIO_PinConfig->GPIO_PinNumber);


	}


	//temp = 0;				// resetting the temp varaible for future reg.  assignments

	/*configure gpio speed*/								// select the gpio speed from the list of all possible speed macros in stm32f407xx_gpio_driver.h

	temp = pGPIOHandle->pGPIO_PinConfig->GPIO_PinSpeed << (2 * pGPIOHandle->pGPIO_PinConfig->GPIO_PinNumber);

	pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3<<pGPIOHandle->pGPIO_PinConfig->GPIO_PinNumber);

	pGPIOHandle->pGPIOx->OSPEEDR |= temp;

	//temp = 0;

	/*configure gpio pu/pd*/

	temp = pGPIOHandle ->pGPIO_PinConfig->GPIO_PinPuPdControl << (2 * pGPIOHandle->pGPIO_PinConfig->GPIO_PinNumber);

	pGPIOHandle->pGPIOx->PUPDR &= ~(0x3<<pGPIOHandle->pGPIO_PinConfig->GPIO_PinNumber);

	pGPIOHandle->pGPIOx->PUPDR |= temp;

	//temp = 0;

	/*configure gpio output type*/

	temp = pGPIOHandle->pGPIO_PinConfig->GPIO_PinOType <<  pGPIOHandle->pGPIO_PinConfig->GPIO_PinNumber;

	pGPIOHandle->pGPIOx->OTYPER &= ~(0x1<<pGPIOHandle->pGPIO_PinConfig->GPIO_PinNumber);

	pGPIOHandle->pGPIOx->OTYPER |= temp;

	//temp = 0;

	/*configure gpio alt. func.*/

	if(pGPIOHandle->pGPIO_PinConfig->GPIO_PinMode == GPIO_MODE_ALT_FUNC){

		if(pGPIOHandle->pGPIO_PinConfig->GPIO_PinNumber <= 7){

			temp = pGPIOHandle->pGPIO_PinConfig->GPIO_PinAltFuncMode << (4 * pGPIOHandle->pGPIO_PinConfig->GPIO_PinNumber);

			pGPIOHandle->pGPIOx->AFRL &= ~(0xF<<pGPIOHandle->pGPIO_PinConfig->GPIO_PinNumber);

			pGPIOHandle->pGPIOx->AFRL |= temp;

		}

		else{

			temp = pGPIOHandle->pGPIO_PinConfig->GPIO_PinAltFuncMode << (4 *( (pGPIOHandle->pGPIO_PinConfig->GPIO_PinNumber)%8));

			pGPIOHandle->pGPIOx->AFRH &= ~(0xF <<pGPIOHandle->pGPIO_PinConfig->GPIO_PinNumber);

			pGPIOHandle->pGPIOx->AFRH |= temp;

		}

		//temp = 0;

	}


}

void GPIO_DeInit(GPIO_RegDef_t *pGPIOx){

	if(pGPIOx == GPIO_A ){

		GPIOA_REG_RESET();

	}

	else if(pGPIOx == GPIO_B){

		GPIOB_REG_RESET();

	}

	else if(pGPIOx == GPIO_C){

		GPIOC_REG_RESET();

	}

	else if(pGPIOx == GPIO_D){

		GPIOD_REG_RESET();

	}

	else if(pGPIOx == GPIO_E){

		GPIOE_REG_RESET();

	}

	else if(pGPIOx == GPIO_F){

		GPIOF_REG_RESET();

	}

	else if(pGPIOx == GPIO_G){

		GPIOG_REG_RESET();

	}

	else if(pGPIOx == GPIO_H){

		GPIOH_REG_RESET();

	}

	else if(pGPIOx == GPIO_I){

		GPIOI_REG_RESET();

	}


}

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber){

	uint8_t value;

	value = (uint8_t)((pGPIOx->IDR  >>  pinNumber) & 0x00000001);

	return value;

}

uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx){

	uint16_t value;

	value =(uint16_t) pGPIOx->IDR;

	return value;

}

void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber, uint8_t value){		// value could be 1 / 0 thats it

	if(value == SET){

		pGPIOx->ODR |= (1 << pinNumber);

	}

	else{

		pGPIOx->ODR &= ~(1 << pinNumber);

	}

}


void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint8_t value){

	pGPIOx->ODR = value;

}


void GPIO_ToggleOutputPin(GPIO_RegDef_t  *pGPIOx, uint8_t pinNumber){

	pGPIOx->ODR  ^= (1 << pinNumber);

}


void GPIO_IRQConfig(uint8_t IRQ_Number,  uint8_t status){

	if(status == ENABLE){

		if(IRQ_Number <= 31){

			/*configure ISER0 reg*/

			*NVIC_ISER_0 |= (1 << IRQ_Number);

		}

		else if(IRQ_Number <= 63){

			/*configure ISER1 reg*/

			*NVIC_ISER_1 |= (1 << (IRQ_Number %32));

		}

		else if(IRQ_Number <= 95){ 			// <95 is enough as all the default peripheral interrupts are numbered till 82 (ref. to RM pg: 374)

			/*configure ISER2 reg*/

			*NVIC_ISER_2 |= (1 << (IRQ_Number % 64));

		}

		else{

			if(IRQ_Number <= 31){

				/*configure ICER0 reg*/

				*NVIC_ICER_0 |= (1 << IRQ_Number);

					}

					else if(IRQ_Number <= 63){

						/*configure ISER1 reg*/

						*NVIC_ICER_1 |= (1 << (IRQ_Number % 32));

					}

					else if(IRQ_Number <= 95){

						/*configure ISER2 reg*/

						*NVIC_ICER_2 |= (1 << ( IRQ_Number % 64));

					}

		}


	}

}



/*in ARM cortex m4 there are 60 priority registers; each reg cn configure 4 irq number's priority (i.e 8 bit priority number is assigned)*/


void IRQ_PriorityConfig(uint8_t IRQ_Number, uint8_t IRQ_Priority){

	// first find out the ipr reg

	uint8_t iprx = IRQ_Number / 4;

	// irq section

	uint8_t iprx_section = IRQ_Number % 4;

	// shift amount is mcu specific no. of bits that are not implemented within a designated register section (in this case the last 4 bits of the iprx (of 8 bits) are not implemented by the mcu)

	uint8_t shift_amount =( iprx_section * 8) + (8  -  NO_PR_BITS_IMPLEMENTED);

	*(NVIC_IPR_BASEADDR + (iprx * 4)) |= (IRQ_Priority <<  shift_amount);


}

/*generally complexity interrupt handling function  */

void GPIO_IRQHandling(uint8_t pinNumber ){

	if(EXTI->PR & (1 << pinNumber)){

		// clear the pending register. in this mcu clearing bit is writing 1 to it

		EXTI->PR |= (1 << pinNumber);


	}


}

























