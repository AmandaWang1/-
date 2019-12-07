#include "GY53.h"
#include "base.h"
#include "base2.h"
#include "weidai.h"
#include "systick.h"

#define  GY53_Receive    PBin(6)
#define  GY53_Receive2    PBin(7)

extern uint16_t time;
extern uint16_t time2;

/*������ģ��1 ��ʼ��*/
void GY53_Init (void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(GY53_CLK , ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = GY53_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;     //GPIO_Mode_IN_FLOATING;//��������
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GY53_PORT, &GPIO_InitStruct);
	
}

/*������ģ��2 ��ʼ��*/
void GY53_Init2 (void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(GY53_CLK2 , ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = GY53_PIN2;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;     //GPIO_Mode_IN_FLOATING;//��������
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GY53_PORT2, &GPIO_InitStruct);
	
}


/* �򿪶�ʱ�� 6*/
static void OpenTimerForGY(void)         
{  
	//����TIM�������Ĵ�����ֵ
	TIM_SetCounter(BASIC_TIM,0); //�������  
	time = 0;  
	TIM_Cmd(BASIC_TIM,ENABLE);  //ʹ��TIMX����  
}  
   
/* �򿪶�ʱ�� 7*/
static void OpenTimerForGY2(void)         
{  
	//����TIM�������Ĵ�����ֵ
	TIM_SetCounter(BASIC_TIM7,0); //�������  
	time = 0;  
	TIM_Cmd(BASIC_TIM7,ENABLE);  //ʹ��TIMX����  

}

/* �رն�ʱ��6*/
static void CloseTimerForGY(void)           
{  
	TIM_Cmd(BASIC_TIM,DISABLE); //ʹ��TIMX����  
}  

/* �رն�ʱ��7*/
static void CloseTimerForGY2(void)           
{  
	TIM_Cmd(BASIC_TIM7,DISABLE); //ʹ��TIMX����  
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

void BASIC_TIM7_IRQHandler(void)
{
	if( TIM_GetITStatus( BASIC_TIM7,TIM_IT_Update) != RESET)
	{
		time2++;
		TIM_ClearITPendingBit(BASIC_TIM7,TIM_FLAG_Update);
	}
}


//��ȡ��ʱ��6ʱ��  
uint32_t GetGYTimer(void)  
{  
	uint32_t t = 0;  
	t = time * 1000;      //��msת��Ϊus 
  t = t + TIM_GetCounter(BASIC_TIM);    //�õ���us  
	TIM6-> CNT = 0;       //��TIM6�����Ĵ����ļ���ֵ���� ����һ����������ֵ��  
	delay_ms(50);
	return t;  
}  

//��ȡ��ʱ��7ʱ��  
uint32_t GetGYTimer2(void)  
{  
	uint32_t t2 = 0;  
	t2 = time2 * 1000;      //��msת��Ϊus 
  t2 = t2 + TIM_GetCounter(BASIC_TIM7);    //�õ���us  
	TIM7-> CNT = 0;       //��TIM6�����Ĵ����ļ���ֵ���� ����һ����������ֵ��  
	delay_ms(50);
	return t2;  
}  

  
//��ʱ��6һ�λ�ȡ����������β��֮����Ҫ���һ��ʱ�䣬���ϻ����ź�  
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


//��ʱ��7һ�λ�ȡ����������β��֮����Ҫ���һ��ʱ�䣬���ϻ����ź�  
float Hcsr04GetLength2(void)  
{  
	uint32_t t2 = 0;  
	float  lengthTemp2 = 0;  
	
	delay_ms(500);

	while (GY53_Receive2 == 0);      //�ȴ����տڸߵ�ƽ���  
	OpenTimerForGY2();               //�򿪶�ʱ��  
		
	while (GY53_Receive2 == 1);    //
	CloseTimerForGY2();           //�رն�ʱ�� 
	
	t2 = GetGYTimer2();           //��ȡʱ�䣬�ֱ���Ϊ1US   
	
	lengthTemp2 = (float)t2 / 10;
		
	return lengthTemp2;
}  


