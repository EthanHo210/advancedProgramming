#pragma once

#include "User.h"
#include "Member.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include "TimeBank.h"

class Admin : public User
{
public:
    Admin();
    Admin(std::string username, std::string password);

    void resetPassword(std::string username);
};
