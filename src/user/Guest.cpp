#include "Guest.h"

Guest::Guest(std::string &username, std::string &password) : User(username, password) {}

std::string Guest::getUserName(){
    return this->username;
};

std::string Guest::getPassWord(){
    return this->password;
};

Member Guest::registerAsMember(){
    Member newMember(this->username, this->password);

    return newMember;
}