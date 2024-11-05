#include "Lab-1.h"


/*!
 * ____________________________________________________________________________________________________________________
 *
 * Led - C13
 *
 * ____________________________________________________________________________________________________________________
 * */


void Lab_outputL1(){
	RCC->APB2ENR |= (1 << 4);
	GPIOC->CRH &= ~(0xF << 20);
	GPIOC->CRH |= (0b0001 << 20);
	GPIOC->ODR &= ~(1 << 13);

}


/*!
 * Btns -- PULL-UP
 * ____________________________________________________________________________________________________________________
 *
 *  Btn1 - B3
 *  Btn2 - B4
 *  Btn3 - B5
 *  Btn6 - B6
 *  Btn7 - B7
 * ____________________________________________________________________________________________________________________
 * */

void Lab_inputL1(){
	RCC->APB2ENR |= (1 << 3);

	// Btn1
	GPIOB->CRL &= ~(0xF << 12);
	GPIOB->CRL |= (0b1000 << 12);
	GPIOB->ODR |= (1 << 3);

	//Btn2
	GPIOB->CRL &= ~(0xF << 16);
	GPIOB->CRL |= (0b1000 << 16);
	GPIOB->ODR |= (1 << 4);

	//Btn3
	GPIOB->CRL &= ~(0xF << 20);
	GPIOB->CRL |= (0b1000 << 20);
	GPIOB->ODR |= (1 << 5);

	//Btn4
	GPIOB->CRL &= ~(0xF << 24);
	GPIOB->CRL |= (0b1000 << 24);
	GPIOB->ODR |= (1 << 6);

	//Btn5
	GPIOB->CRL &= ~(0xF << 28);
	GPIOB->CRL |= (0b1000 << 28);
	GPIOB->ODR |= (1 << 7);
}


void Lab_setupL1(){
	Lab_inputL1();
	Lab_outputL1();
}

void Other_Btn(){
	if(RBTN1 & RBTN2 & (!(RBTN3 | RBTN4))){
		LED_ON;
	}else if(RBTN1 & RBTN3 & (!(RBTN2 | RBTN4))){
		LED_ON;
	}else if(RBTN1 & RBTN4 & (!(RBTN2 | RBTN3))){
		LED_ON;
	}else if(RBTN2 & RBTN3 & (!(RBTN1 | RBTN4))){
		LED_ON;
	}else if(RBTN2 & RBTN4 & (!(RBTN1 | RBTN3))){
		LED_ON;
	}else if(RBTN3 & RBTN4 & (!(RBTN1 | RBTN2))){
		LED_ON;
	}else if(RBTN1 & RBTN2 & RBTN3 & (!RBTN4)){
		LED_ON;
	}else {
		LED_OFF;
	}
}

void Lab_loopL1(){

	if(!(RBTN5)){
		Other_Btn();
	}else{
		LED_OFF;
	}

}
