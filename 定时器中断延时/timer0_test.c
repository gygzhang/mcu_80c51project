#include"timer0.h"



int main(){
	//µ÷ÓÃÊ¾Àı
	timer0_100us_init();
	timer0_start();
	while(1){
		delay100us(100);
		P1=~P1;
	}
}