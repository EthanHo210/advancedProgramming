#include <iostream>
#include "User.h"

User::User(std::string& username, std::string& password)
    :username(username), password(password) {
    nameList.push_back(username);
    }

std::string User::getUsername() {
    return username;
}

std::string User::getPassword() {
    return password;
}

