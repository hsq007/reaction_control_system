#include "led.h"

void LED_init(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    GPIO_StructInit(&GPIO_InitStructure);
    RCC_APB2PeriphClockCmd(LED_CLOCK, ENABLE);	 
    GPIO_InitStructure.GPIO_Pin = LED_PIN;
    GPIO_InitStructure.GPIO_Mode = LED_MODE;
    GPIO_InitStructure.GPIO_Speed = LED_SPEED;
    GPIO_Init(LED_PORT, &GPIO_InitStructure);
    LED_write(0x00);
}

/**
 * level 输出电平
 * 
 * **/
void LED_write(uint8_t level)
{
   if(level)
   {
        GPIO_SetBits(LED_PORT,LED_PIN);
   }
   else
   {
     GPIO_ResetBits(LED_PORT,LED_PIN);
   }
}

 
