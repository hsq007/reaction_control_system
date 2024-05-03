#include "pid.h"
#include "user_math.h"

/**
 * @brief PID算法初始化。在运行PID之前必须先用这个函数初始化，主要是配置算法参数。
 * 
 * @param[null] self 算法内部参数
 * @param[in] kp 比例参数
 * @param[in] ki 积分参数
 * @param[in] kd 微分参数
 * @param[in] u_limit 总输出限幅
 * @return ** void 
 */
void pid_init(ST_PID *self, f32 kp, f32 ki, f32 kd, f32 u_limit, f32 dead_zone)
{
    self->kp = kp;
    self->ki = ki;
    self->kd = kd;
    self->u_limit = u_limit;
    self->dead_zone = dead_zone;
}


void pid_saturate(f32 *x, f32 x_limit)
{
    if(*x > x_limit)
    {
        *x = x_limit;
    }
    if(*x < -x_limit)
    {
        *x = -x_limit;
    }
}

/**
 * @brief PID算法运算过程。根据目标值、反馈值计算控制器输出。
 * 
 * @param self 
 * @param[in] dt 控制器的运算周期 s
 * @param[in] des 目标值 
 * @param[in] fb 反馈值
 * @return ** f32 PID控制器运算结果
 */
f32 pid_step(ST_PID *self, f32 dt, f32 des, f32 fb)
{
    self->dt = dt;
    self->des = des;
    self->fb = fb;
    f32 err_tmp = self->des - self->fb;
    self->err = math_dead_zone(err_tmp, self->dead_zone); // 连续死区映射
    self->u_kp = self->kp * self->err;
    self->u_ki += self->ki * 0.5f * (self->err + self->err_pre) * self->dt;
	pid_saturate(&self->u_ki, self->u_limit); // 这里需要单独对积分项进行输出限幅，防止值过大导致归零缓慢出现问题
    self->u_kd = self->kd * (self->err - self->err_pre)/self->dt;
    f32 u_tmp = self->u_kp + self->u_ki + self->u_kd;
    pid_saturate(&u_tmp, self->u_limit);
    self->u = u_tmp;
    self->err_pre = self->err;
    // 死区内把各项输出清零，防止值不等于零导致电机一直在会乱跑
#if 0
    if((math_absf(self->err) < self->dead_zone) && (math_absf(self->des) < self->dead_zone))
    {
        self->u = 0; 
        self->u_ki = 0; 
    }
#endif
    return self->u;
}


/**
 * @brief 复位PID算法。把内部的一些变量恢复到初始状态。
 * 
 * @param self 
 * @return ** void 
 */
void pid_reset(ST_PID *self)
{
    self->des = 0;
    self->fb = 0;
    self->err = 0;
    self->err_pre = 0;
    self->u = 0;
    self->u_ki = 0;
    self->u_kp = 0;
    self->u_kd = 0;
}

