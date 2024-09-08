//////////////////////////////////////////////////////////////////////////////////	 
//±¾³ÌĞòÖ»¹©Ñ§Ï°Ê¹ÓÃ£¬Î´¾­×÷ÕßĞí¿É£¬²»µÃÓÃÓÚÆäËüÈÎºÎÓÃÍ¾
//ÖĞ¾°Ô°µç×Ó
//µêÆÌµØÖ·£ºhttp://shop73023976.taobao.com/?spm=2013.1.0.0.M4PqC2
//
//  ÎÄ ¼ş Ãû   : main.c
//  °æ ±¾ ºÅ   : v2.0
//  ×÷    Õß   : HuangKai
//  Éú³ÉÈÕÆÚ   : 2018-0101
//  ×î½üĞŞ¸Ä   : 
//  ¹¦ÄÜÃèÊö   :ÑİÊ¾Àı³Ì(STM32F4ÏµÁĞ)
//              ËµÃ÷: 
//              ----------------------------------------------------------------
//              GND  µçÔ´µØ
//              VCC  3.3vµçÔ´
//              D0   ½ÓPG12£¨SCL£©
//              D1   ½ÓPD5£¨SDA£©
//              RES  ½ÓPD4
//              DC   ½ÓPD15
//              BLK  ½ÓPD1
//              MISO ½ÓPE8
//              CS1  ½ÓPE10
//              CS2  ½ÓPE12
//              PEN  ½ÓPE14
//              ----------------------------------------------------------------
// ĞŞ¸ÄÀúÊ·   :
// ÈÕ    ÆÚ   : 
// ×÷    Õß   : HuangKai
// ĞŞ¸ÄÄÚÈİ   : ´´½¨ÎÄ¼ş
//°æÈ¨ËùÓĞ£¬µÁ°æ±Ø¾¿¡£
//  Éú³ÉÈÕÆÚ   : 2018-0101
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
	lv_label_set_text( label,"å¦‚æ„é‡‘ç®æ£’");
	lv_style_init(&style);
	lv_style_set_text_font(&style, &chinese);
	lv_obj_add_style(label,&style,LV_STATE_DEFAULT);
	
	LV_IMG_DECLARE(main_p);//æ­¤å¤„è¾“å…¥cæ–‡ä»¶åå­—

	lv_obj_t *img = lv_img_create(lv_scr_act());  // åœ¨ obj ä¸Šåˆ›å»ºå›¾åƒå¯¹è±¡
	lv_img_set_src(img, &main_p);  // è®¾ç½®å›¾åƒæº
	lv_obj_align(img, LV_ALIGN_CENTER, 0, 0);  // å›¾åƒå±…ä¸­æ˜¾ç¤º
	while(1)
	{
//		tp_dev.scan(0);//É¨Ãè
//		if(tp_dev.sta & TP_PRES_DOWN)
//		{
//			LCD_ShowString(10,LCD_H-40,"X:",RED,WHITE,16,0);
//			LCD_ShowIntNum(26,LCD_H-40,tp_dev.x[0],3,RED,WHITE,16);
//		}
		lv_task_handler();
		delay_ms(5);

	}

}
