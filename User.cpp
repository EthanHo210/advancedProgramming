#include <iostream>
#include "include/User.h"

std::vector<std::string> User::nameList;

User::User(std::string username, std::string password)
    :username(username), password(password) {
    nameList.push_back(username);
    }

std::string User::getUsername() {
    return username;
}

std::string User::getPassword() {
    return password;
}

void User::displayNames()
{
    for (std::string name : nameList)
    {
        std::cout << name;
    }
}