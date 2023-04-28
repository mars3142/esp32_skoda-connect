#include "connection.h"

#include <Arduino.h>
#include <esp32-hal-log.h>
#include <WiFi.h>
#include <ESPmDNS.h>

#include "secrets.h"

bool init_mdns_done = false;
bool connection_ready = false;

void initWiFiTask(void *params)
{
    WiFi.disconnect();
    WiFi.mode(WIFI_STA);
    if (WiFi.status() != WL_CONNECTED)
    {
        WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
        log_d("Trying to connect to %s", WIFI_SSID);

        // Wait for connection
        unsigned long start = millis();
        while (millis() - start <= 15000)
        {
            if (WiFi.status() == WL_CONNECTED)
            {
                connection_ready = true;
                break;
            }

            delay(500);
        }

        if (WiFi.status() != WL_CONNECTED)
        {
            log_w("Restarting because of no wifi connection");
            delay(2000);
            ESP.restart();
        }
    }

    if (!MDNS.begin("skodaconnect"))
    {
        log_e("Error setting up MDNS responder!");
        vTaskDelay(10000 / portTICK_PERIOD_MS);
        ESP.restart();
    }

    vTaskDelete(NULL);
}

void updateLocalTime()
{
    configTime(0, 0, "pool.ntp.org", "time.nis.gov");

    // change timezone to Europe/Berlin
    // found eg https://github.com/nayarsystems/posix_tz_db/blob/master/zones.json
    setenv("TZ", "CET-1CEST,M3.5.0,M10.5.0/3", 1);
    tzset();

    struct tm timeinfo;
    if (!getLocalTime(&timeinfo))
    {
        log_e("Failed to obtain time");
        return;
    }
}
