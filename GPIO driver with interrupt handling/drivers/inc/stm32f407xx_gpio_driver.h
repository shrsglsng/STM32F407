
/* This .h contains driver specific data */

#ifndef INC_STM32F407XX_GPIO_DRIVER_H_
#define INC_STM32F407XX_GPIO_DRIVER_H_



#include "stm32f4xx.h"

/* GPIO config structure from a user application perspective */

/* This struct can be edited as per requirement, as of now it covers most commonly used/needed GPIO configurations */

typedef struct {

	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;						// all possibles values @ GPIO_MODES macros below
	uint8_t GPIO_PinSpeed; 					// all possibles values @ GPIO_SPEED macros below
	uint8_t GPIO_PinPuPdControl;				// pull up-down control
	uint8_t GPIO_PinOType;
	uint8_t GPIO_PinAltFuncMode;				// alternate function mode is possible only when PinMode = ALTFN

}GPIO_PinConfig_t;

/*GPIO handle structure to initialize individual pin with desired configurations*/

typedef struct {

	GPIO_PinConfig_t *pGPIO_PinConfig;		// user input config. data

	GPIO_RegDef_t *pGPIOx;				//  the desired user input config data must be assigned to the respective reg. belonging to this structure. also desired gpio's base address


}GPIO_Handle_t;



/*GPIO driver API's*/

/*See api implementation for more documentation*/

/*Peripheral clk config*/

void GPIO_PeriClkControl(GPIO_RegDef_t *pGPIOx, uint8_t status);

/*Init and DeInit*/

void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/*Data read - write*/

uint8_t  GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber);
uint16_t  GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);

void  GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber, uint8_t value);
void  GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint8_t value);
void  GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNumber);

/*IRQ congi and ISR handling*/

/*these api's are processor side irq handling*/

void GPIO_IRQConfig(uint8_t IRQ_Number,  uint8_t status);

void GPIO_IRQPriorityConfig(uint8_t IRQ_Number);

void GPIO_IRQHanding(uint8_t pinNumber);

/*API implementation macros*/

/*GPIO_MODES macros*/

#define GPIO_MODE_IN 						0
#define GPIO_MODE_OUT 					1
#define GPIO_MODE_ALT_FUNC  		2
#define GPIO_MODE_ANALOG  			3

#define GPIO_MODE_INT_F 				4
#define GPIO_MODE_INT_R 				5
#define GPIO_MODE_INT_F_R 			6


/*GPIO_SPEED macros*/

#define GPIO_LS 0
#define GPIO_MS  1
#define GPIO_HS  2
#define GPIO_VHS  3


/*GPIO_PUPDR macros*/

#define GPIO_NOPUPD 							0
#define GPIO_PU 										1
#define GPIO_PD											2

/*GPIO_OT_TYPE macros*/

#define GPIO_OP_TYPE_PP					 0
#define GPIO_OP_TYPE_OD 				 1

#endif /* INC_STM32F407XX_GPIO_DRIVER_H_ */





