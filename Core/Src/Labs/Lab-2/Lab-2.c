

#include "Lab-2.h"

uint64_t RedTime = 0;
uint64_t YellowTime = 0;
uint64_t GreenTime = 0;
uint64_t BufferHelpTime = 0;
uint64_t BtnDelayTime = 0;
uint64_t blim = 0;

uint8_t Flag1 = 0x00;

#define TIME_MAN (TIME_NOW - BufferHelpTime)

#define WAIT_TIME(TIME) ((TIME + 50) >= TIME_MAN && TIME_MAN >= (TIME - 50))

Svitlo_Mode modeNow = OFF;

//Global
const uint16_t end_algo = 19950;



//Help Function


void clearAllAlgo(){
	modeNow = OFF;
	Flag1 = 0x00;

	BufferHelpTime = 0;
	RedTime = 0;
	YellowTime = 0;
	GreenTime = 0;
}

void Switch_State(){
	if(modeNow == OFF){
		clearAllAlgo();
		modeNow = ALGORITM_1;
	}else if(modeNow == ALGORITM_1){
		clearAllAlgo();
		modeNow = ALGORITM_2;
	}else{
		clearAllAlgo();
		modeNow = OFF;
	}
}

void Led_Controle(){
	//Red
	if(RedTime > TIME_NOW){
		RED_ON;
	}else{
		RED_OFF;
	}
	//Yellow
	if(YellowTime > TIME_NOW){
		YELLOW_ON;
	}else{
		YELLOW_OFF;
	}
	//Green
	if(GreenTime > TIME_NOW){
		GREEN_ON;
	}else{
		GREEN_OFF;
	}

	if(blim > TIME_NOW){
			GPIOC->ODR &= ~(1 << 13);
		}else{
			GPIOC->ODR |= (1 << 13);
		}
}


void SetLight(uint16_t time, LED_SELECTOR led){
	switch(led){
		case GREEN:
			GreenTime = TIME_NOW + time;
		break;
		case YELLOW:
			YellowTime = TIME_NOW + time;
		break;

		case RED:
			RedTime = TIME_NOW + time;
		break;

		case PC13:
			blim = TIME_NOW + time;
		break;

	}
}



void Algo_1(){
	if(modeNow == ALGORITM_1){
		if(!Flag1){
			BufferHelpTime = TIME_NOW;
			SetLight(9000, RED);
			Flag1 = 0xFF;
		}
		if(WAIT_TIME(6000)){
			SetLight(1000, YELLOW);
		}else if(WAIT_TIME(8000)){
			SetLight(1000, YELLOW);
		}else if(WAIT_TIME(9000)){
			SetLight(7000, GREEN);
		}else if(WAIT_TIME(16000)){
			SetLight(1000, YELLOW);
		}else if(WAIT_TIME(18000)){
			SetLight(1000, YELLOW);
		}

		if(TIME_NOW - BufferHelpTime > end_algo){
			clearAllAlgo();
		}
	}
}

void Algo_2(){
	if(modeNow == ALGORITM_2){
		if(!Flag1){
			BufferHelpTime = TIME_NOW;
			SetLight(9000, GREEN);
			Flag1 = 0xFF;
		}


		if(WAIT_TIME(6000)){
			SetLight(1000, YELLOW);
		}else if(WAIT_TIME(8000)){
			SetLight(1000, YELLOW);
		}else if(WAIT_TIME(9000)){
			SetLight(7000, GREEN);
		}else if(WAIT_TIME(16000)){
			SetLight(1000, YELLOW);
		}else if(WAIT_TIME(18000)){
			SetLight(1000, YELLOW);
		}

		if(TIME_NOW - BufferHelpTime > end_algo){
			clearAllAlgo();
		}
	}
}

void Button_Cheker(){
	if((!(GPIOB->IDR & (1 << 3)))  && (TIME_NOW - BtnDelayTime >= 500)){
		BtnDelayTime = TIME_NOW;
		SetLight(500, PC13);
		Switch_State();
	}
}

//Standart Function
void Lab_outputL2(){
	// 0, 2, 4 - Out

	RCC->APB2ENR |= (1 << 2) | (1 << 4);

	GPIOA->CRL &= ~ ( (0xF << 0) | (0xF << 8) | (0xF << 16) );

	GPIOA->CRL |= (0b0001 << 0); // PA0 -Output
	GPIOA->CRL |= (0b0001 << 8); // PA2 -Output
	GPIOA->CRL |= (0b0001 << 16);// PA4 -Output
	GPIOC->CRH |= (0b0001 << 20);

	GPIOC->ODR &= ~(1 << 13);
	GPIOA->ODR &= ~( (1 << 0) | (1 << 2) | (1 << 4));
}

void Lab_inputL2(){
	RCC->APB2ENR |= (1 << 3);
	GPIOB->CRL &= ~(0xF << 12);// PB3

	GPIOB->CRL |= (0b1000  << 12);
	GPIOB->ODR |= (1 << 3);
}


void testLed(){
	YELLOW_ON;
	GREEN_ON;
	RED_ON;
	HAL_Delay(1000);
	YELLOW_OFF;
	GREEN_OFF;
	RED_OFF;
}

void Lab_setupL2(){
	Lab_inputL2();
	Lab_outputL2();

	testLed();

}



void Lab_loopL2(){
	Led_Controle();
	Button_Cheker();

	Algo_1();
	Algo_2();

}
