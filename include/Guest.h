#pragma once

#include "User.h"

class Guest : public User
{
public:
    Guest(std::string &username, std::string &password);

    std::string getUserName();

    std::string getPassWord();

private:
};
