
/*This .h file contains MCU specific data*/

#ifndef INC_STM32F4XX_H_
#define INC_STM32F4XX_H_


#include <stdint.h>
#include <stddef.h>

#define __vo		volatile
#define ENABLE			1
#define DISABLE			0
#define SET						ENABLE
#define RESET				DISABLE
#define HIGH					1
#define LOW					0

/*NVIC registers*/

#define NVIC_ISER_0				((__vo uint32_t *)0xE000E100 )

#define NVIC_ISER_1				((__vo uint32_t *)0xE000E104)

#define NVIC_ISER_2				((__vo uint32_t *)0xE000E108)

#define NVIC_ISER_3				((__vo uint32_t *)0xE000E10C)


#define NVIC_ICER_0				((__vo uint32_t *)0xE000E180)

#define NVIC_ICER_1				((__vo uint32_t *)0xE000E184)

#define NVIC_ICER_2				((__vo uint32_t *)0xE000E188)

#define NVIC_ICER_3				((__vo uint32_t *)0xE000E18C)


/*Interrupt priority register*/

#define NVIC_IPR_BASEADDR			((__vo uint32_t * )0xE000E400)

#define NO_PR_BITS_IMPLEMENTED			4		// this is mcu specific. this is the number of bits that are not implemented with the interrupt priority register section (in this case 4 out of 8 bits are not implemented)



/*Memory base addresses*/

#define FLASH							0x08000000U
#define SRAM1						0x20000000U																								//112kB
#define SRAM2						0x2001C000U
#define ROM								0x1FFF0000U																								//System Memory
#define SRAM							SRAM1

/*Bus base addresses*/

#define PERIPH_BASEADDR									0x40000000U
#define AHB1PERIPH_BASEADDR							0x40020000U
#define AHB2PERIPH_BASE	ADDR							0x50000000U
#define AHB3PERIPH_BASEADDR							0xA0000000U
#define APB1PERIPH_BASEADDR							0x40000000U
#define APB2PERIPH_BASEADDR							0x40010000U

/*Bus Peripheral Base Addresses*/

/*AHB1 peripherals*/

#define GPIOA_BASEADDR 			(AHB1PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR 			(AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR 			(AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR 			(AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR 			(AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOF_BASEADDR 			(AHB1PERIPH_BASEADDR + 0x1400)
#define GPIOG_BASEADDR 			(AHB1PERIPH_BASEADDR + 0x1800)
#define GPIOH_BASEADDR 			(AHB1PERIPH_BASEADDR + 0x1C00)
#define GPIOI_BASEADDR 			(AHB1PERIPH_BASEADDR + 0x2000)
#define GPIOJ_BASEADDR 			(AHB1PERIPH_BASEADDR + 0x2400)
#define GPIOK_BASEADDR 			(AHB1PERIPH_BASEADDR + 0x2800)

/*RCC basae address*/

#define RCC_BASEADDR			0x40023800U

/*APB1 peripherals*/

#define I2C1_BASEADDR			(APB1PERIPH_BASE + 0x5400)
#define I2C2_BASEADDR			(APB1PERIPH_BASE + 0x5800)
#define I2C3_BASEADDR			(APB1PERIPH_BASE + 0x5C00)

#define SPI2_BASEADDR			(APB1PERIPH_BASE + 0x3800)
#define SPI3_BASEADDR			(APB1PERIPH_BASE + 0x3C00)

#define USART2_BASEADDR	(APB1PERIPH_BASE + 0x4400)
#define USART3_BASEADDR	(APB1PERIPH_BASE + 0x4800)

#define UART4_BASEADDR		(APB1PERIPH_BASE + 0x4C00)
#define UART5_BASEADDR		(APB1PERIPH_BASE + 0x5000)

/*APB2 peripheral*/

#define SPI1_BASEADDR						(APB2PERIPH_BASEADDR + 0x3000 )

#define USART1_BASEADDR				(APB2PERIPH_BASEADDR + 0x1000 )
#define USART6_BASEADDR				(APB2PERIPH_BASEADDR + 0x1400 )

