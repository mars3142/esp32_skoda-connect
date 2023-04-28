#pragma once

#include <string>

class SkodaConnect
{
public:
    SkodaConnect(const char *username, const char *password);
    bool connect();

private:
    const char *username;
    const char *password;
};
