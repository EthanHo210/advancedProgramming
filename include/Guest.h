#pragma once

#include "User.h"
#include "Member.h"

class Guest: public User
{
public:
    Guest(std::string username, std::string password);

    void displayInfo();

    Member registerAsMember();

    std::string getUserName();

    std::string getPassWord();
};
