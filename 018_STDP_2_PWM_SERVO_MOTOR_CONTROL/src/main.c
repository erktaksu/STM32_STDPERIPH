
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

GPIO_InitTypeDef GPIO_InitStruct;
TIM_TimeBaseInitTypeDef TIM_InitSturct;
TIM_OCInitTypeDef  TIMOC_InitStruct;

uint32_t delay_count;

void SysTick_Handler(void)
{
	delay_count--;



}
void delay_ms(uint32_t time){

	delay_count=time;

	while(delay_count); // 8 cycle gerçekleþir
}
void GPIO_Config(){

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE);

	GPIO_PinAFConfig(GPIOD, GPIO_PinSource12,GPIO_AF_TIM4);

	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AF;
	GPIO_InitStruct.GPIO_OType=GPIO_OType_PP;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_12  ;
	GPIO_InitStruct.GPIO_PuPd=GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_100MHz;

	GPIO_Init(GPIOD,&GPIO_InitStruct);




}

void TIM_Config()
{

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
	TIM_InitSturct.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_InitSturct.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_InitSturct.TIM_Period=19999;
	TIM_InitSturct.TIM_Prescaler=83;
	TIM_InitSturct.TIM_RepetitionCounter=0; //KAÇ DEFA SAYILCAÐINI SÖYLER


	TIM_TimeBaseInit(TIM4,&TIM_InitSturct);

	TIM_Cmd(TIM4,ENABLE);

	TIMOC_InitStruct.TIM_OCMode=TIM_OCMode_PWM1;
	TIMOC_InitStruct.TIM_OutputState=ENABLE;
	TIMOC_InitStruct.TIM_OCNPolarity=TIM_OCNPolarity_High;

	SysTick_Config(SystemCoreClock/1000); // 1ms de 1 kesmeye gidiyor


}

int i;
int main(void)
{
	GPIO_Config();
	TIM_Config();


  while (1)
  {

for(i=500; i<=2000; i++){
	  TIMOC_InitStruct.TIM_Pulse=i;
	  TIM_OC1Init(TIM4,&TIMOC_InitStruct);
	  TIM_OC1PreloadConfig(TIM4,TIM_OCPreload_Enable);
	  delay_ms(2); //tam 2 ms de bir

}
for( i=2000; i>=500; i--){
	  TIMOC_InitStruct.TIM_Pulse=i;
	  TIM_OC1Init(TIM4,&TIMOC_InitStruct);
	  TIM_OC1PreloadConfig(TIM4,TIM_OCPreload_Enable);
	  delay_ms(2); //tam 2 ms de bir
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
