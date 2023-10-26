
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"


GPIO_InitTypeDef GPIO_InitStruct;

//F4 discovery �zerindeki buton PA0 a ba�l�
void GPIO_Config(){

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE);

 	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN;
 	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_0;
 	GPIO_InitStruct.GPIO_OType=GPIO_OType_PP;
 	GPIO_InitStruct.GPIO_PuPd=GPIO_PuPd_DOWN;
 	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_100MHz;


 	GPIO_Init(GPIOA,&GPIO_InitStruct);

 	 GPIO_InitStruct.GPIO_Mode=GPIO_Mode_OUT;
 	 GPIO_InitStruct.GPIO_Pin=GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15 ;
 	 GPIO_InitStruct.GPIO_OType=GPIO_OType_PP;
     GPIO_InitStruct.GPIO_PuPd=GPIO_PuPd_NOPULL;
 	 GPIO_InitStruct.GPIO_Speed=GPIO_Speed_100MHz;

 	 GPIO_Init(GPIOD,&GPIO_InitStruct);




}
void delay(uint32_t time){
	while(time--); //time 0 olana kadar d�ng�yle bekle delay fonksiyonu
}

int main(void)
{
	GPIO_Config();

  while (1)
  {

	  if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)){
		  while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0));
		  delay(10000);
		  GPIO_ToggleBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);

	  }

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


