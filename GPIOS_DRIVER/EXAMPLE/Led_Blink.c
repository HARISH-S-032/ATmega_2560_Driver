/*
 * Led_Blink.c
 *
 * Created: 5/27/2026 5:58:06 PM
 * Author : HARISH S
 */ 

#include "gpios.h"


int main()
{
	pin_mode(A0,output);  // configure pin A0 as output
	while(1)
	{
		digital_write(A0,high);  // set pin A0 high to turn on the LED
		delay_h(30);
		digital_write(A0,low);   // set pin A0 low to turn off the LED
		delay_h(30);
	}
}
