#pragma once

#include"C:\Users\CreaQi\OneDrive\文档\课程\单片机\uVision_Project\蜂鸣器\alarm.h"
#include"C:\Users\CreaQi\OneDrive\文档\课程\单片机\uVision_Project\led显示字符\led_display.h"
//#include"C:\Users\CreaQi\OneDrive\文档\课程\单片机\uVision_Project\led显示字符\led_display_cfg.h"
int count=0;
int main(){
	char key[5]={0};
	//led_display_puts("123");
	while(1){
		key[count]=get_key();
		key_shake_eliminate();		
		if(key[count]!=-1)
		{		
			//led_display_puts("123");
			count++;
			count%=6;
		}
		led_display_puts(key);
		led_display_scan();
	}
}

