#include "led.h"
#include "math.h"
#include "systick.h"
#include "rcs_drv.h"


uint8_t rcs_drv_state[2];

int main(void)
{	
	LED_init();
	RCS_DRV_init();
	systick_init(1000);
	while(1)
	{
		RCS_DRV_set_z_negetive(rcs_drv_state[0]);
		RCS_DRV_set_z_positive(rcs_drv_state[1]);
	}
}


uint16_t rcs_state = 0x00;
void rcs_task(void)
{
	switch(rcs_state)
	{
		case 0: // OFF
		{
			break;
		}

		case 10: // 延时 5s
		{
			break;
		}

		case 20: // 正向喷气
		{
			break;
		}

		case 30: // 延时 1s
		{
			break;
		}

		case 40: // 停止喷气
		{
			break;
		}

		default:
		break;
	}
}


/**
 * LED 闪灯任务 
 * run_freq 调用频率 Hz
 * task_freq 闪灯频率 Hz
 * **/
void led_blink_task(void)
{
	static uint8_t led_level = 0x00;
	led_level = ~led_level;
	LED_write(led_level);
	rcs_drv_state[0] = led_level;
	rcs_drv_state[1] = led_level;
}

uint16_t systime = 0x00;
void SysTick_Handler(void)
{
	systime ++;
	if(systime > 3000)
	{
		systime = 0x00;
		led_blink_task();
	}
}
