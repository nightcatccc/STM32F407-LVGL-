//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//中景园电子
//店铺地址：http://shop73023976.taobao.com/?spm=2013.1.0.0.M4PqC2
//
//  文 件 名   : main.c
//  版 本 号   : v2.0
//  作    者   : HuangKai
//  生成日期   : 2018-0101
//  最近修改   : 
//  功能描述   :演示例程(STM32F4系列)
//              说明: 
//              ----------------------------------------------------------------
//              GND  电源地
//              VCC  3.3v电源
//              D0   接PG12（SCL）
//              D1   接PD5（SDA）
//              RES  接PD4
//              DC   接PD15
//              BLK  接PD1
//              MISO 接PE8
//              CS1  接PE10
//              CS2  接PE12
//              PEN  接PE14
//              ----------------------------------------------------------------
// 修改历史   :
// 日    期   : 
// 作    者   : HuangKai
// 修改内容   : 创建文件
//版权所有，盗版必究。
//  生成日期   : 2018-0101
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


int main(void)
{
	Timer7_Init();
	delay_init(168);
	lv_init();
	lv_port_disp_init();
	lv_port_indev_init();

	
	lv_obj_t* switch_obj=lv_switch_create(lv_scr_act());
	lv_obj_set_size(switch_obj,120,60);
	lv_obj_align(switch_obj,LV_ALIGN_CENTER,0,0);
	
	while(1)
	{
//		tp_dev.scan(0);//扫描
//		if(tp_dev.sta & TP_PRES_DOWN)
//		{
//			LCD_ShowString(10,LCD_H-40,"X:",RED,WHITE,16,0);
//			LCD_ShowIntNum(26,LCD_H-40,tp_dev.x[0],3,RED,WHITE,16);
//		}
		lv_task_handler();
		delay_ms(5);

	}

}
