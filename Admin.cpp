#include <iostream>
#include "include/Admin.h"

Admin::Admin(std::string username, std::string password) : User(username, password) {}

void Admin::changeInfo(Member member)
{
}

void Admin::resetPassword(Member member)
{
}