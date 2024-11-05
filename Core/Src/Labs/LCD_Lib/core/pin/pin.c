#include "pin.h"

GPIO_TypeDef * getPort(PORTS mode){
	switch(mode){
	case(PORTA):
		if(!(RCC->APB2ENR & (1 << 2))){
			ON_A;
		}
		return PTA;
		break;
	case(PORTB):
		if(!(RCC->APB2ENR & (1 << 3))){
			ON_B;
		}
		return PTB;
		break;
	case(PORTC):
		if(!(RCC->APB2ENR & (1 << 4))){
			ON_C;
		}
		return PTC;
		break;

	default:
		return PTA;
		break;
	}


}


void setupPin(Pins* self){
	if(self){
		switch(self->mode){

			case(OUTPUT):
				if(self->pin > 7){
					getPort(self->mode)->CRH &= ~(0xF << ((self->pin - 8)*4));
					getPort(self->mode)->CRH |= (0b0010 << ((self->pin - 8)*4));
				}else{
					getPort(self->mode)->CRL &= ~(0xF << (self->pin*4));
					getPort(self->mode)->CRH |= (0b0010 << (self->pin*4));
				}
				getPort(self->mode)->ODR &= ~(1 << self->pin);
				break;
			case(INPUT):
				if(self->pin > 7){
					getPort(self->mode)->CRH &= ~(0xF << ((self->pin - 8)*4));
					getPort(self->mode)->CRH |= (0b0100 << ((self->pin - 8)*4));
				}else{
					getPort(self->mode)->CRL &= ~(0xF << (self->pin*4));
					getPort(self->mode)->CRH |= (0b0100 << (self->pin*4));
				}

				break;
			case(INPUT_PULL_UP):
				if(self->pin > 7){
					getPort(self->mode)->CRH &= ~(0xF << ((self->pin - 8)*4));
					getPort(self->mode)->CRH |= (0b1000 << ((self->pin - 8)*4));
				}else{
					getPort(self->mode)->CRL &= ~(0xF << (self->pin*4));
					getPort(self->mode)->CRH &= ~(0b1000 << (self->pin*4));

				}
				getPort(self->mode)->ODR &= ~(1 << self->pin);
				break;
			case(INPUT_PULL_DOWN):
				if(self->pin > 7){
					getPort(self->mode)->CRH &= ~(0xF << ((self->pin - 8)*4));
					getPort(self->mode)->CRH &= ~(0b1000 << ((self->pin - 8)*4));
				}else{
					getPort(self->mode)->CRL &= ~(0xF << (self->pin*4));
					getPort(self->mode)->CRH &= ~(0b1000 << (self->pin*4));
				}

				getPort(self->mode)->ODR |= (1 << self->pin);

				break;

			}
	}
}
void changeMode(Pins* self, PinMode mode){
	if(self){
		self->mode = mode;
		self->setupPin(self);
	}
}
void writePin(Pins* self, uint8_t level){
	if(self && self->mode == OUTPUT){
		if(level){
			getPort(self->port) -> ODR |= (1 << self->pin);
		}else{
			getPort(self->port) -> ODR &= ~(1 << self->pin);
		}
	}
}
uint8_t readPin(Pins* self){
	if(self){
		return getPort(self->mode)->IDR & (1 << self->pin);
	}
	return 0xFF;
}


Pins* initPin(uint8_t pin, PORTS port, PinMode mode){
	Pins* element = (Pins*)malloc(sizeof(Pins));

	if(element){
		element->pin = pin;
		element->port = port;
		element->mode = mode;

		element->setupPin = setupPin;
		element->changeMode = changeMode;
		element->writePin = writePin;
		element->readPin = readPin;
	}
	return 0x00000000;
}
