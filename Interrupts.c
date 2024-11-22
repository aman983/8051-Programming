#include <reg51.h>

#include <LCD.h>
//#include <Timer_Delay.h>
//#include <Serial.h>
#include <stdio.h>

//sbit inp1 = P0^0;
//sbit inp2 = P0^1;
int count = 0;

void ext_int_0 () interrupt 0 
{ 
    count = 1;
}
 
void ext_int_1 () interrupt 2 
{ 
   count = 2;
}


void main(void){
	
	 unsigned char buffer[16];
	 P3 |= 0x0c; // Configure the INT0 & INT1 pins as Inputs
   EX0 = 1;    // Enable INT0
   EX1 = 1;    // Enable INT1
   EA  = 1;    // Enable Global Interrupt bit
	 lcd_init(1);
	while(1){
	if(count == 1){
		sprintf(buffer, "Hello %d", count);
		lcd_clear();
		lcd_set_cursor(0,0);
		lcd_show(buffer);
		count = 3;
		
	}else if(count == 2){
		sprintf(buffer, "Hello %d", count);
		lcd_clear();
		lcd_set_cursor(0,0);
		lcd_show(buffer);
		count = 3;
	}
}
	/*int i = 0;
	lcd_init(1);
	while(1){
	 unsigned char buffer[16];
		
		if(inp1 == 0)
		{
			sprintf(buffer, "Hello %d", i);
			Serial_println(buffer,1200);
  	  var_delay(100);
			i++;
		}
		if(inp2 == 0){
			
			lcd_clear();
			lcd_set_cursor(0,0);
			lcd_show(buffer);
			var_delay(100);
	}

 }*/
}