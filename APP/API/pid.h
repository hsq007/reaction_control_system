#ifndef __PID_H__
#define __PID_H__
#include "value_types.h"
typedef struct
{
    f32 dt;  // 采样周期 s
    f32 des; // pid 目标值
    f32 fb; // pid 反馈值
    f32 err; // 误差
    f32 err_pre; // 上次误差
    f32 kp; // 比例参数
    f32 ki; // 积分参数
    f32 kd; // 微分参数
    f32 u; // pid 总输出
    f32 u_ki; // 积分项输出
    f32 u_kp; // 比例项输出
    f32 u_kd; // 微分项输出
    f32 u_limit; // 总输出限幅
    f32 dead_zone; // 死区 
}ST_PID;


void pid_init(ST_PID *self, f32 kp, f32 ki, f32 kd, f32 u_limit, f32 dead_zone);
void pid_reset(ST_PID *self);
f32 pid_step(ST_PID *self, f32 dt, f32 des, f32 fb);


#endif



