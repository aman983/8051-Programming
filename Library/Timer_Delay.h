#ifndef __Timer_Delay_H__
#define __Timer_Delay_H__

#include <reg51.h>
void var_delay(unsigned int time_ms);
void Delay(void);

void Delay(void){
	
  TMOD = 0x01; // Timer0 mode1
  TH0 = 0xFC; //initial value for 10ms
  TL0 = 0x66;
  TR0 = 1; // timer0 start

  while (TF0 == 0); // check overflow condition
  TR0 = 0; // Stop Timer
  TF0 = 0; // Clear flag
}
void var_delay(unsigned int time_ms){
		int i =0 ;
		while(i != time_ms){
		Delay();
			i++;
		}	
	}

#endif