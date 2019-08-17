#include "GY53.h"
#include "base.h"
#include "weidai.h"
#include "systick.h"

#define  GY53_Receive    PBin(6)

extern uint16_t time;


void GY53_Init (void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(GY53_CLK , ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = GY53_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;     //GPIO_Mode_IN_FLOATING;//��������
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GY53_PORT, &GPIO_InitStruct);
	
}


/* �򿪶�ʱ�� */
static void OpenTimerForGY(void)         
{  
	//����TIM�������Ĵ�����ֵ
	TIM_SetCounter(BASIC_TIM,0); //�������  
	time = 0;  
	TIM_Cmd(BASIC_TIM,ENABLE);  //ʹ��TIMX����  
}  
   
/* �رն�ʱ�� */
static void CloseTimerForGY(void)           
{  
	TIM_Cmd(BASIC_TIM,DISABLE); //ʹ��TIMX����  
}  


/*����Ǵ�֮ǰstmf10x_it.c���Ų������*/
void BASIC_TIM_IRQHandler(void)
{
	if( TIM_GetITStatus( BASIC_TIM,TIM_IT_Update) != RESET)
	{
		time++;
		TIM_ClearITPendingBit(BASIC_TIM,TIM_FLAG_Update);
	}
}


//��ȡ��ʱ��ʱ��  
uint32_t GetGYTimer(void)  
{  
	uint32_t t = 0;  
	t = time * 1000;      //��msת��Ϊus 
  t = t + TIM_GetCounter(BASIC_TIM);    //�õ���us  
	TIM6-> CNT = 0;       //��TIM6�����Ĵ����ļ���ֵ���� ����һ����������ֵ��  
	delay_ms(50);
	return t;  
}  

  
//һ�λ�ȡ����������β��֮����Ҫ���һ��ʱ�䣬���ϻ����ź�  
float Hcsr04GetLength(void)  
{  
	uint32_t t = 0;  
	float  lengthTemp = 0;  
	
	delay_ms(500);

	while (GY53_Receive == 0);      //�ȴ����տڸߵ�ƽ���  
	OpenTimerForGY();               //�򿪶�ʱ��  
		
	while (GY53_Receive == 1);    //
	CloseTimerForGY();           //�رն�ʱ�� 
	
	t = GetGYTimer();           //��ȡʱ�䣬�ֱ���Ϊ1US   
	
	lengthTemp = (float)t / 10;
		
	return lengthTemp;
}  



