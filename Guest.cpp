#include <iostream>
#include "include/Guest.h"

Guest::Guest(std::string &username, std::string &password) : User(username, password) {}

std::string Guest::getUserName()
{
    return this->username;
};

std::string Guest::getPassWord()
{
    return this->password;
};
