#ifndef BSE_LCD
#define BASE_LCD

#include "stm32f103xb.h"
#include "stm32f1xx.h"
#include "stm32f1xx_hal_gpio.h"
#include "stm32f1xx_hal_rcc.h"


#include "../stc.h"
#include "../setting.h"
#include "../pin/pin.h"


typedef struct LCD{
	InputBit type;

	LCD_ERR err;

	void (*lcd_loop)(struct LCD* this);




}LCD;



#endif
