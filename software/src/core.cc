#include "core.h"
#include "common.h"
#include <cstring>
#include <cmath>

unsigned char dat[] = {
	0x20,0x40,0x40,0x20,0x08,
	0x02,0x01,0x01,0x02,0x08,
};

unsigned char pixie_map[7][10] = {
	#include "BMP.dat"
};

unsigned char pixie_map_count[10][7] = { 0 };

int t = 0;

extern unsigned char font_0507 [][5];

void writeChar(char ch1, char ch2) {
	unsigned char ch11 = ch1 - 0x20;
	unsigned char ch22 = ch2 - 0x20;
	for (int i = 0; i < 5; i++) {
		dat[i] = font_0507[ch11][i];
	}
	for (int i = 0; i < 5; i++) {
		dat[i+5] = font_0507[ch22][i];
	}
}

void core(void) {

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
		// case 0: set(LTP1C1); clr(LTP2C5); break;
		// case 1: clr(LTP1C1);set(LTP1C2);clr(LTP1C3);clr(LTP1C4);clr(LTP1C5);clr(LTP1P); break;
		// case 2: clr(LTP1C1);clr(LTP1C2);set(LTP1C3);clr(LTP1C4);clr(LTP1C5);clr(LTP1P); break;
		// case 3: clr(LTP1C1);clr(LTP1C2);clr(LTP1C3);set(LTP1C4);clr(LTP1C5);clr(LTP1P); break;
		// case 4: clr(LTP1C1);clr(LTP1C2);clr(LTP1C3);clr(LTP1C4);set(LTP1C5);clr(LTP1P); break;
		// case 5: set(LTP2C1);clr(LTP2C2);clr(LTP2C3);clr(LTP2C4);clr(LTP2C5);clr(LTP2P);
		// 		clr(LTP1C5); break;
		// case 6: clr(LTP2C1);set(LTP2C2);clr(LTP2C3);clr(LTP2C4);clr(LTP2C5);clr(LTP2P); break;
		// case 7: clr(LTP2C1);clr(LTP2C2);set(LTP2C3);clr(LTP2C4);clr(LTP2C5);clr(LTP2P); break;
		// case 8: clr(LTP2C1);clr(LTP2C2);clr(LTP2C3);set(LTP2C4);clr(LTP2C5);clr(LTP2P); break;
		// case 9: clr(LTP2C1);clr(LTP2C2);clr(LTP2C3);clr(LTP2C4);set(LTP2C5);clr(LTP2P); break;
		// case 5: clr(LTP1C1);clr(LTP1C2);clr(LTP1C3);clr(LTP1C4);clr(LTP1C5);set(LTP1P); break;
	}
	// setR(dat[select_c]);
	// setR(dat[(select_c+t)%10]);
	setR()
	// setR((1 << static_cast<unsigned char>((sin(t) + 1.0) / 2.0)*7));
	select_c++;
	if (select_c > 9) {
		select_c = 0;
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim == (&htim17)) {
		selectC();
	}
}

