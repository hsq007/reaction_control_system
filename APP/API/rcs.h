/*
 * @Author: hsq007 2267222816@qq.com
 * @Date: 2024-05-03 19:28:19
 * @LastEditors: hsq007 2267222816@qq.com
 * @LastEditTime: 2024-05-03 19:40:04
 * @FilePath: \MDK_ARMd:\1-MyDucument\04-MCU\01-项目代码\01-20240503-ReactionControlSystem\APP\API\rcs.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef __RCS_H__
#define __RCS_H__

#include "value_types.h"

void rcs_init(void);
void rcs_step(f32 dt);

#endif