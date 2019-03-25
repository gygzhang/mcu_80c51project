//#include"key_board.h"
//#include"key_board_cfg.h"
#include"C:\Users\CreaQi\OneDrive\文档\课程\单片机\uVision_Project\led显示字符\led_display.h"
//#include"C:\Users\CreaQi\OneDrive\文档\课程\单片机\uVision_Project\led显示字符\led_display_cfg.h"
int count=0;
int main(){
	char key[5],tmp_key;
	//sbit bz = P3^5;
	//LED_DIG1_ON();
	while(1){
		key[count]=get_key();
		key_shake_eliminate();		
		if(key[count]!=-1)
		{
			//key[count]==tmp_key;
			count++;
			count%=6;
		}
		//P3=0XFF;
		led_display_puts(key);
		led_display_scan();
	}
}

