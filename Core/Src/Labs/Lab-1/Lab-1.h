#ifndef SRC_LABS_LAB_1_LAB_1_H_
#define SRC_LABS_LAB_1_LAB_1_H_

#include "stm32f103xb.h"
#include "stm32f1xx.h"
#include "stm32f1xx_hal_gpio.h"
#include "stm32f1xx_hal_rcc.h"



#define RBTN1 			(!(GPIOB->IDR & (1 << 3)))
#define RBTN2 			(!(GPIOB->IDR & (1 << 4)))
#define RBTN3 			(!(GPIOB->IDR & (1 << 5)))
#define RBTN4 			(!(GPIOB->IDR & (1 << 6)))
#define RBTN5 			(!(GPIOB->IDR & (1 << 7)))


#define LED_ON			GPIOC->ODR &= ~(1 << 13)
#define LED_OFF			GPIOC->ODR |= (1 << 13)

#define READ(PORT, BTN) (PORT->IDR & BTN)


void Lab_loopL1();

void Lab_outputL1();

void Lab_inputL1();

void Lab_setupL1();


#endif /* SRC_LABS_LAB_1_LAB_1_H_ */
