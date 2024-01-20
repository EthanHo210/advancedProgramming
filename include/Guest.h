#pragma once

#include "User.h"

class Guest : public User
{
public:
    Guest(std::string username, std::string password);

    void displayInfo();

    std::string getUserName();

    std::string getPassWord();

private:
};
