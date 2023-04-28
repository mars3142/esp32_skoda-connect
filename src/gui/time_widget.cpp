#include "gui/time_widget.h"

#include <string>
#include <time.h>

#include "lv_conf.h"

lv_obj_t *widget_time;
lv_timer_t *timer;

void time_widget_update(lv_timer_t *timer)
{
    lv_obj_t *label = (lv_obj_t *)timer->user_data;

    time_t now;
    struct tm timeinfo;
    time(&now);
    localtime_r(&now, &timeinfo);
    std::string weekday[] = LV_CALENDAR_DEFAULT_DAY_NAMES;
    lv_label_set_text_fmt(label, "%s %02d:%02d:%02d\n%d-%02d-%02d", weekday[timeinfo.tm_wday].c_str(), timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec, timeinfo.tm_year + 1900, timeinfo.tm_mon + 1, timeinfo.tm_mday);
}

void time_widget_init()
{
    if (widget_time != NULL)
    {
        return;
    }

    widget_time = lv_obj_create(lv_layer_top());
    lv_obj_align(widget_time, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_obj_set_width(widget_time, 200);
    lv_obj_set_style_bg_opa(widget_time, LV_OPA_TRANSP, 0);
    lv_obj_set_style_border_opa(widget_time, LV_OPA_TRANSP, 0);

    lv_obj_t *label = lv_label_create(widget_time);
    lv_obj_set_pos(label, -10, -10);

    timer = lv_timer_create(time_widget_update, 1000, (void *)label);
    time_widget_update(timer);
}

void time_widget_dispose()
{
    if (widget_time == NULL)
    {
        return;
    }

    lv_timer_del(timer);
    lv_obj_del(widget_time);
}
