#ifndef __RCS_DRV_H__
#define __RCS_DRV_H__

#include "stm32f10x.h"
#include "value_types.h"


void RCS_DRV_init(void);
// Z轴正向喷气输出控制 0x00=关闭， 0x01=打开
void RCS_DRV_set_z_positive(uint8_t state);
// Z轴负向喷气输出控制 0x00=关闭， 0x01=打开
void RCS_DRV_set_z_negetive(uint8_t state);

#endif



