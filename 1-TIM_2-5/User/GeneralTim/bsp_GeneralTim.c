#include "bsp_GeneralTim.h" 

struct GeneralTimerx
{
	TIM_TypeDef *  GENERAL_TIMx;
	uint32_t       GENERAL_TIMx_CLK; 
	
	// TIMx ����Ƚ�ͨ��1
	uint32_t       GENERAL_TIMx_CH1_GPIO_CLK;
	GPIO_TypeDef * GENERAL_TIMx_CH1_PORT;
	uint16_t       GENERAL_TIMx_CH1_PIN;
	
	// TIMx ����Ƚ�ͨ��2
	uint32_t       GENERAL_TIMx_CH2_GPIO_CLK;
	GPIO_TypeDef * GENERAL_TIMx_CH2_PORT;
	uint16_t       GENERAL_TIMx_CH2_PIN;	
	
	// TIMx ����Ƚ�ͨ��3
	uint32_t       GENERAL_TIMx_CH3_GPIO_CLK;
	GPIO_TypeDef * GENERAL_TIMx_CH3_PORT;
	uint16_t       GENERAL_TIMx_CH3_PIN;	
	
	// TIMx ����Ƚ�ͨ��4
	uint32_t       GENERAL_TIMx_CH4_GPIO_CLK;
	GPIO_TypeDef * GENERAL_TIMx_CH4_PORT;
	uint16_t       GENERAL_TIMx_CH4_PIN;	
	
}TimX[] = {
	{TIM2,RCC_APB1Periph_TIM2,RCC_APB2Periph_GPIOA,GPIOA,GPIO_Pin_15,\
														RCC_APB2Periph_GPIOB,GPIOB,GPIO_Pin_3,\
														RCC_APB2Periph_GPIOB,GPIOB,GPIO_Pin_10,\
														RCC_APB2Periph_GPIOB,GPIOB,GPIO_Pin_11},
	
	{TIM3,RCC_APB1Periph_TIM3,RCC_APB2Periph_GPIOA,GPIOA,GPIO_Pin_6,\
														RCC_APB2Periph_GPIOA,GPIOA,GPIO_Pin_7,\
														RCC_APB2Periph_GPIOB,GPIOB,GPIO_Pin_0,\
														RCC_APB2Periph_GPIOB,GPIOB,GPIO_Pin_1},
	
	{TIM4,RCC_APB1Periph_TIM4,RCC_APB2Periph_GPIOB,GPIOB,GPIO_Pin_6,\
														RCC_APB2Periph_GPIOB,GPIOB,GPIO_Pin_7,\
														RCC_APB2Periph_GPIOB,GPIOB,GPIO_Pin_8,\
														RCC_APB2Periph_GPIOB,GPIOB,GPIO_Pin_9},
	
	{TIM5,RCC_APB1Periph_TIM5,RCC_APB2Periph_GPIOA,GPIOA,GPIO_Pin_0,\
														RCC_APB2Periph_GPIOA,GPIOA,GPIO_Pin_1,\
														RCC_APB2Periph_GPIOA,GPIOA,GPIO_Pin_2,\
														RCC_APB2Periph_GPIOA,GPIOA,GPIO_Pin_3}
};


static void GENERAL_TIM_GPIO_Config(uint32_t i) 
{
  GPIO_InitTypeDef GPIO_InitStructure;
	
	if(i == 0)
	{
		/*** ���ο���AFIO/GPIOA/TIM2ʱ�� ***/
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_AFIO | TimX[i].GENERAL_TIMx_CH1_GPIO_CLK, ENABLE);
	}
	else
  // ����Ƚ�ͨ��1 GPIO ��ʼ��
	RCC_APB2PeriphClockCmd(TimX[i].GENERAL_TIMx_CH1_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  TimX[i].GENERAL_TIMx_CH1_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(TimX[i].GENERAL_TIMx_CH1_PORT, &GPIO_InitStructure);
	
	
	if(i == 0)
	{
		/*** ���ο���AFIO/GPIOA/TIM2ʱ�� ***/
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_AFIO | TimX[i].GENERAL_TIMx_CH2_GPIO_CLK, ENABLE);
	}
	else
	// ����Ƚ�ͨ��2 GPIO ��ʼ��
	RCC_APB2PeriphClockCmd(TimX[i].GENERAL_TIMx_CH2_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin = TimX[i]. GENERAL_TIMx_CH2_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(TimX[i].GENERAL_TIMx_CH2_PORT, &GPIO_InitStructure);
	
	
	if(i == 0)
	{
		/*** ���ο���AFIO/GPIOA/TIM2ʱ�� ***/
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_AFIO | TimX[i].GENERAL_TIMx_CH3_GPIO_CLK, ENABLE);
	}
	else
	// ����Ƚ�ͨ��3 GPIO ��ʼ��
	RCC_APB2PeriphClockCmd(TimX[i].GENERAL_TIMx_CH3_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin = TimX[i]. GENERAL_TIMx_CH3_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(TimX[i].GENERAL_TIMx_CH3_PORT, &GPIO_InitStructure);
	
	if(i == 0)
	{
		/*** ���ο���AFIO/GPIOA/TIM2ʱ�� ***/
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_AFIO | TimX[i].GENERAL_TIMx_CH4_GPIO_CLK, ENABLE);
	}
	else
	// ����Ƚ�ͨ��4 GPIO ��ʼ��
	RCC_APB2PeriphClockCmd(TimX[i].GENERAL_TIMx_CH4_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  TimX[i].GENERAL_TIMx_CH4_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(TimX[i].GENERAL_TIMx_CH4_PORT, &GPIO_InitStructure);
}

