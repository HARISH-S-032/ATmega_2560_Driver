/*
 * counter.c
 *
 * Created: 5/27/2026 5:58:06 PM
 * Author : HARISH S
 */ 

#include "7segment.h"

int main()
{
	port_config(portf,OUTPUT);
	while(1)
	{
		for(int i=0;i<=9;i++)
		{
			segment(portf,i);
			delay_h(30);
		}
		
	}
}
