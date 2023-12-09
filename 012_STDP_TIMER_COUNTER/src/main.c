
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
//týmer 84 mhz de

TIM_TimeBaseInitTypeDef TIM_Initstrcuct;
GPIO_InitTypeDef  GPIO_Initstrcuct;

int count = 0;

void TIMER_Config(){
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);


	TIM_Initstrcuct.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_Initstrcuct.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_Initstrcuct.TIM_Period=3999;
	TIM_Initstrcuct.TIM_Prescaler= 41999;
	TIM_Initstrcuct.TIM_RepetitionCounter =0;

	TIM_TimeBaseInit(TIM2,&TIM_Initstrcuct);

	TIM_Cmd(TIM2,ENABLE);



}

void GPIO_Config(){

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE);

	GPIO_Initstrcuct.GPIO_Mode=GPIO_Mode_OUT;
	GPIO_Initstrcuct.GPIO_OType=GPIO_OType_PP;
	GPIO_Initstrcuct.GPIO_Pin=GPIO_Pin_12 |GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
	GPIO_Initstrcuct.GPIO_PuPd=GPIO_PuPd_NOPULL;
	GPIO_Initstrcuct.GPIO_Speed=  GPIO_Speed_100MHz;

	GPIO_Init(GPIOD,&GPIO_Initstrcuct);

}

int main(void)
{

	TIMER_Config();
    GPIO_Config();

	while (1)
  {

      count = TIM_GetCounter(TIM2);

      if(count==1999){
    	  GPIO_SetBits(GPIOD,GPIO_Pin_12 |GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);

      }
      else if(count == 3999){
    	  GPIO_ResetBits(GPIOD,GPIO_Pin_12 |GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);
      }

  }
}


/*
 * Callback used by stm32f4_discovery_audio_codec.c.
 * Refer to stm32f4_discovery_audio_codec.h for more info.
 */
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
