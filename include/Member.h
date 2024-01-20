#pragma once

#include "User.h"
#include <iostream>
#include <vector>
#include <string>

class Member : public User {
private:
    std::string fullName;
    std::string phoneNumber;
    std::string email;
    std::string address;
    int creditPoints;
    bool isSupporting;
    std::vector<Member *> blockList;
public:
    // Constructor
    Member(std::string &username, std::string &password,
           std::string &fullName, std::string &phoneNumber, std::string &email,
           std::string &address, int creditPoints);

    Member(std::string &username, std::string &password);

    // Implementation of the displayInfo function
    void displayInfo() override
    {
        std::cout << "--Member Info--" << std::endl;
        std::cout << "Username: " << getUsername() << std::endl;
        std::cout << "Password: " << getPassword() << std::endl;
        std::cout << "Full Name: " << fullName << std::endl;
        std::cout << "Phone Number: " << phoneNumber << std::endl;
        std::cout << "Email: " << email << std::endl;
        std::cout << "Address: " << address << std::endl;
    }

    // Other member functions for Member class
    void browse(std::string& criteria) {
        // Implement browse functionality
    }

    void book(Member& member) {
        // Implement book functionality
    }

    void enableSupport() {
        // Implement enableSupport functionality
    }

    void endSession() {
        // Implement endSession functionality
    }

    void rate(Member& member) {
        // Implement rate functionality
    }
};