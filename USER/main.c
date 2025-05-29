//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ���������ɣ��������������κ���;
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
#include "jiantu.c"
#include "chasulun.c"
#include "jiantou.c"
#include "xiaoche.c"
#include "fxp.c"
#include "bjt.c"
#include "Serial3.h"
#include "lanyalianjie.c"
#include "lanyafeilianjie.c"
extern const lv_font_t my_custom_font;
extern uint8_t recive3[20];
float speed_x;
float speed_y;
float odom;
float pose_x;
float pose_y;

static void set_label_opacity(lv_obj_t * obj, int value)//渐隐渐显动画
{
	lv_obj_set_style_opa(obj, value, 0); 
}
static void set_img_opacity(lv_obj_t * obj, int value)//渐隐渐显
{
	lv_obj_set_style_opa(obj, value, 0); 
}
static lv_style_t style;
lv_obj_t *label ;
lv_obj_t *line_1 ;
lv_obj_t *img;
lv_obj_t * btn_src;

int flag_pkg;
lv_obj_t * checkbox_2;
lv_obj_t * dot_2_1;
lv_obj_t * dot_2_2;
lv_obj_t * dot_2_3;
lv_obj_t * dot_2_4;
lv_obj_t *img_2_1;
lv_obj_t *img_2_2;
lv_obj_t *img_2_3;
lv_obj_t *img_2_4;
lv_obj_t *img_bj;
lv_obj_t *img_jaintou_2;
lv_obj_t *btn_2;
lv_obj_t *img_bt;
lv_obj_t *img_bt_f;

lv_obj_t * control_1;
lv_obj_t * control_2;
lv_obj_t * control_3;
lv_obj_t * control_4;
int flag_check;
lv_obj_t * line_3_1;
lv_obj_t * label_3_1;
static lv_style_t style_3_1;
lv_obj_t * label_3_2;
lv_obj_t * src_3;
lv_obj_t * esc_btn;
lv_obj_t * label_3_3;

lv_obj_t * line_3_2;
lv_obj_t * line_3_3;
lv_obj_t * line_3_4;
lv_obj_t * label_3_4;
lv_obj_t * label_3_5;
lv_obj_t * label_3_6;
lv_obj_t * label_3_7;
lv_obj_t * label_3_8;

lv_obj_t * label_2_7;
lv_obj_t * label_2_8;
lv_obj_t * label_2_9;
lv_obj_t * label_2_10;
lv_obj_t * line_3_5;
lv_obj_t * label_3_9;
int flag_1_on;
int flag_1_off;

int flag_2_on;
int flag_2_off;

int flag_3_on;
int flag_3_off;

int flag_4_on;
int flag_4_off;

char buf_3_4[128];
char buf_3_5[128];
char buf_3_6[128];
char buf_3_7[128];
char buf_3_8[128];

static void btn_1_event_handler(lv_event_t * e) {
    lv_obj_t * btn = lv_event_get_target(e);

    // 获取事件类型
    lv_event_code_t code = lv_event_get_code(e);
    
    if (code == LV_EVENT_PRESSING) {
		flag_1_off=0;
		if(flag_1_on==0){
		Serial_SendByte3(0x01);
		flag_1_on=1;
		}
		
        // 按键按下时放大
		lv_obj_set_pos(btn,193,83);
        lv_obj_set_size(btn, 85, 85); // 调整为你想要的尺寸
    } else if (code == LV_EVENT_RELEASED) {
        // 按键释放时恢复原始尺寸
		flag_1_on=0;
		if(flag_1_off==0){
		Serial_SendByte3(0x00);
		flag_1_off=1;
		}
		lv_obj_set_pos(btn, 200, 90);
        lv_obj_set_size(btn, 70, 70); // 恢复原始尺寸
    }
}

static void btn_2_event_handler(lv_event_t * e) {//BACK
    lv_obj_t * btn = lv_event_get_target(e);

    // 获取事件类型
    lv_event_code_t code = lv_event_get_code(e);
    
    if (code == LV_EVENT_PRESSING) {
		flag_2_off=0;
		if(flag_2_on==0){
		Serial_SendByte3(0x04);
		flag_2_on=1;
		}
		
        // 按键按下时放大
		lv_obj_set_pos(btn,193,173);
        lv_obj_set_size(btn, 85, 85); // 调整为你想要的尺寸
    } else if (code == LV_EVENT_RELEASED) {
		
		flag_2_on=0;
		if(flag_2_off==0){
		Serial_SendByte3(0x00);
		flag_1_off=2;
		}
		
        // 按键释放时恢复原始尺寸
		lv_obj_set_pos(btn, 200, 180);
        lv_obj_set_size(btn, 70, 70); // 恢复原始尺寸
    }
}

