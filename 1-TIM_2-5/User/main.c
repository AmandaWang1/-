
// TIM��ͨ�ö�ʱ��-4·PWM���Ӧ��
#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_GeneralTim.h"  

/**
  * @brief  ������
  * @param  ��  
  * @retval ��
  */
int main(void)
{
	/* led �˿����� */ 
//	LED_GPIO_Config();
	//T = ARR * (1/CLK_cnt) = ��ARR+1��*(PSC+1) / 72M
	/* TIM2��ʼ�� */
		GENERAL_TIMX_Init(0,(20-1),(7200-1));
		/* TIM3��ʼ�� */
		GENERAL_TIMX_Init(1,(20-1),(7200-1));
		/* TIM4��ʼ�� */
		GENERAL_TIMX_Init(2,(20-1),(7200-1));
		/* TIM5��ʼ�� */
		GENERAL_TIMX_Init(3,(20-1),(7200-1));
	while(1)
	{
	}
	
}
/*********************************************END OF FILE**********************/
