
#include "lvgl.h"
#include "touch.h"

void lvgl_task()
{
    tp_dev.scan();
    lv_timer_handler();
}

void lvgl_test()
{
    // 按钮
	lv_obj_t *myBtn = lv_btn_create(lv_scr_act());                               // 创建按钮; 父对象：当前活动屏幕
	lv_obj_set_pos(myBtn, 10, 10);                                               // 设置坐标
	lv_obj_set_size(myBtn, 120, 50);                                             // 设置大小

	// 按钮上的文本
	lv_obj_t *label_btn = lv_label_create(myBtn);                                // 创建文本标签，父对象：上面的btn按钮
	lv_obj_align(label_btn, LV_ALIGN_CENTER, 0, 0);                              // 对齐于：父对�?
	lv_label_set_text(label_btn, "Test");                                        // 设置标签的文�?

	// 独立的标�?
	lv_obj_t *myLabel = lv_label_create(lv_scr_act());                           // 创建文本标签; 父对象：当前活动屏幕
	lv_label_set_text(myLabel, "Hello world!");                                  // 设置标签的文�?
	lv_obj_align(myLabel, LV_ALIGN_CENTER, 0, 0);                                // 对齐于：父对�?
	lv_obj_align_to(myBtn, myLabel, LV_ALIGN_OUT_TOP_MID, 0, -20);               // 对齐于：某对�?

}
