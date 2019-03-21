#include<reg51.h>

sbit BUZZER_PIN=P3^7;

#define BUZZER_ON() BUZZER_PIN=0
#define BUZZER_OFF() BUZZER_PIN=1

