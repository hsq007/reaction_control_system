/*
 * @Author: hsq007 2267222816@qq.com
 * @Date: 2024-05-03 18:47:17
 * @LastEditors: hsq007 2267222816@qq.com
 * @LastEditTime: 2024-05-03 19:44:58
 * @FilePath: \MDK_ARMd:\1-MyDucument\04-MCU\01-项目代码\01-20240503-ReactionControlSystem\HARDWARE\led.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef __LED_H
#define __LED_H	 
#include "stm32f10x.h"
#include "value_types.h"

void led_init(void);

void led_write(uint8_t level);
		 				    
#endif
