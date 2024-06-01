#include "rcs_drv.h"

// Z正向喷嘴
#define RCS_Z_P_CLOCK   RCC_APB2Periph_GPIOB
#define RCS_Z_P_PORT    GPIOB
#define RCS_Z_P_PIN     GPIO_Pin_0
#define RCS_Z_P_MODE    GPIO_Mode_Out_PP
#define RCS_Z_P_SPEED   GPIO_Speed_50MHz
// Z正向喷嘴互补输出
#define RCS_Z_N_CLOCK   RCC_APB2Periph_GPIOB
#define RCS_Z_N_PORT    GPIOB
#define RCS_Z_N_PIN     GPIO_Pin_1
#define RCS_Z_N_MODE    GPIO_Mode_Out_PP
#define RCS_Z_N_SPEED   GPIO_Speed_50MHz


void RCS_DRV_init(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    GPIO_StructInit(&GPIO_InitStructure);

    RCC_APB2PeriphClockCmd(RCS_Z_P_CLOCK, ENABLE);	 
    GPIO_InitStructure.GPIO_Pin = RCS_Z_P_PIN;
    GPIO_InitStructure.GPIO_Mode = RCS_Z_P_MODE;
    GPIO_InitStructure.GPIO_Speed = RCS_Z_P_SPEED;
    GPIO_Init(RCS_Z_P_PORT, &GPIO_InitStructure);

     RCC_APB2PeriphClockCmd(RCS_Z_N_CLOCK, ENABLE);	 
    GPIO_InitStructure.GPIO_Pin = RCS_Z_N_PIN;
    GPIO_InitStructure.GPIO_Mode = RCS_Z_N_MODE;
    GPIO_InitStructure.GPIO_Speed = RCS_Z_N_SPEED;
    GPIO_Init(RCS_Z_N_PORT, &GPIO_InitStructure);
}


// Z轴正向喷气输出控制 0x00=关闭， 0x01=打开
void RCS_DRV_set_z_positive(uint8_t state)
{
    if(state)
    {
        GPIO_SetBits(RCS_Z_P_PORT,RCS_Z_P_PIN);
    }
    else
    {
        GPIO_ResetBits(RCS_Z_P_PORT,RCS_Z_P_PIN);
    }
}


// Z轴负向喷气输出控制 0x00=关闭， 0x01=打开
void RCS_DRV_set_z_negetive(uint8_t state)
{
    if(state)
    {
        GPIO_SetBits(RCS_Z_N_PORT,RCS_Z_N_PIN);
    }
    else
    {
        GPIO_ResetBits(RCS_Z_N_PORT,RCS_Z_N_PIN);
    }
}