//��һ��������ʱ��X(X=0 ��ӦTIM2, X=1 ��ӦTIM3, X=2 ��ӦTIM4, X=3,��ӦTIM5)
//�ڶ�������ARR��ֵ,����������psc��ֵ
static void GENERAL_TIM_Mode_Config(uint32_t j,uint32_t m,uint32_t n)
{
	
  
	
	if(j==0)
	{
		/*** ���ο���AFIO/GPIOA/TIM2ʱ�� ***/
//		RCC_APB2PeriphClockCmd( RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIOA, ENABLE);
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
		/*** ����JTAG���ã�SWD���� ***/
		GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);
		/*** ��ʱ��2������ӳ��1 ***/
		GPIO_PinRemapConfig( GPIO_PartialRemap1_TIM2, ENABLE);	
	}
	else
	{
		// ������ʱ��ʱ��,���ڲ�ʱ��CK_INT=72M
		GENERAL_TIM_APBxClock_FUN(TimX[j].GENERAL_TIMx_CLK,ENABLE);
	}
	
	
	// �������ڣ���������Ϊ100K
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	// �Զ���װ�ؼĴ�����ֵ���ۼ�TIM_Period+1��Ƶ�ʺ����һ�����»����ж�
	TIM_TimeBaseStructure.TIM_Period = m;	
	// ����CNT��������ʱ�� = Fck_int/(psc+1)
	TIM_TimeBaseStructure.TIM_Prescaler = n;	
	// ʱ�ӷ�Ƶ���� ����������ʱ��ʱ��Ҫ�õ�
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;		
	// ����������ģʽ������Ϊ���ϼ���
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;		
	// �ظ���������ֵ��û�õ����ù�
	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;	
	// ��ʼ����ʱ��
	TIM_TimeBaseInit(TimX[j].GENERAL_TIMx, &TIM_TimeBaseStructure);

	
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	// ����ΪPWMģʽ1
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	// ���ʹ��
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	// ���ͨ����ƽ��������	
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	TIM_OCInitStructure.TIM_Pulse = 6;///////////////////////
	
	// ����Ƚ�ͨ�� 1
	TIM_OC1Init(TimX[j].GENERAL_TIMx, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(TimX[j].GENERAL_TIMx, TIM_OCPreload_Enable);
	
	// ����Ƚ�ͨ�� 2
	TIM_OC2Init(TimX[j].GENERAL_TIMx, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(TimX[j].GENERAL_TIMx, TIM_OCPreload_Enable);
	
	// ����Ƚ�ͨ�� 3
	TIM_OC3Init(TimX[j].GENERAL_TIMx, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(TimX[j].GENERAL_TIMx, TIM_OCPreload_Enable);
	
	// ����Ƚ�ͨ�� 4
	TIM_OC4Init(TimX[j].GENERAL_TIMx, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(TimX[j].GENERAL_TIMx, TIM_OCPreload_Enable);
	
	// ʹ�ܼ�����
	TIM_Cmd(TimX[j].GENERAL_TIMx, ENABLE);
}


/* ----------------   PWM�ź� ���ں�ռ�ձȵļ���--------------- */
// ARR ���Զ���װ�ؼĴ�����ֵ
// CLK_cnt����������ʱ�ӣ����� Fck_int / (psc+1) = 72M/(psc+1)
// PWM �źŵ����� T = ARR * (1/CLK_cnt) = ��ARR+1��*(PSC+1) / 72M
// ռ�ձ�P=CCR/(ARR+1)

//��һ��������ʱ��X(X=0 ��ӦTIM2, X=1 ��ӦTIM3, X=2 ��ӦTIM4, X=3,��ӦTIM5)
//�ڶ�������ARR��ֵ,����������psc��ֵ
void GENERAL_TIMX_Init(uint32_t X,uint32_t ARR,uint32_t PSC)
{
	GENERAL_TIM_GPIO_Config(X);
	GENERAL_TIM_Mode_Config(X,ARR,PSC);		
}







