/****************************************Copyright (c)****************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:              led_display.c
** Latest modified Date:    2019-03-14
** Latest Version:          
** Descriptions:            数码管显示，可配置引脚
**--------------------------------------------------------------------------------------------------------
** Created by:             	张桂荧
** Created date:            2019-03-14
** Version:                 
** Descriptions:            宏定义与引脚配置，头文件相关
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/


#include "led_display.h"



//显示字库
unsigned char show_table[][2]={
	{'0',0x3f},{'1',0x06},{'2',0x5b},{'3',0x4f},{'4',0x66},{'5',0x6d},
	{'6',0x7d},{'7',0x07},{'8',0x7f},{'9',0x6f},{'A',0x77},{'B',0x7c},
	{'C',0x39},{'D',0x5e},{'E',0x79},{'F',0x71},{'H',0X76},{'L',0x38},
	{'Z',0x5b},{'Y',0X6E},{'S',0x6d},{0x00,0x00}
	};


unsigned char led_show_buf[6];


void led_close_all(){
	LED_DIG1_OFF();
	LED_DIG2_OFF();
	LED_DIG3_OFF();
	LED_DIG4_OFF();
	LED_DIG5_OFF();
	LED_DIG6_OFF();
}


/*********************************************************************************************************
** Function name:           led_display_puts
** Descriptions:            LED数码管字符输入
** input parameters:        char *str
** output parameters:     	none
** Returned value:          成功:0
														失败:-1
*********************************************************************************************************/
char led_display_puts(char* str){
	char i,j;
	
	//if(str==0) return -1;
	for(i = 0 ;i<6; i++){	
		if(*str=='.') {
			i--;
			led_show_buf[i]|=0x80;
				
		}
		else{
		for(j=0;show_table[j][0]!=0x00;j++){
			if((char)show_table[j][0]==*str){
				led_show_buf[i]=show_table[j][1];
				break;				
			}
		}	
	}
		str++;		
	}
	return 0;
}

/*********************************************************************************************************
** Function name:           led_display_scan
** Descriptions:            LED数码管扫描
** input parameters:        none
** output parameters:       none
** Returned value:          none
*********************************************************************************************************/	
void led_display_scan(){
	static unsigned char index = 0;
	
	led_close_all();
	LED_SEG_DATA(~led_show_buf[index]);	
	switch(index){
		case 0:
			LED_DIG1_ON();
		break;
		
		case 1:
			LED_DIG2_ON();
		break;
		
		case 2:
			LED_DIG3_ON();
		break;
		
		case 3:
			LED_DIG4_ON();
		break;
		
		case 4:
			LED_DIG5_ON();
		break;
		
		case 5:
			LED_DIG6_ON();
		break;
	}
	
	index++;
	index%=6;
	
}


/*********************************************************************************************************
** Function name:           delay
** Descriptions:            软件延时
** input parameters:        none
** output parameters:     	none
** Returned value:          none
*********************************************************************************************************/	
extern volatile int time_count;
void delay100ms(unsigned int num){
	time_count = num;
	if(time_count==0) P3=~P3;
	while(time_count);
}

void timer_init_with_time(int us){
	int init_val;
	TMOD|=0x01;
	EA = 1;
	init_val = 65536-us;
	TH0=init_val/256;
	TL0=init_val%256;
	ET0=1;
	TR0=1;
}

/*********************************************************************************************************
** Function name:           led_display_clear
** Descriptions:            LED数码管清0
** input parameters:        none
** output parameters:     	none
** Returned value:          成功:0
														失败：未定义
*********************************************************************************************************/	
char led_display_clear(){
	memset(led_show_buf,0,6);
	return 0;
}

/*void timer_init(){
	TOMD|=0X01;
	
}*/

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
