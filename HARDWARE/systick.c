/*
 * @Author: hsq007 2267222816@qq.com
 * @Date: 2024-05-03 19:06:31
 * @LastEditors: hsq007 2267222816@qq.com
 * @LastEditTime: 2024-05-03 19:15:55
 * @FilePath: \MDK_ARMd:\1-MyDucument\04-MCU\01-项目代码\01-20240503-ReactionControlSystem\HARDWARE\systick.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "systick.h"
#include "stm32f10x.h"

/**
 * systick_isr_freq 滴答定时器中断频率 Hz
 * 
 * **/
void systick_init(uint16_t systick_isr_freq)
{
    SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK);
    SysTick_Config(SystemCoreClock/systick_isr_freq);
}