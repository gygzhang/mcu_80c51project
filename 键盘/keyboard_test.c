//#include"key_board.h"
//#include"key_board_cfg.h"
#include"C:\Users\CreaQi\OneDrive\文档\课程\单片机\uVision_Project\led显示字符\led_display.h"
//#include"C:\Users\CreaQi\OneDrive\文档\课程\单片机\uVision_Project\led显示字符\led_display_cfg.h"

int main(){
	char key[6];
	LED_DIG1_ON();
	while(1){
		key[0]=get_key();
		//key[0]+='0';
		switch(key[0]){
			case '0':
				P0 = ~0x3f;
			break;
			
			case '1':
				P0=~0x06;
			break;
			
			case '2':
				P0=~0x0b;
			break;
			
			case '3':
				P0=~0x4f;
			break;
			
			case '4':
				P0=~0x66;
			break;
			
			case '5':
				P0=~0x6d;
			break;
			
			case '6':
				P0=~0x7d;
			break;
			
			case '7':
				P0=~0x07;
			break;
			
			case '8':
				P0=~0x7f;
			break;
			
			case '9':
				P0=~0x6f;
			break;
			
			
				
		}
		//led_display_puts(key);
		//led_display_scan();
		//delay(60);
	}
}