#define EXTI_BASEADDR						(APB2PERIPH_BASEADDR + 0x3C00 )

#define SYSCFG_BASEADDR				(APB2PERIPH_BASEADDR + 0x3800 )

/*Struct of common registers across peripheral instances*/

/*Usecase: access this structure as base address of a gpio port during initialization*/

typedef struct{

	__vo uint32_t MODER;
	__vo uint32_t OTYPER;
	__vo uint32_t OSPEEDR;
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFRL;
	__vo uint32_t AFRH;

} GPIO_RegDef_t;

typedef struct{

	__vo uint32_t CR;
	__vo uint32_t PLLCFGR;
	__vo uint32_t CFGR;
	__vo uint32_t CIR;
	__vo uint32_t AHB1RSTR;
	__vo uint32_t AHB2RSTR;
	__vo uint32_t AHB3RSTR;

	__vo uint32_t RESERVED0;							// remember to add reserved macros 'in-order'

	__vo uint32_t APB1RSTR;
	__vo uint32_t APB2RSTR;

	__vo uint32_t RESERVED1;
	__vo uint32_t RESERVED2;

	__vo uint32_t AHB1ENR;
	__vo uint32_t AHB2ENR;
	__vo uint32_t AHB3ENR;

	__vo uint32_t RESERVED3;

	__vo uint32_t APB1ENR;
	__vo uint32_t APB2ENR;

	__vo uint32_t RESERVED4;
	__vo uint32_t RESERVED5;

	__vo uint32_t AHB1LPENR;
	__vo uint32_t AHB2LPENR;
	__vo uint32_t AHB3LPENR;

	__vo uint32_t RESERVED6;

	__vo uint32_t APB1LPENR;
	__vo uint32_t APB2LPENR;

	__vo uint32_t RESERVED7;
	__vo uint32_t RESERVED8;

	__vo uint32_t BDCR;
	__vo uint32_t CSR;

	__vo uint32_t RESERVED9;
	__vo uint32_t RESERVED10;

	__vo uint32_t SSCGR;
	__vo uint32_t PLLI2SCFGR;

}RCC_RegDef_t;

/* intialize struct ptr for EACH instance of the peripheral for easy acces of members*/

#define GPIO_A  		((GPIO_RegDef_t *)GPIOA_BASEADDR)
#define GPIO_B 		((GPIO_RegDef_t *)GPIOB_BASEADDR)
#define GPIO_C 		((GPIO_RegDef_t *)GPIOC_BASEADDR)
#define GPIO_D 		((GPIO_RegDef_t *)GPIOD_BASEADDR)
#define GPIO_E 		((GPIO_RegDef_t *)GPIOE_BASEADDR)
#define GPIO_F  		((GPIO_RegDef_t *)GPIOF_BASEADDR)
#define GPIO_G 		((GPIO_RegDef_t *)GPIOG_BASEADDR)
#define GPIO_H 		((GPIO_RegDef_t *)GPIOH_BASEADDR)
#define GPIO_I 			((GPIO_RegDef_t *)GPIOI_BASEADDR)

