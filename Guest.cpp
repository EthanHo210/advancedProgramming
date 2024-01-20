#include <iostream>
#include "include/Guest.h"
#include <fstream>

Guest::Guest(std::string username, std::string password) : User(username, password)
{
}

void Guest::displayInfo()
{
    std::cout << username << password << std::endl;
}

std::string Guest::getUserName()
{
    return username;
};

std::string Guest::getPassWord()
{
    return password;
}
