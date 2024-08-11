//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//�о�԰����
//���̵�ַ��http://shop73023976.taobao.com/?spm=2013.1.0.0.M4PqC2
//
//  �� �� ��   : main.c
//  �� �� ��   : v2.0
//  ��    ��   : HuangKai
//  ��������   : 2018-0101
//  ����޸�   : 
//  ��������   :��ʾ����(STM32F4ϵ��)
//              ˵��: 
//              ----------------------------------------------------------------
//              GND  ��Դ��
//              VCC  3.3v��Դ
//              D0   ��PG12��SCL��
//              D1   ��PD5��SDA��
//              RES  ��PD4
//              DC   ��PD15
//              BLK  ��PD1
//              MISO ��PE8
//              CS1  ��PE10
//              CS2  ��PE12
//              PEN  ��PE14
//              ----------------------------------------------------------------
// �޸���ʷ   :
// ��    ��   : 
// ��    ��   : HuangKai
// �޸�����   : �����ļ�
//��Ȩ���У�����ؾ���
//  ��������   : 2018-0101
//All rights reserved
//******************************************************************************/
#include "delay.h"
#include "sys.h"
#include "led.h"
#include "lcd_init.h"
#include "lcd.h"
#include "pic.h"
#include "touch.h" 
#include "lvgl.h"
#include "lv_port_disp_template.h"


void lv_ex_label(void)
{
		char* github_addr = "https://gitee.com/W23";
		lv_obj_t * label = lv_label_create(lv_scr_act());
    lv_label_set_recolor(label, true);
    lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR); /*Circular scroll*/
    lv_obj_set_width(label, 120);
    lv_label_set_text_fmt(label, "#ff0000 Gitee: %s#", github_addr);
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 10);
	
    lv_obj_t * label2 = lv_label_create(lv_scr_act());
    lv_label_set_recolor(label2, true);
    lv_label_set_long_mode(label2, LV_LABEL_LONG_SCROLL_CIRCULAR); /*Circular scroll*/
    lv_obj_set_width(label2, 120);
    lv_label_set_text_fmt(label2, "#ff0000 Hello# #0000ff world !123456789#");
    lv_obj_align(label2, LV_ALIGN_CENTER, 0, -10);
}


int main(void)
{
//	u8 i,j;
//	float t=0;
// 	u16 lastpos[2];//���һ�ε�����
	delay_init(168);
//	LED_Init();//LED��ʼ��
//	LCD_Init();//LCD��ʼ��
//	LCD_Fill(0,0,LCD_W,LCD_H,WHITE);
//	lastpos[0]=0XFFFF;
//	LED0=0;

//	LCD_ShowChinese(0,0,"�о�԰����",RED,WHITE,32,0);
//	LCD_ShowString(0,40,"LCD_W:",RED,WHITE,16,0);
//	LCD_ShowIntNum(48,40,LCD_W,3,RED,WHITE,16);
//	LCD_ShowString(80,40,"LCD_H:",RED,WHITE,16,0);
//	LCD_ShowIntNum(128,40,LCD_H,3,RED,WHITE,16);
//	LCD_ShowString(80,40,"LCD_H:",RED,WHITE,16,0);
//	LCD_ShowString(0,70,"Increaseing Nun:",RED,WHITE,16,0);
//	LCD_ShowFloatNum1(128,70,t,4,RED,WHITE,16);
//	t+=0.11f;
//	for(j=0;j<7;j++)
//	{
//		for(i=0;i<8;i++)
//		{
//			LCD_ShowPicture(40*i,200+j*40,40,40,gImage_1);
//		}
//	}
//	delay_ms(1000);
//	LCD_Fill(0,0,LCD_W,LCD_H,WHITE);
//	
//	TP_Init();
//	LCD_ShowString(10,LCD_H-40,"X:",RED,WHITE,16,0);
//	LCD_ShowIntNum(26,LCD_H-40,0,3,RED,WHITE,16);
//	LCD_ShowString(10,LCD_H-20,"Y:",RED,WHITE,16,0);
//	LCD_ShowIntNum(26,LCD_H-20,0,3,RED,WHITE,16);
//	while(1)
//	{
// 		tp_dev.scan(0);//ɨ��
// 		if(tp_dev.sta&TP_PRES_DOWN)//�а���������
//		{				  
//			delay_ms(1);//��Ҫ����ʱ,��������Ϊ�а�������.		    
//			if((tp_dev.x[0]<(LCD_W-1)&&tp_dev.x[0]>=1)&&(tp_dev.y[0]<(LCD_H-1)&&tp_dev.y[0]>=1))
//			{			 
//				if(lastpos[0]==0XFFFF)
//				{
//					lastpos[0]=tp_dev.x[0];
//					lastpos[1]=tp_dev.y[0];
//				}
//				LCD_DrawRoughLine(lastpos[0],lastpos[1],tp_dev.x[0],tp_dev.y[0],BLUE);//����
//				lastpos[0]=tp_dev.x[0];
//				lastpos[1]=tp_dev.y[0];
//				LCD_ShowString(10,LCD_H-40,"X:",RED,WHITE,16,0);
//				LCD_ShowIntNum(26,LCD_H-40,tp_dev.x[0],3,RED,WHITE,16);
//				LCD_ShowString(10,LCD_H-20,"Y:",RED,WHITE,16,0);
//				LCD_ShowIntNum(26,LCD_H-20,tp_dev.y[0],3,RED,WHITE,16);
//			}    
//		}
//	}
//	LCD_Init();
	lv_init();
	lv_port_disp_init();
	lv_ex_label();
	
while(1)
{
	
		lv_task_handler();
		delay_ms(5);

}

}
