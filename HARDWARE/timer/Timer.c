#include "stm32f4xx.h"                  // Device header
#include "lvgl.h"

void Timer7_Init(void)//??
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7, ENABLE);    
	
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_Period = 10-1; 	                      
	TIM_TimeBaseStructure.TIM_Prescaler=9000-1;                        
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;       
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;           
	TIM_TimeBaseInit(TIM7,&TIM_TimeBaseStructure); 
	
	TIM_ClearFlag(TIM7, TIM_FLAG_Update);
	
	TIM_ITConfig(TIM7, TIM_IT_Update, ENABLE);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel=TIM7_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=0;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=0;
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStruct);
	
	TIM_Cmd(TIM7,ENABLE);

	
}

void TIM7_IRQHandler()//20ms???
{
	if(TIM_GetITStatus(TIM7, TIM_IT_Update) == SET){
		
		lv_tick_inc(1);
		
		TIM_ClearITPendingBit(TIM7, TIM_IT_Update);
	}
}

