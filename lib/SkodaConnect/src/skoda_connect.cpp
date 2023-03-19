#include "skoda_connect.h"

#include <WiFiClientSecure.h>

SkodaConnect::SkodaConnect(const char *username, const char *password)
{
    this->username = username;
    this->password = password;
}
