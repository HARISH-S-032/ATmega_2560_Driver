/*
 * counter.c
 *
 * Created: 5/27/2026 5:58:06 PM
 * Author : HARISH S
 */ 

#include "7segment.h"

int main()
{
	port_config(portf,OUTPUT);  // configure port f as output
	while(1)
	{
		for(int i=0;i<=9;i++)  
		{
			segment(portf,i);   // display the number on the 7-segment display
			delay_h(30);
		}
		
	}
}
