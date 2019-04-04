#include"key_board.h"
#include"C:\Users\CreaQi\OneDrive\文档\课程\单片机\uVision_Project\led显示字符\led_display.h"

char get_key(){
	char row,col,ret=-1;
	//使用P0-KEY_PIN输出0
	KEY_PIN=0xf0;
	if(KEY_PIN!=0xf0){
	//消除抖动
	key_shake_eliminate();
	//确实有键按下了
	if(KEY_PIN!=0xF0){
		//行用做输入，列作为输出
		KEY_PIN=0xf0;
		if(L1==0) col = 1;
		else if(L2==0) col = 2;
		else if(L3==0) col = 3;
		//列作为输入，行输出
		KEY_PIN = 0x0f;
		if(R1==0) row =0;
		else if(R2==0) row =1;
		else if(R3==0) row =2;
		else if(R4==0) row = 3;	
		
		ret = row*3+col;
		if(ret==11) return '0';
		else if(ret==10) return -2;
		else if(ret==12) return -3;
		else //if(ret>0&&ret<11)
		return ret+'0';
		//根据ret得到数字对应的字符串
		/*switch(ret){			
			case 1:
				return '1';
			break;
			
			case 2:
				return '2';
			break;
			
			case 3:
				return '3';
			break;
			
			case 4:
				return '4';
			break;
			
			case 5:
				return '5';
			break;
			
			case 6:
				return '6';
			break;
			
			case 7:
				return '7';
			break;
			
			case 8:
				return '8';
			break;
			
			case 9:
				return '9';
			break;

			case 10:
				return -2;
			break;
			
			case 11:
				return '0';
			break;
			
			case 12:
				return -3;
			break;
			deflaut:
			return -1;
		}
	}*/
}
	//return -1;
	
	
}
	return -1;
}

void key_shake_eliminate(){
	int tmp = 930*3;
	while(tmp--){
		//if(tmp%2==)
		led_display_scan();
	}
}

/*void delay(int t){
	while(--t);
}*/