#include"alarm.h"
#include"alarm_cfg.h"
#include<reg51.h>
void buzz(){
	unsigned char i;
	for(i=0;i<3000;i++){	
		BUZZER_PIN=0x00;
		delay100us(5);	
		BUZZER_PIN=0x01;
	}
}

void buzz_by_frequency(int freq){
	char i;
	float t = 1.0/freq;
	for(i=0;i<3000;i++){
		BUZZER_PIN=~BUZZER_PIN;
		delay100us(t*10000/2);
	}
}

void delay1ms(int t0){
	int t = t0*921;
	while(t--);
}

void delay100us(float t1){
	int t = (int)t1*93;
	while(t--);
}