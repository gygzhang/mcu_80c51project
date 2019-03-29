#include<reg51.h>

int main(){
	P1=0X55;
	EA=1;
	EX0=1;
	IT0=0;
	while(1){
	
	}
}

void ISR_T(void) interrupt 0 using 1
{
	P1=~P1;
}