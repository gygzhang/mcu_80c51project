#include<reg51.h>
extern int t_count;
extern void delay100us(int us100_count);

extern void timer0_isr() ;

extern void timer0_100us_init();

extern void timer0_start();