#ifndef SRC_LABS_LCD_LIB_CORE_PIN_PIN_H_
#define SRC_LABS_LCD_LIB_CORE_PIN_PIN_H_

#include <stdlib.h>
#include "stm32f103xb.h"
#include "stm32f1xx.h"
#include "stm32f1xx_hal_gpio.h"
#include "stm32f1xx_hal_rcc.h"

#define ON_A 	RCC->APB2ENR |= (1 << 2)
#define ON_B 	RCC->APB2ENR |= (1 << 3)
#define ON_C 	RCC->APB2ENR |= (1 << 4)

#define PTA		GPIOA
#define PTB		GPIOB
#define PTC		GPIOC


typedef enum PORTS{
	PORTA,
	PORTB,
	PORTC
}PORTS;

typedef enum PinMode{
	OUTPUT,
	INPUT,
	INPUT_PULL_UP,
	INPUT_PULL_DOWN
}PinMode;

typedef struct Pins{
	PORTS port;
	PinMode mode;
	uint8_t pin;


	void 	(*setupPin)		(struct Pins* self);
	void 	(*changeMode)	(struct Pins* self, PinMode mode);
	void 	(*writePin)		(struct Pins* self, uint8_t level);
	uint8_t (*readPin)		(struct Pins* self);
}Pins;


void setupPin(Pins* selfsss);
void changeMode(Pins* self, PinMode mode);
void writePin(Pins* self, uint8_t level);
uint8_t readPin(Pins* self);
GPIO_TypeDef * getPort(PORTS mode);


Pins* initPin(uint8_t pin, PORTS port, PinMode mode);

#endif
