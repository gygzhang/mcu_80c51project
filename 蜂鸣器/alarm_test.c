
#include"alarm.h"
#include"alarm_cfg.h"
#include"C:\Users\CreaQi\OneDrive\�ĵ�\�γ�\��Ƭ��\uVision_Project\������\key_board.h"
int main(){
	char k;
	while(1){
		BUZZER_OFF();
		k = get_key();
		key_shake_eliminate();
		if(k!=-1) {
		buzz_by_frequency(50*(k-'0'+10)*(k-'0'+10));
		}
		k=-1;
		BUZZER_OFF();
	}
	return 0;
}