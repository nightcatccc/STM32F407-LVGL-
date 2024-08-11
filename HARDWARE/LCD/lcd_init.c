#include "lcd_init.h"
#include "delay.h"

void LCD_GPIO_Init(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA|RCC_AHB1Periph_GPIOB|RCC_AHB1Periph_GPIOC|RCC_AHB1Periph_GPIOD|RCC_AHB1Periph_GPIOE|RCC_AHB1Periph_GPIOG, ENABLE);//ʹ��PORTA~E,PORTGʱ��
 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
  GPIO_Init(GPIOG, &GPIO_InitStructure);//��ʼ��
	GPIO_SetBits(GPIOG,GPIO_Pin_12);
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_15 ;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
  GPIO_Init(GPIOD, &GPIO_InitStructure);//��ʼ��
	GPIO_SetBits(GPIOD,GPIO_Pin_1|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_15);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_14;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//��ͨ����ģʽ
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
 	GPIO_Init(GPIOE, &GPIO_InitStructure);	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10|GPIO_Pin_12;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
 	GPIO_Init(GPIOE, &GPIO_InitStructure);	
 	GPIO_SetBits(GPIOE,GPIO_Pin_10|GPIO_Pin_12);
}


/******************************************************************************
      ����˵����LCD��������д�뺯��
      ������ݣ�dat  Ҫд��Ĵ�������
      ����ֵ��  ��
******************************************************************************/
void LCD_Writ_Bus(u8 dat) 
{	
	u8 i;
	LCD_CS_Clr();
	for(i=0;i<8;i++)
	{			  
		LCD_SCLK_Clr();
		if(dat&0x80)
		{
		   LCD_MOSI_Set();
		}
		else
		{
		   LCD_MOSI_Clr();
		}
		LCD_SCLK_Set();
		dat<<=1;
	}	
  LCD_CS_Set();	
}


/******************************************************************************
      ����˵����LCDд������
      ������ݣ�dat д�������
      ����ֵ��  ��
******************************************************************************/
void LCD_WR_DATA8(u8 dat)
{
	LCD_Writ_Bus(dat);
}


/******************************************************************************
      ����˵����LCDд������
      ������ݣ�dat д�������
      ����ֵ��  ��
******************************************************************************/
void LCD_WR_DATA(u16 dat)
{
	LCD_Writ_Bus(dat>>8);
	LCD_Writ_Bus(dat);
}


/******************************************************************************
      ����˵����LCDд������
      ������ݣ�dat д�������
      ����ֵ��  ��
******************************************************************************/
void LCD_WR_REG(u8 dat)
{
	LCD_DC_Clr();//д����
	LCD_Writ_Bus(dat);
	LCD_DC_Set();//д����
}


/******************************************************************************
      ����˵����������ʼ�ͽ�����ַ
      ������ݣ�x1,x2 �����е���ʼ�ͽ�����ַ
                y1,y2 �����е���ʼ�ͽ�����ַ
      ����ֵ��  ��
******************************************************************************/
void LCD_Address_Set(u16 x1,u16 y1,u16 x2,u16 y2)
{
		LCD_WR_REG(0x2a);//�е�ַ����
		LCD_WR_DATA(x1);
		LCD_WR_DATA(x2);
		LCD_WR_REG(0x2b);//�е�ַ����
		LCD_WR_DATA(y1);
		LCD_WR_DATA(y2);
		LCD_WR_REG(0x2c);//������д
}

void LCD_Init(void)
{
	LCD_GPIO_Init();//��ʼ��GPIO
	
	LCD_RES_Clr();//��λ
	delay_ms(100);
	LCD_RES_Set();
	delay_ms(100);
	
	LCD_BLK_Set();//�򿪱���
  delay_ms(100);
	
	//************* Start Initial Sequence **********//
	LCD_WR_REG(0x11); //Sleep out 
	delay_ms(120);    //Delay 120ms 
	//************* Start Initial Sequence **********// 
	LCD_WR_REG(0Xf0);
	LCD_WR_DATA8(0xc3);
	LCD_WR_REG(0Xf0);
	LCD_WR_DATA8(0x96);
	LCD_WR_REG(0x36);    // Memory Access Control 
	if(USE_HORIZONTAL==0)LCD_WR_DATA8(0x48);
	else if(USE_HORIZONTAL==1)LCD_WR_DATA8(0x88);
	else if(USE_HORIZONTAL==2)LCD_WR_DATA8(0x28);
	else LCD_WR_DATA8(0xE8);
	
	LCD_WR_REG(0x3A);
	LCD_WR_DATA8(0x05);
	
	LCD_WR_REG(0Xe8);
	LCD_WR_DATA8(0x40);
	LCD_WR_DATA8(0x82);
	LCD_WR_DATA8(0x07);
	LCD_WR_DATA8(0x18);
	LCD_WR_DATA8(0x27);
	LCD_WR_DATA8(0x0a);
	LCD_WR_DATA8(0xb6);
	LCD_WR_DATA8(0x33);
	
	LCD_WR_REG(0Xc5);
	LCD_WR_DATA8(0x27);
	
	LCD_WR_REG(0Xc2);
	LCD_WR_DATA8(0xa7);
	
	LCD_WR_REG(0Xe0);
	LCD_WR_DATA8(0xf0);
	LCD_WR_DATA8(0x01);
	LCD_WR_DATA8(0x06);
	LCD_WR_DATA8(0x0f);
	LCD_WR_DATA8(0x12);
	LCD_WR_DATA8(0x1d);
	LCD_WR_DATA8(0x36);
	LCD_WR_DATA8(0x54);
	LCD_WR_DATA8(0x44);
	LCD_WR_DATA8(0x0c);
	LCD_WR_DATA8(0x18);
	LCD_WR_DATA8(0x16);
	LCD_WR_DATA8(0x13);
	LCD_WR_DATA8(0x15);
	
	LCD_WR_REG(0Xe1);
	LCD_WR_DATA8(0xf0);
	LCD_WR_DATA8(0x01);
	LCD_WR_DATA8(0x05);
	LCD_WR_DATA8(0x0a);
	LCD_WR_DATA8(0x0b);
	LCD_WR_DATA8(0x07);
	LCD_WR_DATA8(0x32);
	LCD_WR_DATA8(0x44);
	LCD_WR_DATA8(0x44);
	LCD_WR_DATA8(0x0c);
	LCD_WR_DATA8(0x18);
	LCD_WR_DATA8(0x17);
	LCD_WR_DATA8(0x13);
	LCD_WR_DATA8(0x16);
	
	LCD_WR_REG(0Xf0);
	LCD_WR_DATA8(0x3c);
	
	LCD_WR_REG(0Xf0);
	LCD_WR_DATA8(0x69);
	
	LCD_WR_REG(0X29);	 
} 








