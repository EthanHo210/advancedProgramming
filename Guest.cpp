#include "include/Guest.h"

Guest::Guest(std::string username, std::string password) : User(username, password) {}

std::string Guest::getUserName(){
    return username;
};

std::string Guest::getPassWord(){
    return password;
};

Member Guest::registerAsMember(){
    Member newMember(username, password);

    return newMember;
}