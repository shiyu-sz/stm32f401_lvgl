
#include <stdint.h>

void delay_us(uint32_t n)
{
	for(int i=0; i<n; i++) {
		__asm__("nop");
	}
}

void delay_ms(uint32_t n)
{
	delay_us(n*1000);
}
