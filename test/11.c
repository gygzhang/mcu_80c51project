/*******************led_display.c文件注释************************
**File name :led_display.c
**Latest modified Date:2019-03-11
**Latest Version:
**Descriptions:数码管显示字符，可配置引脚
**――――――――――――――――――――――――――――――――――――――
**Created by:LiZhini
**Created data:2019-03-11
**Version:
**Descriptions:
*************************************************************/

#include <reg51.h>

sbit P2_0=P2^0;
sbit P2_1=P2^1;
sbit P2_2=P2^2;
sbit P2_3=P2^3;
sbit P2_4=P2^4;
sbit P2_5=P2^5;


/*********************************************************************************************************
  伪函数定义
*********************************************************************************************************/
#define LED_DIG1_ON() P2_0=0
#define LED_DIG2_ON() P2_1=0
#define LED_DIG3_ON() P2_2=0
#define LED_DIG4_ON() P2_3=0
#define LED_DIG5_ON() P2_4=0
#define LED_DIG6_ON() P2_5=0

#define LED_DIG1_OFF() P2_0=1
#define LED_DIG2_OFF() P2_1=1
#define LED_DIG3_OFF() P2_2=1
#define LED_DIG4_OFF() P2_3=1
#define LED_DIG5_OFF() P2_4=1
#define LED_DIG6_OFF() P2_5=1

#define LED_SEG_DATA(data) P0=data

void led_close_all(){
	LED_DIG1_OFF();
	LED_DIG2_OFF();
	LED_DIG3_OFF();
	LED_DIG4_OFF();
	LED_DIG5_OFF();
	LED_DIG6_OFF();
}
/*****************************************************************
**Function name: delay100us
**Descriptions: 延时100us时间的函数
**input parameters: unsigned int uiDly
**output parameters: none
**Returned value:
******************************************************************/
void delay100us(unsigned int uiDly)//1+（2*46）=93，93*1.085us=100us
{
	unsigned char i;
	
	do{
		
		i = 46;
		do{
		} while(--i != 0);
	} while(--uiDly != 0);
}
/*******************************************************************
**function name:main
**Description:系统主函数
**inputparameter:none
**outputparameter:none
**return value:none
********************************************************************/
void main(void)
{
	while(1)//死循环
	{
		
		//P2=0xff;
		//P2_0=0,P2_1=1,P2_2=1,P2_3=1,P2_4=1,P2_5=1;	//用于仿真电路图
		//led_close_all();
		P2=0xfe;	//用于单片机
		P0 = 0x88;
		delay100us(22);
		
		//P2_0=1,P2_1=0,P2_2=1,P2_3=1,P2_4=1,P2_5=1;
		//led_close_all();
		P2=0xfd;
		P0 = 0x83;
		delay100us(220);
		
		//P2_0=1,P2_1=1,P2_2=0,P2_3=1,P2_4=1,P2_5=1;
		//led_close_all();
		P2=0xfb;
		P0 = 0xb0;
		delay100us(220);
		
		//P2_0=1,P2_1=1,P2_2=1,P2_3=0,P2_4=1,P2_5=1;
		//led_close_all();
		
		P2=0xf7;
		P0 = 0x99;
		delay100us(220);
		
		//P2_0=1,P2_1=1,P2_2=1,P2_3=1,P2_4=0,P2_5=1;
		//led_close_all();
		P2=0xef;
		P0 = 0x92;
		delay100us(220);
		
		//P2_0=1,P2_1=1,P2_2=1,P2_3=1,P2_4=1,P2_5=0;
		
		P2=0xdf;
		P0 = 0x82;
		delay100us(220);

		//P2_0=1,P2_1=1,P2_2=1,P2_3=1,P2_4=1,P2_5=1;
		
		//delay100us(666);
	}
}