static void btn_3_event_handler(lv_event_t * e) {//left
    lv_obj_t * btn = lv_event_get_target(e);

    // 获取事件类型
    lv_event_code_t code = lv_event_get_code(e);
    
    if (code == LV_EVENT_PRESSING) {
		
		flag_3_off=0;
		if(flag_3_on==0){
		Serial_SendByte3(0x03);
		flag_3_on=1;
		}
		
		
        // 按键按下时放大
		lv_obj_set_pos(btn,103,173);
        lv_obj_set_size(btn, 85, 85); // 调整为你想要的尺寸
    } else if (code == LV_EVENT_RELEASED) {
		
		flag_3_on=0;
		if(flag_3_off==0){
		Serial_SendByte3(0x00);
		flag_3_off=2;
		}
		
        // 按键释放时恢复原始尺寸
		lv_obj_set_pos(btn,110, 180);
        lv_obj_set_size(btn, 70, 70); // 恢复原始尺寸
    }
}

static void btn_4_event_handler(lv_event_t * e) {
    lv_obj_t * btn = lv_event_get_target(e);

    // 获取事件类型
    lv_event_code_t code = lv_event_get_code(e);
    
    if (code == LV_EVENT_PRESSING) {
		
		flag_4_off=0;
		if(flag_4_on==0){
		Serial_SendByte3(0x02);
		flag_4_on=1;
		}
		
        // 按键按下时放大
		lv_obj_set_pos(btn,283,173);
        lv_obj_set_size(btn, 85, 85); // 调整为你想要的尺寸
    } else if (code == LV_EVENT_RELEASED) {
		
		flag_4_on=0;
		if(flag_4_off==0){
		Serial_SendByte3(0x00);
		flag_4_off=2;
		}
		
        // 按键释放时恢复原始尺寸
		lv_obj_set_pos(btn, 290, 180);
        lv_obj_set_size(btn, 70, 70); // 恢复原始尺寸
    }
}

static void esc_btn_event_handler(lv_event_t * e) {
	lv_obj_t * btn = lv_event_get_target(e); // 获取事件源，即按钮对象
	if (lv_event_get_code(e) == LV_EVENT_CLICKED) {
	lv_obj_del(src_3);
	lv_obj_del(label_3_1);
	lv_obj_del(label_3_2);
	lv_obj_del(label_3_3);
	lv_obj_del(esc_btn);
	lv_obj_del(line_3_1);	
	lv_obj_del(label_3_9);
	lv_obj_del(line_3_5);
	lv_obj_set_style_border_width(control_1, 0, 0); // 2像素宽
	}
}


