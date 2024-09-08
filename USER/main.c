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
#include "Timer.h"
#include "lv_port_indev_template.h"
#include "lv_conf.h"
#include "chinese.c"
#include "main_p.c"

extern const lv_font_t my_custom_font;
int main(void)
{
	Timer7_Init();
	delay_init(168);
	lv_init();
	lv_port_disp_init();
	lv_port_indev_init();

	static lv_style_t style;

	lv_obj_t *label = lv_label_create(lv_scr_act());
	lv_label_set_text( label,"如意金箍棒");
	lv_style_init(&style);
	lv_style_set_text_font(&style, &chinese);
	lv_obj_add_style(label,&style,LV_STATE_DEFAULT);
	
	LV_IMG_DECLARE(main_p);//此处输入c文件名字

	lv_obj_t *img = lv_img_create(lv_scr_act());  // 在 obj 上创建图像对象
	lv_img_set_src(img, &main_p);  // 设置图像源
	lv_obj_align(img, LV_ALIGN_CENTER, 0, 0);  // 图像居中显示
	while(1)
	{
//		tp_dev.scan(0);//ɨ��
//		if(tp_dev.sta & TP_PRES_DOWN)
//		{
//			LCD_ShowString(10,LCD_H-40,"X:",RED,WHITE,16,0);
//			LCD_ShowIntNum(26,LCD_H-40,tp_dev.x[0],3,RED,WHITE,16);
//		}
		lv_task_handler();
		delay_ms(5);

	}

}
