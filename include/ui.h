#include <lvgl.h>

void _ui_screen_change(lv_obj_t *target, lv_scr_load_anim_t fademode, int spd, int delay, bool auto_del = false)
{
    lv_scr_load_anim(target, fademode, spd, delay, auto_del);
}

void ui_event_SplashScreen(lv_event_t *e);
lv_obj_t *ui_SplashScreen;
lv_obj_t *ui_SplashSpinner;
void ui_event_VehicleSelection(lv_event_t *e);
lv_obj_t *ui_VehicleSelection;
lv_obj_t *ui_Calendar;

void ui_SplashScreen_screen_init(void)
{
    ui_SplashScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_SplashScreen, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_SplashSpinner = lv_spinner_create(ui_SplashScreen, 1000, 90);
    lv_obj_set_width(ui_SplashSpinner, 80);
    lv_obj_set_height(ui_SplashSpinner, 80);
    lv_obj_set_align(ui_SplashSpinner, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_SplashSpinner, LV_OBJ_FLAG_CLICKABLE); /// Flags

    lv_obj_add_event_cb(ui_SplashScreen, ui_event_SplashScreen, LV_EVENT_ALL, NULL);
}

void ui_VehicleSelection_screen_init(void);
void ui_event_SplashScreen(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        ui_VehicleSelection_screen_init();
        _ui_screen_change(ui_VehicleSelection, LV_SCR_LOAD_ANIM_OVER_TOP, 500, 0, true);
    }
}
void ui_event_VehicleSelection(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        ui_SplashScreen_screen_init();
        _ui_screen_change(ui_SplashScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, true);
    }
}
void ui_VehicleSelection_screen_init(void)
{
    ui_VehicleSelection = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_VehicleSelection, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    time_t now;
    struct tm timeinfo;
    time(&now);
    localtime_r(&now, &timeinfo);

    ui_Calendar = lv_calendar_create(ui_VehicleSelection);
    lv_calendar_set_today_date(ui_Calendar, timeinfo.tm_year + 1900, timeinfo.tm_mon + 1, timeinfo.tm_mday);
    lv_calendar_set_showed_date(ui_Calendar, timeinfo.tm_year + 1900, timeinfo.tm_mon + 1);

    lv_obj_t *ui_Calendar_header = lv_calendar_header_arrow_create(ui_Calendar);
    lv_obj_set_width(ui_Calendar, 230);
    lv_obj_set_height(ui_Calendar, 240);
    lv_obj_set_align(ui_Calendar, LV_ALIGN_CENTER);

    lv_obj_add_event_cb(ui_VehicleSelection, ui_event_VehicleSelection, LV_EVENT_ALL, NULL);
}

void ui_init(void)
{
    ui_SplashScreen_screen_init();
    lv_disp_load_scr(ui_SplashScreen);
}
