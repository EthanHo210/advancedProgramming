#pragma once

#include "User.h"
#include "Member.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>

class Guest: public User
{
public:
    Guest(std::string &username, std::string &password);

    Member registerAsMember();

    std::string getUserName();

    std::string getPassWord();

private:
    bool memberIDExists(const std::string& memberId) const;
};
