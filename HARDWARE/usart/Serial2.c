#include "stm32f4xx.h"                  // Device header
                // Device header
#include <stdio.h>
#include <stdarg.h>
#include "Serial.h"
uint8_t Serial_RxFlag2;
/**
  * ?    ?:?????
  * ?    ?:?  
  * ? ? ?:?
  */
void Serial_Init2(void)
{
	 //GPIO????
    GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE); //??GPIOA??
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);//??USART1??
 
	//??1????????
	GPIO_PinAFConfig(GPIOD,GPIO_PinSource5,GPIO_AF_USART2); //GPIOA9???USART1
	GPIO_PinAFConfig(GPIOD,GPIO_PinSource6,GPIO_AF_USART2); //GPIOA10???USART1
	
	//USART1????
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6; //GPIOA9?GPIOA10
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//????
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//??50MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //??????
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; //??
	GPIO_Init(GPIOD,&GPIO_InitStructure); //???PA9,PA10

   //USART1 ?????
	USART_InitStructure.USART_BaudRate = 115200;//?????
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//???8?????
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//?????
	USART_InitStructure.USART_Parity = USART_Parity_No;//??????
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//????????
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//????
	USART_Init(USART2, &USART_InitStructure); //?????1
	

	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);//??????

	//Usart1 NVIC ??
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;//??1????
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0;//?????3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =0;		//????3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ????
	NVIC_Init(&NVIC_InitStructure);	//??????????VIC????

	USART_Cmd(USART2, ENABLE);  //????1 



}

/**
  * ?    ?:????????
  * ?    ?:Byte ????????
  * ? ? ?:?
  */
void Serial_SendByte2(uint8_t Byte)
{
	
	USART_SendData(USART2, Byte);		//????????????,???USART????????
	while (USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);	//??????
	/*?????????????????????,?????,???????*/
}

/**
  * ?    ?:????????
  * ?    ?:Array ?????????
  * ?    ?:Length ????????
  * ? ? ?:?
  */
void Serial_SendArray2(uint8_t *Array, uint16_t Length)
{
	uint16_t i;
	for (i = 0; i < Length; i ++)		//????
	{		
		 Serial_SendByte2(Array[i]);
	}
}

/**
  * ?    ?:?????????
  * ?    ?:String ??????????
  * ? ? ?:?
  */
void Serial_SendString2(char *String)
{
	uint8_t i;
	for (i = 0; String[i] != '\0'; i ++)//??????(???),?????????????
	{
		Serial_SendByte2(String[i]);		//????Serial_SendByte????????
	}
}

/**
  * ?    ?:????(????)
  * ? ? ?:?????X?Y??
  */
uint32_t Serial_Pow2(uint32_t X, uint32_t Y)
{
	uint32_t Result = 1;	//???????1
	while (Y --)			//??Y?
	{
		Result *= X;		//?X?????
	}
	return Result;
}

/**
  * ?    ?:??????
  * ?    ?:Number ??????,??:0~4294967295
  * ?    ?:Length ????????,??:0~10
  * ? ? ?:?
  */


/**
  * ?    ?:??printf??????????
  * ?    ?:????????,????
  * ? ? ?:????????,????
  */
//int fputc(int ch, FILE *f)
//{
//	Serial_SendByte1(ch);			//?printf????????????????
//	return ch;
//}
//int fputc(int ch,FILE *p)  //?????,???printf???????
//{
//	USART_SendData(USART1,(u8)ch);	
//	while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);
//	return ch;
//}

///**
//  * ?    ?:?????prinf??
//  * ?    ?:format ??????
//  * ?    ?:... ???????
//  * ? ? ?:?
//  */
//void Serial_Printf(char *format, ...)
//{
//	char String[100];				//??????
//	va_list arg;					//???????????????arg
//	va_start(arg, format);			//?format??,???????arg??
//	vsprintf(String, format, arg);	//??vsprintf???????????????????
//	va_end(arg);					//????arg
//	Serial_SendString1(String);		//????????(???)
//}

/**
  * ?    ?:???????
  * ?    ?:?
  * ? ? ?:?
  * ?    ?:??????,Serial_TxPacket??????????(FF)??(FE)?,?????????
  */
void Serial_SendPacket2(void)
{
	;	
}

/**
  * ?    ?:????????????
  * ?    ?:?
  * ? ? ?:??????????,??:0~1,???????,????1,??????????
  */
uint8_t Serial_GetRxFlag2(void)
{
	if (Serial_RxFlag2 == 1)			//??????1
	{
		Serial_RxFlag2 = 0;
		return 1;					//???1,????????
	}
	return 0;						//??????0,???0
}
uint8_t RxData2;
/**
  * ?    ?:USART1????
  * ?    ?:?
  * ? ? ?:?
  * ????:????????,????,?????????
  *           ???????????,?????????
  *           ????????,???????,???????????
  */
uint8_t recive2[20];
void USART2_IRQHandler(void)
{
	static uint8_t RxState = 0;		//????????????????
	static uint8_t pRxPacket = 0;	//?????????????????
	if (USART_GetITStatus(USART2, USART_IT_RXNE) == SET)	//?????USART1??????????
	{
		RxData2 = USART_ReceiveData(USART2);		//???????,??????????
		
		/*????????,????????????*/
		//&& Serial_RxFlag2 == 0
		/*?????0,???????*/
		if (RxState == 0)
		{
			if (RxData2 == 0x55 )		//?????????,?????????????
			{
				RxState = 1;			//??????
				pRxPacket = 0;			//????????
			}
		}
		/*?????1,???????,???????????????*/
		else if (RxState == 1)
		{
			if (RxData2 == 0x52)			//?????????
			{
				RxState = 2;			//??????
			}
			
							//????????
		}
		/*?????2,??????????*/
		else if (RxState == 2)
		{
			recive2[pRxPacket] = RxData2;		//???????????????
			pRxPacket ++;
//			Serial_SendByte1(RxData2);
			if(pRxPacket==19)
			{
				RxState=3;
			}
		}
		else if (RxState==3)			//?????????
			{
				RxState = 0;			
				Serial_RxFlag2 = 1;	
			}
		USART_ClearITPendingBit(USART2, USART_IT_RXNE);			//?????
	}
	
	
//	if (USART_GetITStatus(USART2, USART_IT_RXNE) == SET)		//?????USART1??????????
//	{
//		RxData2 = USART_ReceiveData(USART2);				//???????,??????????
//		USART_ClearITPendingBit(USART2, USART_IT_RXNE);		//?????
//		Serial_RxFlag2=1;
//	}

}