static void img_btn_event_handler(lv_event_t * e) {//第二次切换屏幕的右下角按钮
    lv_obj_t * btn = lv_event_get_target(e); // 获取事件源，即按钮对象
	if (lv_event_get_code(e) == LV_EVENT_CLICKED) {
    lv_obj_del(img_jaintou_2);
	lv_obj_del(img_2_1);
	lv_obj_del(img_2_2);
	lv_obj_del(img_2_3);
	lv_obj_del(img_2_4);		
	lv_obj_del(dot_2_1);
	lv_obj_del(dot_2_2);
	lv_obj_del(dot_2_3);
	lv_obj_del(dot_2_4);
	lv_obj_del(checkbox_2);
	lv_obj_del(btn_2);
	lv_obj_del(label_2_7);
	lv_obj_del(label_2_8);
	lv_obj_del(label_2_9);
	lv_obj_del(label_2_10);
	flag_pkg=3;
		
	src_3 = lv_obj_create(lv_scr_act());
	lv_obj_set_pos(src_3, 0, 0); // 设置位置
	lv_obj_set_size(src_3, 480,320); // 设置大小
	lv_obj_set_style_bg_color(src_3, lv_color_hex(0x808080), 0); // 设置背景颜色
	lv_obj_set_style_bg_opa(src_3, 150, 0); // 确保颜色不透明
	
	control_1 = lv_obj_create(lv_scr_act());
	lv_obj_set_pos(control_1, 200, 90); // 设置位置
	lv_obj_set_size(control_1, 70,70); // 设置大小
	lv_obj_set_style_bg_color(control_1,lv_color_hex(0x0095B6), 0);
	lv_obj_set_style_bg_opa(control_1, LV_OPA_COVER, 0); // 确保颜色不透明
	lv_obj_add_event_cb(control_1, btn_1_event_handler, LV_EVENT_ALL, NULL);
		
	control_2 = lv_obj_create(lv_scr_act());
	lv_obj_set_pos(control_2, 200, 180); // 设置位置
	lv_obj_set_size(control_2, 70,70); // 设置大小
	lv_obj_set_style_bg_color(control_2,lv_color_hex(0x0095B6), 0);
	lv_obj_set_style_bg_opa(control_2, LV_OPA_COVER, 0); // 确保颜色不透明
	lv_obj_add_event_cb(control_2, btn_2_event_handler, LV_EVENT_ALL, NULL);
	
	control_3 = lv_obj_create(lv_scr_act());
	lv_obj_set_pos(control_3, 110, 180); // 设置位置
	lv_obj_set_size(control_3, 70,70); // 设置大小
	lv_obj_set_style_bg_color(control_3,lv_color_hex(0x0095B6), 0);
	lv_obj_set_style_bg_opa(control_3, LV_OPA_COVER, 0); // 确保颜色不透明
	lv_obj_add_event_cb(control_3, btn_3_event_handler, LV_EVENT_ALL, NULL);
	
	control_4 = lv_obj_create(lv_scr_act());
	lv_obj_set_pos(control_4, 290, 180); // 设置位置
	lv_obj_set_size(control_4, 70,70); // 设置大小
	lv_obj_set_style_bg_color(control_4,lv_color_hex(0x0095B6), 0);
	lv_obj_set_style_bg_opa(control_4, LV_OPA_COVER, 0); // 确保颜色不透明
	lv_obj_add_event_cb(control_4, btn_4_event_handler, LV_EVENT_ALL, NULL);
	
//	line_3_2= lv_line_create(lv_scr_act());
//	 static lv_point_t points_3[] = {
//        {10, 30},
//        {120, 30}
//    };
//	 lv_line_set_points(line_3_2, points_3, 2);
	
	
	label_3_4 = lv_label_create(lv_scr_act());
	lv_label_set_text(label_3_4,"disconnected");
	lv_obj_set_pos(label_3_4,10,13);
	
	
	
	label_3_5 = lv_label_create(lv_scr_act());
	lv_label_set_text(label_3_5,"disconnected");
	lv_obj_set_pos(label_3_5,10,45);
    
	
	label_3_6 = lv_label_create(lv_scr_act());
	lv_label_set_text(label_3_6,"disconnected");
	lv_obj_set_pos(label_3_6,10,73);
	
	label_3_7 = lv_label_create(lv_scr_act());
	lv_label_set_text(label_3_7,"disconnected");
	lv_obj_set_pos(label_3_7,10,103);
	
	label_3_8 = lv_label_create(lv_scr_act());
	lv_label_set_text(label_3_8,"disconnected");
	lv_obj_set_pos(label_3_8,10,133);
	
//	 line_3_3= lv_line_create(lv_scr_act());
//	 static lv_point_t points_3_3[] = {
//        {10, 60},
//        {120, 60}
//    };
//	 lv_line_set_points(line_3_3, points_3_3, 2);
	
//	 line_3_4= lv_line_create(lv_scr_act());
//	 static lv_point_t points_3_4[] = {
//        {10, 90},
//        {120, 90}
//    };	 
//	lv_line_set_points(line_3_4, points_3_4, 2);
	
	if(flag_check==1){
	lv_obj_set_style_border_color(control_1, lv_color_hex(0x000000), 0); 
	lv_obj_set_style_border_width(control_1, 2, 0); // 2像素宽
		
	line_3_1= lv_line_create(lv_scr_act());
	 static lv_point_t points[] = {
        {240, 90},
        {260, 60}
    };
    lv_line_set_points(line_3_1, points, 2);
	
	label_3_1 = lv_label_create(lv_scr_act());
	lv_label_set_text(label_3_1,"控制");
	lv_style_init(&style_3_1);
	lv_style_set_text_font(&style_3_1, &chinese);
	lv_obj_add_style(label_3_1,&style_3_1,LV_STATE_DEFAULT);
	lv_obj_set_pos(label_3_1,260,45);
	
	label_3_2 = lv_label_create(lv_scr_act());
	lv_label_set_text(label_3_2,"按键按下控制小车探索地图。当地图完全探索后，立即结束并保存。建图时不要进行大幅度转弯。请注意地图是否超过规格");
	lv_obj_add_style(label_3_2,&style_3_1,LV_STATE_DEFAULT);
	lv_obj_set_pos(label_3_2,280,80);
	lv_obj_set_width(label_3_2, 200);
	
	
	line_3_5= lv_line_create(lv_scr_act());
	 static lv_point_t points_3_5[] = {
        {35, 160},
        {65, 190}
    };
    lv_line_set_points(line_3_5, points_3_5, 2);
	
	label_3_9 = lv_label_create(lv_scr_act());
	lv_label_set_text(label_3_9,"dynamic parameters");
	lv_obj_set_pos(label_3_9,30,190);
	
	esc_btn = lv_obj_create(lv_scr_act());
	lv_obj_set_pos(esc_btn, 0,0); // 设置位置
	lv_obj_set_size(esc_btn, 40,40); // 设置大小
	lv_obj_set_style_bg_color(esc_btn,lv_color_hex(0xFF0000), 0);
	lv_obj_set_style_bg_opa(esc_btn, LV_OPA_COVER, 0); // 确保颜色不透明
	lv_obj_add_event_cb(esc_btn, esc_btn_event_handler, LV_EVENT_ALL, NULL);
	
	label_3_3 = lv_label_create(lv_scr_act());
	lv_label_set_text(label_3_3,"esc");
	lv_obj_set_pos(label_3_3,10,10);
	}
	
	
	
	}
}
static void checkbox_event_hander(lv_event_t * e)//复选框
{
   lv_event_code_t code = lv_event_get_code(e);
   lv_obj_t * obj = lv_event_get_target(e);
	
	
   if(code == LV_EVENT_VALUE_CHANGED){
     if(flag_check==1){
	 flag_check=0;
	 }
	 else{
	 flag_check=1;
	 }
   }
}
extern int count;
static void btn_src_event_handler(lv_event_t * e) {//第一次切换屏幕的全屏按钮
    lv_obj_t * obj = lv_event_get_target(e);
    lv_point_t point;
    lv_indev_get_point(lv_indev_get_act(), &point);
	
    if (lv_event_get_code(e) == LV_EVENT_CLICKED) {
		lv_obj_del(btn_src);
		
		
		
		
		img_2_1 = lv_img_create(lv_scr_act());  
		lv_img_set_src(img_2_1, &jiantu);  
		lv_obj_align(img_2_1, LV_ALIGN_CENTER, 0, 0); 
		lv_obj_set_pos(img_2_1,0,-40);
		lv_obj_clear_flag(img_2_1, LV_OBJ_FLAG_HIDDEN);
		
		img_2_2 = lv_img_create(lv_scr_act());  
		lv_img_set_src(img_2_2, &chasulun);  
		lv_obj_align(img_2_2, LV_ALIGN_CENTER, 0, 0); 
		lv_obj_set_pos(img_2_2,0,-40);
		lv_obj_add_flag(img_2_2, LV_OBJ_FLAG_HIDDEN);
		
		img_2_3 = lv_img_create(lv_scr_act());  
		lv_img_set_src(img_2_3, &xiaoche);  
		lv_obj_align(img_2_3, LV_ALIGN_CENTER, 0, 0); 
		lv_obj_set_pos(img_2_3,0,-40);
		lv_obj_add_flag(img_2_3, LV_OBJ_FLAG_HIDDEN);
		
		img_2_4 = lv_img_create(lv_scr_act());  
		lv_img_set_src(img_2_4, &fxp);  
		lv_obj_align(img_2_4, LV_ALIGN_CENTER, 0, 0); 
		lv_obj_set_pos(img_2_4,0,-40);
		lv_obj_add_flag(img_2_4, LV_OBJ_FLAG_HIDDEN);
		
		label_2_7 = lv_label_create(lv_scr_act());
		lv_label_set_text(label_2_7,"定位模式已经可以启用，请在虚拟机端查看定位以及动态障碍。");
		lv_obj_set_pos(label_2_7,50,150);
		lv_obj_add_style(label_2_7,&style,LV_STATE_DEFAULT);
//		lv_obj_set_width(label_2_7, 200);
		lv_obj_add_flag(label_2_7, LV_OBJ_FLAG_HIDDEN);
		
		label_2_8 = lv_label_create(lv_scr_act());
		lv_label_set_text(label_2_8,"目前建图只支持差速轮小车，万向轮请等待开发。");
		lv_obj_set_pos(label_2_8,100,150);
		lv_obj_add_style(label_2_8,&style,LV_STATE_DEFAULT);
//		lv_obj_set_width(label_2_8, 200);
		lv_obj_add_flag(label_2_8, LV_OBJ_FLAG_HIDDEN);
		
		label_2_9 = lv_label_create(lv_scr_act());
		lv_label_set_text(label_2_9,"你的小车我喜欢，你的电池记得关。");
		lv_obj_set_pos(label_2_9,120,150);
		lv_obj_add_style(label_2_9,&style,LV_STATE_DEFAULT);
//		lv_obj_set_width(label_2_9, 200);
		lv_obj_add_flag(label_2_9, LV_OBJ_FLAG_HIDDEN);
		
		label_2_10 = lv_label_create(lv_scr_act());
		lv_label_set_text(label_2_10,"遥控小车建图时切记不要大幅度转向，否则只能从头开始喽。");
		lv_obj_set_pos(label_2_10,60,150);
		lv_obj_add_style(label_2_10,&style,LV_STATE_DEFAULT);
//		lv_obj_set_width(label_2_10, 200);
		lv_obj_add_flag(label_2_10, LV_OBJ_FLAG_HIDDEN);
		
		
        flag_pkg=2;
		lv_obj_del(line_1);
		lv_obj_del(img);
		lv_obj_del(label);
		
		checkbox_2 = lv_checkbox_create(lv_scr_act());
		lv_obj_set_pos(checkbox_2, 170, 220); // ????
		lv_obj_set_size(checkbox_2, 250, 30); // ????
		lv_checkbox_set_text(checkbox_2, "启用引导模式"); // ???????
//		lv_obj_set_size(checkbox_2,100,40);
		lv_obj_add_style(checkbox_2,&style,LV_STATE_DEFAULT);
		lv_obj_add_event_cb(checkbox_2,checkbox_event_hander,LV_EVENT_ALL,NULL);  //设置回调显示
		
		dot_2_1 = lv_obj_create(lv_scr_act());
		lv_obj_set_pos(dot_2_1, 205, 175); // 设置位置
		lv_obj_set_size(dot_2_1, 10,10); // 设置大小
		lv_obj_set_style_radius(dot_2_1, LV_RADIUS_CIRCLE, 0); // 使其成为圆形
		lv_obj_set_style_bg_color(dot_2_1, lv_color_black(), 0); // 设置背景颜色
		lv_obj_set_style_bg_opa(dot_2_1, LV_OPA_COVER, 0); // 确保颜色不透明
		
		dot_2_2 = lv_obj_create(lv_scr_act());
		lv_obj_set_pos(dot_2_2, 225, 175); // 设置位置
		lv_obj_set_size(dot_2_2, 10,10); // 设置大小
		lv_obj_set_style_radius(dot_2_2, LV_RADIUS_CIRCLE, 0); // 使其成为圆形
		lv_obj_set_style_bg_color(dot_2_2, lv_color_black(), 0); // 设置背景颜色
		lv_obj_set_style_bg_opa(dot_2_2, LV_OPA_COVER, 0); // 确保颜色不透明
		
		dot_2_3 = lv_obj_create(lv_scr_act());
		lv_obj_set_pos(dot_2_3, 245, 175); // 设置位置
		lv_obj_set_size(dot_2_3, 10,10); // 设置大小
		lv_obj_set_style_radius(dot_2_3, LV_RADIUS_CIRCLE, 0); // 使其成为圆形
		lv_obj_set_style_bg_color(dot_2_3, lv_color_black(), 0); // 设置背景颜色
		lv_obj_set_style_bg_opa(dot_2_3, LV_OPA_COVER, 0); // 确保颜色不透明
		
		dot_2_4 = lv_obj_create(lv_scr_act());
		lv_obj_set_pos(dot_2_4, 265, 175); // 设置位置
		lv_obj_set_size(dot_2_4, 10,10); // 设置大小
		lv_obj_set_style_radius(dot_2_4, LV_RADIUS_CIRCLE, 0); // 使其成为圆形
		lv_obj_set_style_bg_color(dot_2_4, lv_color_black(), 0); // 设置背景颜色
		lv_obj_set_style_bg_opa(dot_2_4, LV_OPA_COVER, 0); // 确保颜色不透明
		count=0;
		btn_2 = lv_btn_create(lv_scr_act());
		lv_obj_set_size(btn_2, 32, 32); // 设置按钮大小
		lv_obj_set_pos(btn_2,440,280);

    // 创建图片对象
		img_jaintou_2 = lv_img_create(btn_2);
		lv_img_set_src(img_jaintou_2, &jiantou); // `my_image` 是图片资源
		lv_obj_set_size(img_jaintou_2, 32, 32); // 设置图片大小与按钮一致
		lv_obj_set_pos(img_jaintou_2,440,280);
    // 将图片添加到按钮中
		lv_obj_align(img_jaintou_2, LV_ALIGN_CENTER, 0, 0); // 将图片对齐到按钮中心

    // 设置按钮事件
		lv_obj_add_event_cb(btn_2, img_btn_event_handler, LV_EVENT_CLICKED, NULL);
		
    }
}

