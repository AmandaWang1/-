#include "stm32f10x.h"
#include "bsp_led.h"
#include "base.h"
#include "systick.h"
#include "usart.h"
#include "GY53.h"
#include "weidai.h"
#include "TIM.h"



uint16_t time = 0;


int main (void)
{
	BASIC_TIM_Init();//������ʱ����ʼ��
	
	USART_Config();  //���ڳ�ʼ��
	
	GY53_Init();
	
	TIM_Init();							//�߼���ʱ����ʼ��
	
	delay_ms(500);  
	
	while(1)
	{
		printf("����Ϊ%3fmm\n",Hcsr04GetLength());
		delay_ms(500);
	}
	
}

