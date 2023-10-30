
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"


GPIO_InitTypeDef GPIO_InitStruct;
DAC_InitTypeDef DAC_InitStruct;

int i=0;
float dac_voltage=0;

void  GPIO_Config(){


	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);

	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType=GPIO_OType_PP;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_4;
	GPIO_InitStruct.GPIO_PuPd=GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_100MHz;

	GPIO_Init(GPIOA,&GPIO_InitStruct);

}

void DAC1_Config(){

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC,ENABLE);
	DAC_InitStruct.DAC_WaveGeneration=DAC_WaveGeneration_None;
	DAC_InitStruct.DAC_Trigger=DAC_Trigger_None;
	DAC_InitStruct.DAC_OutputBuffer=DAC_OutputBuffer_Enable;  //G�r�lt� engellleme

	DAC_Init(DAC_Channel_1,&DAC_InitStruct);

	DAC_Cmd(DAC_Channel_1,ENABLE);

}


void delay(uint32_t time){
	while(time--);
}
int main(void)
{

  GPIO_Config();
  DAC1_Config();


  while (1)
  {

	  for(i=0; i<255; i++){
		  DAC_SetChannel1Data(DAC_Align_8b_R,i);
          dac_voltage=0.0129*i;
		  delay(180000);
	  }
	  i=0;

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
