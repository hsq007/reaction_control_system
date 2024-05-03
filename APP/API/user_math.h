#ifndef __BBR_MATH_H__
#define __BBR_MATH_H__
#include "value_types.h"


f32 math_absf(f32 input);
f32 math_linear_interpolation(f32 *pxtable, f32 *pytable, int16_t len, f32 x);
f32 math_limit(f32 max, f32 x);
f32 math_limit_between(f32 x, f32 min, f32 max);
uint32_t math_limit_between_u32(uint32_t x, uint32_t min, uint32_t max);
f32 math_parabola_interpolation(f32 x_0, f32 y_0, f32 x_1, f32 y_1, f32 x);
f32 math_sign(f32 x);
double math_ln(double a);
f32 math_dead_zone(f32 input, f32 dead_zone);
f32 math_dead_zone_linear(f32 x, f32 d, f32 k);
#endif

