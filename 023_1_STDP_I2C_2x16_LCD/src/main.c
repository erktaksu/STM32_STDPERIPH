
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "i2c-lcd.h"

GPIO_InitTypeDef GPIO_InitStruct;
I2C_InitTypeDef I2C_InitStruct;

void delay(uint32_t time){
	while(time--);
}
void GPIO_Config(){

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE);


	GPIO_PinAFConfig(GPIOB,GPIO_PinSource6,GPIO_AF_I2C1); //SCL Pin
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource7,GPIO_AF_I2C1); //Sda Pin

	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AF;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStruct.GPIO_OType=GPIO_OType_OD;
	GPIO_InitStruct.GPIO_PuPd=GPIO_PuPd_UP;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_100MHz;

	GPIO_Init(GPIOB,&GPIO_InitStruct);




}

void I2C_Config(){
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1,ENABLE);

	I2C_InitStruct.I2C_Ack=ENABLE;
	I2C_InitStruct.I2C_AcknowledgedAddress=I2C_AcknowledgedAddress_7bit;
	I2C_InitStruct.I2C_ClockSpeed=400000;
	I2C_InitStruct.I2C_DutyCycle=I2C_DutyCycle_2;
	I2C_InitStruct.I2C_Mode=I2C_Mode_I2C;
	I2C_InitStruct.I2C_OwnAddress1=0x00;

	I2C_Init(I2C1,&I2C_InitStruct);

	I2C_Cmd(I2C1,ENABLE);




}

void I2C_Write(uint8_t address, uint8_t data)
{
	while(I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY));  // I2C Me�gul oldu�u s�rece bekle

	I2C_GenerateSTART(I2C1, ENABLE);	// I2C Haberle�mesini ba�latt�k.

	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));

	I2C_Send7bitAddress(I2C1, address, I2C_Direction_Transmitter);

	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED ));

	I2C_SendData(I2C1, data);

	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));

	I2C_GenerateSTOP(I2C1, ENABLE);
}



int main(void)
{

GPIO_Config();
I2C_Config();

lcd_init();

  while (1)
  {

	  lcd_send_cmd(0x80);
		  lcd_sende_string("erkut ");
		  delay(63000000);
		  lcd_send_cmd(0xC3); //bir alt satır adresi bir alt satıra geçti
		  lcd_sende_string("aksu");
		  delay(63000000);
		  lcd_send_cmd(0x01);
		  delay(2100000);
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

