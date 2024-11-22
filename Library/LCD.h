#ifndef __LCD_H__
#define __LCD_H__

#include <reg51.h>
#include <Timer_Delay.h>

#define display_port P2      //Data pins connected to port 2 on microcontroller

sbit rs = P3^5;  //RS pin connected to pin 2 of port 3

sbit rw = P3^6;  // RW pin connected to pin 3 of port 3

sbit e =  P3^7;  //E pin connected to pin 4 of port 3

void lcd_set_cursor(int row, int column);
void lcd_cmd(unsigned char command);
void lcd_write(unsigned char write_data);
void lcd_init(int cursor_style);
void lcd_clear(void);
void lcd_show(unsigned char dat[16]);
		
void lcd_set_cursor(int row, int column){
	
	if(row == 0){
	  lcd_cmd(128+column);
	}
	else if(row == 1){
		lcd_cmd(192+column);
	}
}

void lcd_cmd(unsigned char command){

    display_port = command;

    rs= 0;

    rw=0;

    e=1;

    var_delay(1);

    e=0;

}
void lcd_init(int cursor_style){
	lcd_cmd(0x38);
	var_delay(10);
	
	if(cursor_style==0)
		{
			lcd_cmd(0x0C);
	  }
	else if(cursor_style==1)
	{	
		lcd_cmd(0x0E);
	}
	else if(cursor_style==2)
	{	
		lcd_cmd(0x0F);
	}
	
	var_delay(10);
	
	lcd_clear();
	var_delay(10);
	
	lcd_set_cursor(0,0); //default set cursor
	var_delay(10);
	
}
void lcd_clear(void){
	lcd_cmd(0x01);
	var_delay(10);
}

void lcd_write(char write_data){
	display_port = write_data; // Sending 8 bit char value

    rs= 1; 

    rw=0;

    e=1;

    var_delay(1);

    e=0;
}	
void lcd_show(unsigned char dat[16]){	
	 int i =0;  
	 lcd_clear();
		while(dat[i] != '\0'){
			lcd_write(dat[i]);
			var_delay(10);
			i++;
		}
		
	}	

#endif