#include "led.h"
#include "math.h"
#include "systick.h"


 int main(void)
 {	
	led_init();
	systick_init(1000);
	while(1)
	{

	}
 }

uint16_t systime = 0x00;
uint8_t led_level = 0x00;
void SysTick_Handler(void)
{
	systime ++;
	if(systime > 1000)
	{
		systime = 0x00;
		led_level = ~led_level;
		led_write(led_level);
	}
}
