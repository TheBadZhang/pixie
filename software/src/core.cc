#include "core.h"
#include "common.h"
#include <cstring>
#include <cmath>

unsigned char pixie_output_data[10] = {
	0x20,0x40,0x40,0x20,0x08,
	0x02,0x01,0x01,0x02,0x08,
};

unsigned char pixie_map[10][7] = {
	#include "BMP.dat"
};

int t = 0;

extern unsigned char font_0507 [][5];
extern unsigned int font_0507_size;


void core(void) {

	// HAL_TIM_Base_Start_IT(&htim16);
	HAL_TIM_Base_Start_IT(&htim17);

	while (true) {
		t ++;
		// if (t > 30) {
		// 	writeChar('A', '1');
		// 	HAL_Delay(1000);
		// }
		HAL_Delay(70);
	}

}

void setR(unsigned char dat) {
	if (dat & 0x01) clr(R1); else set(R1);
	if (dat & 0x02) clr(R2); else set(R2);
	if (dat & 0x04) clr(R3); else set(R3);
	if (dat & 0x08) clr(R4); else set(R4);
	if (dat & 0x10) clr(R5); else set(R5);
	if (dat & 0x20) clr(R6); else set(R6);
	if (dat & 0x40) clr(R7); else set(R7);
	// if (dat & 0x80) set(LTP)
}

int sel = 0, sel2 = 0;
void selectC(void) {
	static int select_c = 0;
	setR(0x00);
	switch (select_c) {
		case 0: set(LTP1C1); clr(LTP2C5); break;
		case 1: set(LTP1C2); clr(LTP1C1); break;
		case 2: set(LTP1C3); clr(LTP1C2); break;
		case 3: set(LTP1C4); clr(LTP1C3); break;
		case 4: set(LTP1C5); clr(LTP1C4); break;
		case 5: set(LTP2C1); clr(LTP1C5); break;
		case 6: set(LTP2C2); clr(LTP2C1); break;
		case 7: set(LTP2C3); clr(LTP2C2); break;
		case 8: set(LTP2C4); clr(LTP2C3); break;
		case 9: set(LTP2C5); clr(LTP2C4); break;
	}
	setR(*(font_0507[0]+select_c+sel));
	select_c++;
	if (select_c > 9) {
		select_c = 0;
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	static bool flag = false;
	if (htim == (&htim17)) {
		selectC();
	}
}

