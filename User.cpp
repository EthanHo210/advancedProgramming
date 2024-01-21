#include <iostream>
#include "include/Admin.h"
#include "include/Member.h"
#include "include/Request.h"
#include "include/TimeBank.h"
#include "include/User.h"
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>

std::vector<std::string> User::nameList;

User::User() {}
User::User(std::string username, std::string password)
    : username(username), password(password)
{
    nameList.push_back(username);
}

std::string User::getUsername()
{
    return username;
}

std::string User::getPassword()
{
    return password;
}