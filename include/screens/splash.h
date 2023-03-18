#pragma once

#include <Arduino.h>
#include <lvgl.h>

class SplashScreen
{
private:
    static void calendar_event_cb(lv_event_t *e)
    {
        lv_calendar_date_t date;
        date = {2023, 03, 16};

        auto calendar = lv_event_get_target(e);
        // lv_calendar_get_pressed_date(calendar, &date);
        lv_calendar_set_today_date(calendar, date.year, date.month, date.day);
        lv_calendar_set_showed_date(calendar, date.year, date.month);
    }

public:
    void init()
    {
        auto calendar = lv_calendar_create(lv_scr_act());
        lv_obj_set_size(calendar, 200, 250);
        lv_obj_align(calendar, LV_ALIGN_CENTER, 0, 0);
        lv_calendar_set_today_date(calendar, 2023, 3, 16);
        lv_calendar_set_showed_date(calendar, 2023, 3);
        lv_calendar_header_dropdown_create(calendar);
        lv_obj_add_event_cb(calendar, calendar_event_cb, LV_EVENT_VALUE_CHANGED, NULL);
    }
};
