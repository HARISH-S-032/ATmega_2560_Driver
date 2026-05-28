/*
 * Led_Blink.c
 *
 * Created: 5/27/2026 5:58:06 PM
 * Author : HARISH S
 */ 

#include "gpios.h"


int main()
{
	pin_mode(A0,output);
	while(1)
	{
		digital_write(A0,high);
		delay_h(30);
		digital_write(A0,low);
		delay_h(30);
	}
}
