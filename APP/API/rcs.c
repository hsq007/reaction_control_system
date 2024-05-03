/*
 * @Author: hsq007 2267222816@qq.com
 * @Date: 2024-05-03 19:28:19
 * @LastEditors: hsq007 2267222816@qq.com
 * @LastEditTime: 2024-05-03 19:46:04
 * @FilePath: \MDK_ARMd:\1-MyDucument\04-MCU\01-项目代码\01-20240503-ReactionControlSystem\APP\API\rcs.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include "rcs.h"

typedef enum{
    RCS_STATE_OFF = 0X00, // 关机
    RCS_STATE_POSITIVE = 0X01, // 正向喷气
    RCS_STATE_NEGATIVE = 0X02, // 负向喷气
}RCS_state_t, *RCS_state_h;


typedef struct{
    f32 dt; // 控制周期 s
    f32 delay; // 延时时间 s
    RCS_state_t state; // RCS状态
}RCS_t, *RCS_h;


RCS_t g_rcs;

void rcs_set_state(RCS_state_t state)
{
    RCS_h h = &g_rcs;
    h->state = state;
}


void rcs_init(void)
{
    RCS_h h = &g_rcs;
    h->delay = 0.0f;
}


void rcs_step(f32 dt)
{
    RCS_h h = &g_rcs;
    h->dt = dt;

    switch(h->state)
    {
        case RCS_STATE_OFF:
        {
            break;
            
        }

        case RCS_STATE_POSITIVE:
        {
            break;
        }

        case RCS_STATE_NEGATIVE:
        {
            break;
        }

        default:
        break;
    }

}








