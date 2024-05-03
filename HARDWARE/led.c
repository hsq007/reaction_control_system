#include "led.h"

#define LED_CLOCK   RCC_APB2Periph_GPIOA
#define LED_PORT    GPIOB
#define LED_PIN     GPIO_Pin_2
#define LED_MODE    GPIO_Mode_Out_PP
#define LED_SPEED   GPIO_Speed_50MHz

void led_init(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    GPIO_StructInit(&GPIO_InitStructure);
    RCC_APB2PeriphClockCmd(LED_CLOCK, ENABLE);	 
    GPIO_InitStructure.GPIO_Pin = LED_PIN;
    GPIO_InitStructure.GPIO_Mode = LED_MODE;
    GPIO_InitStructure.GPIO_Speed = LED_SPEED;
    GPIO_Init(LED_PORT, &GPIO_InitStructure);
    led_write(0x00);
}

/**
 * level 输出电平
 * 
 * **/
void led_write(uint8_t level)
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

 
