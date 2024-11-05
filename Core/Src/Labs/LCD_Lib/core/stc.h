
#ifndef SRC_LABS_LCD_LIB_CORE_STC_H_
#define SRC_LABS_LCD_LIB_CORE_STC_H_

#define CLEAR_COM 		(1 << 0)
#define BACK_HOME_COM	(1 << 1)
#define ENTRY_MODE		(1 << 2)
#define DISPLAY			(1 << 3)
#define	CUR_DIS_SHIFT	(1 << 4)
#define	SET_FUNC		(1 << 5)

#define SET_CGRAM		(1 << 6)
#define SET_DDRAM		(1 << 7)




#define ID 		1
#define S 		0

#define D		2
#define C		1
#define B		0

#define SC		3
#define RL		2

#define DL		4
#define N		3
#define F		2

#define BF		7

typedef enum InputBit{
	Bit_4,
	Bit_8
}InputBit;

typedef enum LCD_ERR{
	OK
}LCD_ERR;


// Провсяк випадок
//uint8_t Flag_LCD = 0x00;

#endif
