#ifndef __BSP_ADVANCETIME_H
#define __BSP_ADVANCETIME_H


#include "stm32f10x.h"


/************�߼���ʱ��TIM�������壬ֻ��TIM1��TIM8************/
// ��ʹ�ò�ͬ�Ķ�ʱ����ʱ�򣬶�Ӧ��GPIO�ǲ�һ���ģ����Ҫע��
// ��������ʹ�ø߼����ƶ�ʱ��TIM1

#define            ADVANCE_TIM_APBxClock_FUN     RCC_APB2PeriphClockCmd

// PWM �źŵ�Ƶ�� F = TIM_CLK/{(ARR+1)*(PSC+1)}



/**************************��������********************************/

void ADVANCE_TIMx_Init(uint32_t X,uint32_t ARR,uint32_t PSC,uint32_t pulse);


#endif	/* __BSP_ADVANCETIME_H */


