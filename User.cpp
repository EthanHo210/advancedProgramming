#include <iostream>
#include "include/Admin.h"
#include "include/Guest.h"
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

void User::displayNames()
{
    for (std::string name : nameList)
    {
        std::cout << name;
    }
}

void User::viewMember(const Member& member) {
    std::cout << "Viewing member information...\n";
    std::cout << "ID: " << member.getID() << std::endl;
    std::cout << "Username: " << member.getUsername() << std::endl;
    std::cout << "Password: " << member.getPassword() << std::endl;
    std::cout << "Full Name: " << member.getFullName() << std::endl;
    std::cout << "Phone Number: " << member.getPhoneNumber() << std::endl;
    std::cout << "Email: " << member.getEmail() << std::endl;
    std::cout << "Address: " << member.getAddress() << std::endl;
    std::cout << "Credit Points: " << member.getCreditPoints() << std::endl;
}