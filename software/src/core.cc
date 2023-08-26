#include "core.h"
#include "common.h"
#include <cstring>
#include <cmath>

unsigned char pixie_output_data[256][10] = {
	0x20,0x40,0x40,0x20,0x08,
	0x02,0x01,0x01,0x02,0x08,
};

unsigned char pixie_map[10][7] = {
	#include "BMP.dat"
};



void pixiw_map_pwm (void) {
	static unsigned char pixie_map_count = 0;
	for (int i = 0; i < 10; i++) {
		unsigned char dat = 0x00;
		for (int j = 0; j < 7; j++) {
			if (pixie_map_count < pixie_map[i][j]) {
				dat |= (1 << j);
			}
		}
		pixie_output_data[pixie_map_count][i] = dat;
	}
	pixie_map_count ++;
}

int t = 0;

extern unsigned char font_0507 [][5];

void writeChar(char ch1, char ch2) {
	unsigned char ch11 = ch1 - 0x20;
	unsigned char ch22 = ch2 - 0x20;
	for (int i = 0; i < 5; i++) {
		pixie_output_data[0][i] = font_0507[ch11][i];
	}
	for (int i = 0; i < 5; i++) {
		pixie_output_data[0][i+5] = font_0507[ch22][i];
	}
}

void core(void) {

	HAL_TIM_Base_Start_IT(&htim17);

	for (int i = 0; i < 256 ; i ++) {
		pixiw_map_pwm();
	}

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
int select_frame = 0;
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
	setR(pixie_output_data[select_frame][select_c]);
	// setR(pixie_output_data[(select_c+t)%10]);
	// setR();
	// setR((1 << static_cast<unsigned char>((sin(t) + 1.0) / 2.0)*7));
	select_c++;
	if (select_c > 9) {
		select_c = 0;
		pixiw_map_pwm();
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	static int frame = 0;
	if (htim == (&htim17)) {
		frame++;
		if (frame > 9) {
			select_frame ++;
			if (select_frame > 255) select_frame = 0;
		}
		selectC();
	}
}