int main(void)
{
	Timer7_Init();
	delay_init(168);
	Serial_Init3();
	lv_init();
	lv_port_disp_init();
	lv_port_indev_init();
	LV_IMG_DECLARE(main_p);
	LV_IMG_DECLARE(jiantu);
	LV_IMG_DECLARE(chasulun);
	LV_IMG_DECLARE(jiantou);
	LV_IMG_DECLARE(xiaoche);
	LV_IMG_DECLARE(fxp);
	LV_IMG_DECLARE(bjt);
	LV_IMG_DECLARE(lanyalianjie);
	LV_IMG_DECLARE(lanyafeilianjie);
	label = lv_label_create(lv_scr_act());
	lv_label_set_text(label,"按下任意键进入控制模式");
	lv_style_init(&style);
	lv_style_set_text_font(&style, &chinese);
	lv_obj_add_style(label,&style,LV_STATE_DEFAULT);
//	img_bj = lv_img_create(lv_scr_act());  
//	lv_img_set_src(img_bj, &bjt);  

//	lv_obj_set_pos(img_bj,0,0);
//	lv_obj_add_flag(img_bj, LV_OBJ_FLAG_HIDDEN);
	

	line_1= lv_line_create(lv_scr_act());
	 static lv_point_t points[] = {
        {200, 190},
        {280, 190}
    };
    lv_line_set_points(line_1, points, 2);
	
	img = lv_img_create(lv_scr_act());  
	lv_img_set_src(img, &main_p);  
	lv_obj_align(img, LV_ALIGN_CENTER, 0, 0);  
	
	lv_obj_align_to(label,img,LV_ALIGN_BOTTOM_MID,0,30);
	
	
	lv_anim_t a_label;
    lv_anim_init(&a_label);
    lv_anim_set_var(&a_label, label);  // 设置动画对象
    lv_anim_set_exec_cb(&a_label, (lv_anim_exec_xcb_t) set_label_opacity);  // 设置执行回调函数
    lv_anim_set_time(&a_label,1000);  // 动画时间（毫秒）
    lv_anim_set_delay(&a_label, 1000);  // 动画开始前的延迟（毫秒）
    lv_anim_set_values(&a_label, LV_OPA_TRANSP ,LV_OPA_COVER);  // 动画的开始值和结束值（透明度）
    lv_anim_set_playback_time(&a_label, 1000);  // 播放回放时间（可选）
    lv_anim_set_repeat_count(&a_label, LV_ANIM_REPEAT_INFINITE);  // 动画重复次数（无限）
	lv_anim_start(&a_label);
	
	lv_anim_t a_img;
    lv_anim_init(&a_img);
    lv_anim_set_var(&a_img, img);  // 设置动画对象
    lv_anim_set_exec_cb(&a_img, (lv_anim_exec_xcb_t) set_img_opacity);  // 设置执行回调函数
    lv_anim_set_time(&a_img,1000);  // 动画时间（毫秒）
    lv_anim_set_delay(&a_img, 1000);  // 动画开始前的延迟（毫秒）
    lv_anim_set_values(&a_img, LV_OPA_TRANSP,LV_OPA_COVER);  // 动画的开始值和结束值（透明度）
    
    lv_anim_set_repeat_count(&a_img, 0);
	lv_anim_start(&a_img);
	
	btn_src = lv_btn_create(lv_scr_act());
    lv_obj_set_size(btn_src, 480, 320);
    lv_obj_align(btn_src, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_opa(btn_src,LV_OPA_TRANSP,0);
    // ???????????
    lv_obj_add_event_cb(btn_src, btn_src_event_handler, LV_EVENT_CLICKED, NULL);
	
	img_bt = lv_img_create(lv_scr_act());  
	lv_img_set_src(img_bt, &lanyalianjie);  
	lv_obj_set_pos(img_bt,430,10);
	
	img_bt_f = lv_img_create(lv_scr_act());  
	lv_img_set_src(img_bt_f, &lanyafeilianjie);  
	lv_obj_set_pos(img_bt_f,430,10);
	
	lv_obj_add_flag(img_bt, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(img_bt_f, LV_OBJ_FLAG_HIDDEN);
	
	while(1)
	{
		if(Serial_GetRxFlag3()==1){
			if(recive3[3]==1){
			speed_x=((float)(recive3[13]<<8|recive3[14])/10000);
			}
			else if(recive3[3]==2){
			speed_x=-((float)(recive3[13]<<8|recive3[14])/10000);
			}
			if(recive3[4]==1){
			speed_y=((float)(recive3[15]<<8|recive3[16])/10000);
			}
			else if(recive3[4]==2){
			speed_y=-((float)(recive3[15]<<8|recive3[16])/10000);
			}
			
			if(recive3[0]==1){
			pose_x=((float)(recive3[9]<<8|recive3[10])/100);
			}
			else if(recive3[0]==2){
			pose_x=-((float)(recive3[9]<<8|recive3[10])/100);
			}
			if(recive3[1]==1){
			pose_y=((float)(recive3[11]<<8|recive3[12])/100);
			}
			else if(recive3[1]==2){
			pose_y=-((float)(recive3[11]<<8|recive3[12])/100);
			}
			
			odom=((recive3[6]<<8|recive3[5])/32768.0)*180;
			if(odom>180){
				odom=(odom-180)-180;
			}
			else{
				odom=180-(180-odom);
			}
			sprintf(buf_3_4, " Angle: %.4f", odom);
			lv_label_set_text(label_3_4, buf_3_4);
			
			sprintf(buf_3_5, " speed_x: %.4f", speed_x);
			lv_label_set_text(label_3_5, buf_3_5);
			
			sprintf(buf_3_6, " speed_y: %.4f", speed_y);
			lv_label_set_text(label_3_6, buf_3_6);
			
			sprintf(buf_3_7, " pose_x: %.2f", pose_x);
			lv_label_set_text(label_3_7, buf_3_7);
			
			sprintf(buf_3_8, " pose_y: %.2f", pose_y);
			lv_label_set_text(label_3_8, buf_3_8);
			
		
		}
		if(odom!=0){
			lv_obj_clear_flag(img_bt, LV_OBJ_FLAG_HIDDEN);
			lv_obj_add_flag(img_bt_f, LV_OBJ_FLAG_HIDDEN);
		}
		else{
			lv_obj_add_flag(img_bt, LV_OBJ_FLAG_HIDDEN);
			lv_obj_clear_flag(img_bt_f, LV_OBJ_FLAG_HIDDEN);
		}
		if(flag_pkg==2){
			
			if(count>1000&&count<3000){
			lv_obj_set_style_bg_color(dot_2_1,lv_color_hex(0x00BFFF), 0);
			lv_obj_set_style_bg_color(dot_2_2, lv_color_black(), 0); // 设置背景颜色
			lv_obj_set_style_bg_color(dot_2_3, lv_color_black(), 0); // 设置背景颜色
			lv_obj_set_style_bg_color(dot_2_4, lv_color_black(), 0); // 设置背景颜色
			lv_obj_clear_flag(img_2_1, LV_OBJ_FLAG_HIDDEN);
			lv_obj_add_flag(img_2_2, LV_OBJ_FLAG_HIDDEN);
			lv_obj_add_flag(img_2_3, LV_OBJ_FLAG_HIDDEN);
			lv_obj_add_flag(img_2_4, LV_OBJ_FLAG_HIDDEN);
			lv_obj_clear_flag(label_2_7, LV_OBJ_FLAG_HIDDEN);
			lv_obj_add_flag(label_2_8, LV_OBJ_FLAG_HIDDEN);
			lv_obj_add_flag(label_2_9, LV_OBJ_FLAG_HIDDEN);
			lv_obj_add_flag(label_2_10, LV_OBJ_FLAG_HIDDEN);
				}
			else if(count>3000&&count<6000){
			lv_obj_set_style_bg_color(dot_2_2,lv_color_hex(0x00BFFF), 0);
			lv_obj_set_style_bg_color(dot_2_1, lv_color_black(), 0); // 设置背景颜色
			lv_obj_set_style_bg_color(dot_2_3, lv_color_black(), 0); // 设置背景颜色
			lv_obj_set_style_bg_color(dot_2_4, lv_color_black(), 0); // 设置背景颜色
			lv_obj_add_flag(img_2_1, LV_OBJ_FLAG_HIDDEN);
			lv_obj_clear_flag(img_2_2, LV_OBJ_FLAG_HIDDEN);
			lv_obj_add_flag(img_2_3, LV_OBJ_FLAG_HIDDEN);
			lv_obj_add_flag(img_2_4, LV_OBJ_FLAG_HIDDEN);
			lv_obj_add_flag(label_2_7, LV_OBJ_FLAG_HIDDEN);
			lv_obj_clear_flag(label_2_8, LV_OBJ_FLAG_HIDDEN);
			lv_obj_add_flag(label_2_9, LV_OBJ_FLAG_HIDDEN);
			lv_obj_add_flag(label_2_10, LV_OBJ_FLAG_HIDDEN);
			}
			else if(count>6000&&count<9000){
			lv_obj_set_style_bg_color(dot_2_3,lv_color_hex(0x00BFFF), 0);
			lv_obj_set_style_bg_color(dot_2_2, lv_color_black(), 0); // 设置背景颜色
			lv_obj_set_style_bg_color(dot_2_1, lv_color_black(), 0); // 设置背景颜色
			lv_obj_set_style_bg_color(dot_2_4, lv_color_black(), 0); // 设置背景颜色
			lv_obj_add_flag(img_2_1, LV_OBJ_FLAG_HIDDEN);
			lv_obj_add_flag(img_2_2, LV_OBJ_FLAG_HIDDEN);
			lv_obj_clear_flag(img_2_3, LV_OBJ_FLAG_HIDDEN);
			lv_obj_add_flag(img_2_4, LV_OBJ_FLAG_HIDDEN);
			lv_obj_add_flag(label_2_7, LV_OBJ_FLAG_HIDDEN);
			lv_obj_add_flag(label_2_8, LV_OBJ_FLAG_HIDDEN);
			lv_obj_clear_flag(label_2_9, LV_OBJ_FLAG_HIDDEN);
			lv_obj_add_flag(label_2_10, LV_OBJ_FLAG_HIDDEN);
			}
			else if(count>9000&&count<12000){
			lv_obj_set_style_bg_color(dot_2_4,lv_color_hex(0x00BFFF), 0);
			lv_obj_set_style_bg_color(dot_2_2, lv_color_black(), 0); // 设置背景颜色
			lv_obj_set_style_bg_color(dot_2_3, lv_color_black(), 0); // 设置背景颜色
			lv_obj_set_style_bg_color(dot_2_1, lv_color_black(), 0); // 设置背景颜色
			lv_obj_add_flag(img_2_1, LV_OBJ_FLAG_HIDDEN);
			lv_obj_add_flag(img_2_2, LV_OBJ_FLAG_HIDDEN);
			lv_obj_add_flag(img_2_3, LV_OBJ_FLAG_HIDDEN);
			lv_obj_clear_flag(img_2_4, LV_OBJ_FLAG_HIDDEN);
			lv_obj_add_flag(label_2_7, LV_OBJ_FLAG_HIDDEN);
			lv_obj_add_flag(label_2_8, LV_OBJ_FLAG_HIDDEN);
			lv_obj_add_flag(label_2_9, LV_OBJ_FLAG_HIDDEN);
			lv_obj_clear_flag(label_2_10, LV_OBJ_FLAG_HIDDEN);
			
			}
			if(count>12000)count=0;
		}
		lv_task_handler();
		delay_ms(5);
	}

}