#define RCC 				( (RCC_RegDef_t *)RCC_BASEADDR)

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*Peripheral clock enable macros*/

	/*GPIOx clock enable*/

	#define GPIOA_CLK_EN				(RCC->AHB1ENR |= (1<<0))
	#define GPIOB_CLK_EN				(RCC->AHB1ENR |= (1<<1))
	#define GPIOC_CLK_EN				(RCC->AHB1ENR |= (1<<2))
	#define GPIOD_CLK_EN				(RCC->AHB1ENR |= (1<<3))
	#define GPIOE_CLK_EN					(RCC->AHB1ENR |= (1<<4))
	#define GPIOF_CLK_EN					(RCC->AHB1ENR |= (1<<5))
	#define GPIOG_CLK_EN				(RCC->AHB1ENR |= (1<<6))
	#define GPIOH_CLK_EN				(RCC->AHB1ENR |= (1<<7))
	#define GPIOI_CLK_EN					(RCC->AHB1ENR |= (1<<8))

	/*I2Cx clock enable*/

	#define I2C1_CLK_EN					(RCC->APB1ENR |= (1 << 21))
	#define I2C2_CLK_EN					(RCC->APB1ENR |= (1 << 22))
	#define I2C3_CLK_EN					(RCC->APB1ENR |= (1 << 23))

	/*SPIx clock enable*/

	#define SPI1_CLK_EN					RCC->APB2ENR |= (1 << 12)

	#define SPI2_CLK_EN					RCC->APB1ENR |= (1 << 14)
	#define SPI3_CLK_EN					RCC->APB1ENR |= (1 << 15)

	#define SPI4_CLK_EN					RCC->APB2ENR |= (1 << 13)

	#define SPI5_CLK_EN					RCC->APB2ENR |= (1 << 20)
	#define SPI6_CLK_EN					RCC->APB2ENR |= (1 << 21)


	/*USARTx clock enable*/

	#define USART1_CLK_EN				RCC->APB2ENR |= (1 << 20)
	#define USART2_CLK_EN				RCC->APB1ENR |= (1 << 17)
	#define USART3_CLK_EN				RCC->APB1ENR |= (1 << 18)

	#define UART4_CLK_EN				RCC->APB1ENR |= (1 << 19)
	#define UART5_CLK_EN				RCC->APB1ENR |= (1 << 20)

	#define USART6_CLK_EN				RCC->APB2ENR |= (1 << 21)

	#define UART7_CLK_EN				RCC-> APB1ENR |= (1<< 30)
	#define UART8_CLK_EN				RCC-> APB1ENR |= (1<< 31)

	/*SYSCFG clock enable*/

	#define SYSCFG_CLK_EN 				RCC->APB2ENR |= (1<<14)


	/*GPIOx clock disble*/

	#define GPIOA_CLK_DIS				(RCC->AHB1ENR &= ~(1<<0))
	#define GPIOB_CLK_DIS				(RCC->AHB1ENR &= ~(1<<1))
	#define GPIOC_CLK_DIS				(RCC->AHB1ENR &= ~(1<<2))
	#define GPIOD_CLK_DIS				(RCC->AHB1ENR &= ~(1<<3))
	#define GPIOE_CLK_DIS				(RCC->AHB1ENR &= ~(1<<4))
	#define GPIOF_CLK_DIS				(RCC->AHB1ENR &= ~(1<<5))
	#define GPIOG_CLK_DIS				(RCC->AHB1ENR &= ~(1<<6))
	#define GPIOH_CLK_DIS				(RCC->AHB1ENR &= ~(1<<7))
	#define GPIOI_CLK_DIS					(RCC->AHB1ENR &= ~(1<<8))


	/*I2Cx clock disable*/

	#define I2C1_CLK_DIS					(RCC->APB1ENR &= ~(1 << 21))
	#define I2C2_CLK_DIS					(RCC->APB1ENR &= ~(1 << 22))
	#define I2C3_CLK_DIS					(RCC->APB1ENR &= (~1 << 23))

	/*SPIx clock disable*/

	#define SPI1_CLK_DIS					RCC->APB2ENR &= ~(1 << 12)

	#define SPI2_CLK_DIS					RCC->APB1ENR &= ~(1 << 14)
	#define SPI3_CLK_DIS					RCC->APB1ENR &= ~(1 << 15)

	#define SPI4_CLK_DIS					RCC->APB2ENR &= ~(1 << 13)

	#define SPI5_CLK_DIS					RCC->APB2ENR &= ~(1 << 20)
	#define SPI6_CLK_DIS					RCC->APB2ENR &= ~(1 << 21)

	/*USARTx clock disable*/

	#define USART1_CLK_DIS				RCC->APB2ENR &= ~(1 << 20)
	#define USART2_CLK_DIS			RCC->APB1ENR &= ~(1 << 17)
	#define USART3_CLK_DIS			RCC->APB1ENR &= ~(1 << 18)

	#define UART4_CLK_DIS				RCC->APB1ENR &= ~(1 << 19)
	#define UART5_CLK_DIS				RCC->APB1ENR &= ~(1 << 20)

	#define USART6_CLK_DIS				RCC->APB2ENR &= ~(1 << 21)

	#define UART7_CLK_DIS				RCC-> APB1ENR &= ~(1<< 30)
	#define UART8_CLK_DIS				RCC-> APB1ENR &= ~(1<< 31)

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

