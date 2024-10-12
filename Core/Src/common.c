
#include <stdint.h>

void delay_us(uint32_t n)
{
	for(int i=0; i<n*10; i++) {
		__nop(); __nop(); __nop(); __nop();
	}
}

void delay_ms(uint32_t n)
{
	delay_us(n*1000);
}
