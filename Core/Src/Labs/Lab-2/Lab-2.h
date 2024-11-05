
#ifndef SRC_LABS_LAB_2_LAB_2_H_
#define SRC_LABS_LAB_2_LAB_2_H_

#include "stm32f103xb.h"
#include "stm32f1xx.h"
#include "stm32f1xx_hal_gpio.h"
#include "stm32f1xx_hal_rcc.h"

#define RED_LED		4
#define YELLOW_LED	2
#define GREEN_LED	0

#define LED_PORT 	GPIOA


#define GREEN_ON	(LED_PORT->ODR |= (1 << GREEN_LED))
#define GREEN_OFF	(LED_PORT->ODR &= ~(1 << GREEN_LED))

#define YELLOW_ON	(LED_PORT->ODR |= (1 << YELLOW_LED))
#define YELLOW_OFF	(LED_PORT->ODR &= ~(1 << YELLOW_LED))

#define RED_ON		(LED_PORT->ODR |= (1 << RED_LED))
#define RED_OFF		(LED_PORT->ODR &= ~(1 << RED_LED))


#define TIME_NOW	HAL_GetTick()


typedef enum Svitlo_Mode{
	OFF,
	ALGORITM_1,
	ALGORITM_2
}Svitlo_Mode;

typedef enum LED_SELECTOR{
	GREEN,
	YELLOW,
	RED,
	PC13
}LED_SELECTOR;



void Lab_loopL2();

void Lab_outputL2();

void Lab_inputL2();

void Lab_setupL2();


#endif
