#include <lvgl.h>

lv_obj_t *widget_time;

static void time_widget_update(lv_timer_t *timer)
{
    tm buf;
    auto t = time(nullptr);
    localtime_r(&t, &buf);

    lv_obj_t *label = lv_obj_get_child(widget_time, 0);
    if (buf.tm_year < 2000)
    {
        lv_label_set_text_fmt(label, "");
        return;
    }
    lv_label_set_text_fmt(label, "%04d-%02d-%02d %02d:%02d:%02d", buf.tm_year, buf.tm_mday, buf.tm_mday, buf.tm_hour, buf.tm_min, buf.tm_sec);
}

void time_widget_init()
{
    widget_time = lv_obj_create(lv_layer_top());
    lv_obj_align(widget_time, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_obj_set_width(widget_time, 200);
    lv_obj_set_style_bg_opa(widget_time, LV_OPA_TRANSP, 0);
    lv_obj_set_style_border_opa(widget_time, LV_OPA_TRANSP, 0);

    lv_obj_t *label = lv_label_create(widget_time);
    lv_obj_set_pos(label, -10, -10);

    lv_timer_create(time_widget_update, 1, NULL);
}
