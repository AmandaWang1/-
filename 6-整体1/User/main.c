#include "stm32f10x.h"
#include "bsp_GeneralTim.h"  
#include "bsp_AdvanceTim.h"
#include "usart.h" //����3
#include "weidai.h"
#include "systick.h"
#include "base.h"
#include "GY53.h"

/**
  * @brief  ������
  * @param  ��  
  * @retval ��
  */
	
	uint16_t time = 0;
	uint16_t time2 = 0;
	
int main(void)
{
	/*             ��ʼ��            */
	
	/* ����3��ʼ�� */
	USART_Config();  
	
	/* ������ʱ����ʼ�� */
	BASIC_TIM_Init();
	
	/* ������ģ�� */
	GY53_Init();
	
	

	///********************************** ͨ�ö�ʱ�� *********************//
	//T = ARR * (1/CLK_cnt) = ��ARR+1��*(PSC+1) / 72M
	
	//���ڸ�Сת�ٱ��
	
	/* TIM2��ʼ�� */
		GENERAL_TIMX_Init(0,(20-1),(720-1));
		/* TIM3��ʼ�� */
		GENERAL_TIMX_Init(1,(20-1),(720-1));
		/* TIM4��ʼ�� */
		GENERAL_TIMX_Init(2,(20-1),(720-1));
		/* TIM5��ʼ�� */
		GENERAL_TIMX_Init(3,(20-1),(720-1));
	
	
//***************************** �߼���ʱ�� **********************************//
/* �߼���ʱ��1��ʼ������������Ƕ��������Ϊ20ms��
		��ô��Ӧ��ռ�ձ�Ϊ25��180�㣩,20��135�㣩,15��90�㣩,10��45�㣩,5��0�㣩  */
		ADVANCE_TIMx_Init(0,(200-1),(7200-1),0);
	
		/* �߼���ʱ��2��ʼ�� */
		ADVANCE_TIMx_Init(1,(20-1),(720-1),10);	
		

	/* ������ģ��1����ʱ��6 ������� */
	printf("%fmm",Hcsr04GetLength());
	
	/* ������ģ��2����ʱ��7 ������� */
	printf("%fmm",Hcsr04GetLength2());
	
	while(1){
	}
	
}
/*********************************************END OF FILE**********************/
