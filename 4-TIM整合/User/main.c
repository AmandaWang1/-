
// TIM��ͨ�ö�ʱ��-4·PWM���Ӧ��
#include "stm32f10x.h"
#include "bsp_led.h"
#include "TIM.h"  

/**
  * @brief  ������
  * @param  ��  
  * @retval ��
  */
int main(void)
{
	/* TIM2��ʼ�� */
	GENERAL_TIMX_Init(0,(20-1),(7200-1));
	/* TIM3��ʼ�� */
	GENERAL_TIMX_Init(1,(20-1),(7200-1));
	/* TIM4��ʼ�� */
	GENERAL_TIMX_Init(2,(20-1),(7200-1));
	/* TIM5��ʼ�� */
	GENERAL_TIMX_Init(3,(20-1),(7200-1));
	
	
	/* TIM1��ʼ������������Ƕ��������Ϊ20ms��
		��ô��Ӧ��ռ�ձ�Ϊ25��180�㣩,20��135�㣩,15��90�㣩,10��45�㣩,5��0�㣩  */
	ADVANCE_TIMx_Init(0,(200-1),(7200-1),0);
	/* TIM8��ʼ�� */
	ADVANCE_TIMx_Init(1,(20-1),(7200-1),0);
	
	while(1);
	
}
/*********************************************END OF FILE**********************/
