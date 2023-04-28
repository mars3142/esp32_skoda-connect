#include "main.h"

#include <WiFi.h>
#include <skoda_connect.h>

#include "connection.h"
#include "secrets.h"
#include "ui.h"
#include "gfx/lv_setup.h"
#include "gui/time_widget.h"

SkodaConnect skodaConnect(SKODA_EMAIL, SKODA_PASSWORD);

void onWiFiGotIP(WiFiEvent_t event)
{
  updateLocalTime();

  time_widget_dispose();
  time_widget_init();

  WiFi.removeEvent(onWiFiGotIP);
}

void setup()
{
  Serial.begin(115200);

  WiFi.onEvent(onWiFiGotIP, ARDUINO_EVENT_WIFI_STA_GOT_IP);

  xTaskCreate(
      initWiFiTask,   /* Task function. */
      "WiFi Connect", /* String with name of task. */
      10000,          /* Stack size in bytes. */
      NULL,           /* Parameter passed as input of the task */
      1,              /* Priority of the task. */
      NULL            /* Task handle. */
  );

  lv_begin();
  ui_init();
}

void loop()
{
  lv_handler();
}
