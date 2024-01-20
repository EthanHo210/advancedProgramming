#pragma once

#include "User.h"
#include "Member.h"

class Guest: public User
{
public:
    Guest(std::string username, std::string password);

    Member registerAsMember();

    std::string getUserName();

    std::string getPassWord();
};