#define GPIOA_REG_RESET()			do{ (RCC->AHB1RSTR |= (0x1 << 0)); (RCC->AHB1RSTR &= ~ (0x1 << 0)) ; } while(0)

#define GPIOB_REG_RESET()			do{(RCC->AHB1RSTR |= (0x1 << 1)); (RCC->AHB1RSTR &= ~ (0x1 << 1)) ; } while(0)

#define GPIOC_REG_RESET()			do{(RCC->AHB1RSTR |= (0x1 << 2)); (RCC->AHB1RSTR &= ~ (0x1 << 2)) ; } while(0)

#define GPIOD_REG_RESET()			do{(RCC->AHB1RSTR |= (0x1 << 3)); (RCC->AHB1RSTR &= ~ (0x1 << 3)) ; } while(0)

#define GPIOE_REG_RESET()			do{(RCC->AHB1RSTR |= (0x1 << 4)); (RCC->AHB1RSTR &= ~ (0x1 << 4)) ; } while(0)

#define GPIOF_REG_RESET()			do{(RCC->AHB1RSTR |= (0x1 << 5)); (RCC->AHB1RSTR &= ~ (0x1 << 5)) ; } while(0)

#define GPIOG_REG_RESET()			do{(RCC->AHB1RSTR |= (0x1 << 6)); (RCC->AHB1RSTR &= ~ (0x1 << 6)) ; } while(0)

#define GPIOH_REG_RESET()			do{(RCC->AHB1RSTR |= (0x1 << 7)); (RCC->AHB1RSTR &= ~ (0x1 << 7)) ; } while(0)

#define GPIOI_REG_RESET()		do{(RCC->AHB1RSTR |= (0x1 << 8)); (RCC->AHB1RSTR &= ~ (0x1 << 8)) ; } while(0)

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

#define GPIO_BASEADDR_TO_CODE(x)				((x == GPIO_A) ? 0 :\
																										(x == GPIO_B) ? 1 :\
																											(x == GPIO_C) ? 2 :\
																													(x == GPIO_D) ? 3 :\
																															(x == GPIO_E) ? 4 :\
																																	(x == GPIO_F) ? 5 :\
																																			(x == GPIO_G) ? 6 :\
																																					(x == GPIO_H) ? 7 :\
																																							(x == GPIO_I) ? 8 : 0 )


/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*IRQ numbers for respective external interrupts (that are corresponding to individual pin number)*/

#define EXTI0_IRQ_NUM					6
#define EXTI1_IRQ_NUM					7
#define EXTI2_IRQ_NUM					8
#define EXTI3_IRQ_NUM					9
#define EXTI4_IRQ_NUM					10
#define EXTI9_5_IRQ_NUM				23
#define EXTI15_10_IRQ_NUM			40



/*EXTI*/


typedef struct{

	__vo uint32_t IMR;
	__vo uint32_t EMR;
	__vo uint32_t RTSR;
	__vo uint32_t FTSR;
	__vo uint32_t SWIER;
	__vo uint32_t PR;

}EXTI_RegDef_t;

#define EXTI 			( (EXTI_RegDef_t *)EXTI_BASEADDR)



/*SYSCFG */

typedef struct{

 __vo uint32_t MEMRMP;

 __vo uint32_t PMC;

 __vo uint32_t EXTICR[4];			// EXTICR1,2,3,4

 uint32_t RESERVED[2];					// reserved 0x18-0x1C

 __vo uint32_t CMPCR;

 uint32_t RESERVED2[2];

 __vo uint32_t CFGR;

}SYSCFG_RegDef_t;

#define SYSCFG 				((SYSCFG_RegDef_t *)SYSCFG_BASEADDR)

#include "stm32f407xx_gpio_driver.h"

#endif /* INC_STM32F4XX_H_ */












