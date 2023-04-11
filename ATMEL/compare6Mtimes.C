/// compare 1234 to 1234 by 6 million times (Spoiler: it doesnt do that)
#include <avr/io.h>
#include <util/delay.h>//it has delay function
int num = 1234;
int count = 1;
int howLong = 6000000;
int main(void)
{
	DDRB=0b00000001;
	while(1)
	{
		PORTB=0b00000001;
		_delay_ms(250); 
		PORTB=0b00000000;
		_delay_ms(250);

		while (count <= howLong){
			count = count +1;
			if (num == 1234){
			}
		}
		num = 1;
	}
}
