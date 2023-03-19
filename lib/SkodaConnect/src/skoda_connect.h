#pragma once

#include <string>

class SkodaConnect
{
public:
    SkodaConnect(const char *username, const char *password);

private:
    const char *username;
    const char *password;
};
