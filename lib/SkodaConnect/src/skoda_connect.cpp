#include "skoda_connect.h"

#include "skoda_oauth.h"

SkodaConnect::SkodaConnect(const char *username, const char *password)
{
    this->username = username;
    this->password = password;
}

bool SkodaConnect::connect()
{
}
