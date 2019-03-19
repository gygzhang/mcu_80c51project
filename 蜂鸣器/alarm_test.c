
#include"alarm.h"
#include"alarm_cfg.h"

int main(){
	while(1){
		buzz_by_frequency(1000);
		delay100us(10*2000);
	}
	return 0;
}