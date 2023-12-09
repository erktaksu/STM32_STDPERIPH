#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

GPIO_InitTypeDef GPIO_Initstruct;
TIM_TimeBaseInitTypeDef TIM_Initstruct;
NVIC_InitTypeDef NVIC_Initstruct;

int count;

void GPIO_Config(){

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE);

	GPIO_Initstruct.GPIO_Mode=GPIO_Mode_OUT;
	GPIO_Initstruct.GPIO_Pin=GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
	GPIO_Initstruct.GPIO_OType=GPIO_OType_PP;
	GPIO_Initstruct.GPIO_PuPd=GPIO_PuPd_NOPULL;
	GPIO_Initstruct.GPIO_Speed=GPIO_Speed_100MHz;

	GPIO_Init(GPIOD,&GPIO_Initstruct);


}

void TIM_Config(){

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);

	TIM_Initstruct.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_Initstruct.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_Initstruct.TIM_Period=1999;
	TIM_Initstruct.TIM_Prescaler=41999;
	TIM_Initstruct.TIM_RepetitionCounter=0;

	TIM_TimeBaseInit(TIM3,&TIM_Initstruct);
	TIM_Cmd(TIM3,ENABLE);


}

void NVIC_Config(){

	NVIC_Initstruct.NVIC_IRQChannel=TIM3_IRQn;
	NVIC_Initstruct.NVIC_IRQChannelCmd=ENABLE;

	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);

	NVIC_Init(&NVIC_Initstruct);

}

void TIM3_IRQHandler(){

	GPIO_ToggleBits(GPIOD,GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);

	TIM_ClearITPendingBit(TIM3,TIM_IT_Update);

}


int main(void)
{
 GPIO_Config();
 TIM_Config();
 NVIC_Config();

  while (1)
  {

 count =TIM_GetCounter(TIM3);
  }
}



void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

/*
 * Callback used by stm324xg_eval_audio_codec.c.
 * Refer to stm324xg_eval_audio_codec.h for more info.
 */
uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
