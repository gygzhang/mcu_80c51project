#include"timer0.h"

int t_count;

void timer0_100us_init(){
	TMOD|=0X01;
	EA=1;
	ET0=1;
	TH0=(65536-84)/256;
	TL0=(65536-84)%256;
}

void timer0_start(){
	TR0=1;
}

void delay100us(int us100_count){
	t_count=us100_count;	
	while(t_count);
}

void timer0_isr() interrupt 1 using 1{
	//一定要记得重新设置，不然计时是不对的(进入这个函数意味着TH0=TL0=0)
	TF0=0;
	TH0=(65536-84)/256;
	TL0=(65536-84)%256;
	if(t_count) t_count--; 
}

