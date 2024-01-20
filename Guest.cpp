#include "include/Guest.h"
#include <fstream>

Guest::Guest(std::string username, std::string password) : User(username, password)
{
    std::string path = "data/account/" + username + ".dat";

    // Check if the username exists in database
    std::ifstream checkFile(path, std::ios::out);
    if (checkFile.is_open())
    {
        checkFile.close();
        throw std::runtime_error("This username already exists.");
    }
    else
    {
        // Store in the file
        std::ofstream dataFile(path, std::ios::out);

        dataFile << username << "\n";
        dataFile << password << "\n";
        std::cout << "Account registered successfully.\n";

        dataFile.close();
    }
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
};

Member Guest::registerAsMember()
{
    Member newMember(username, password);

    return newMember;
}