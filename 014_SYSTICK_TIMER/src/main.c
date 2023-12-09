
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

GPIO_InitTypeDef GPIO_Initstruct;



void GPIO_Config(){
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE);

	GPIO_Initstruct.GPIO_Pin=GPIO_Pin_12 |GPIO_Pin_13 |GPIO_Pin_14 |GPIO_Pin_15 ;
	GPIO_Initstruct.GPIO_Mode=GPIO_Mode_OUT;
	GPIO_Initstruct.GPIO_OType=GPIO_OType_PP;
	GPIO_Initstruct.GPIO_PuPd=GPIO_PuPd_NOPULL;
	GPIO_Initstruct.GPIO_Speed=GPIO_Speed_100MHz;

	GPIO_Init(GPIOD,&GPIO_Initstruct);


}
uint16_t count;
void delay_ms(uint32_t time){
	count=time;

	while(count);

}
int main(void)
{
	GPIO_Config();

	SysTick_Config(SystemCoreClock/1000); //1 milisaniyede bir interrupt

  while (1)
  {

	  GPIO_ToggleBits(GPIOD,GPIO_Pin_12 |GPIO_Pin_13 |GPIO_Pin_14 |GPIO_Pin_15 );
      delay_ms(1000);
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
