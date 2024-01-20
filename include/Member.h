#pragma once

#include "User.h"
#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

class Member : public User
{
private:
    std::string fullName;
    std::string phoneNumber;
    std::string email;
    std::string address;
    int creditPoints;
    bool isSupporting;
    std::vector<std::string> blockList;
    std::string skill;
    double requiredHostScore;

public:
    // Constructor
    Member(std::string username, std::string password,
           std::string fullName, std::string phoneNumber, std::string email,
           std::string address, int creditPoints, bool isSupporting, vector<std::string> blockList, std::string skill, double requiredHostScore);

    // Register member
    static void registerMember(std::string username, std::string password);

    // Implementation of the displayInfo function
    void displayInfo() override;
    // Other member functions for Member class
    void browse(std::string &criteria)
    {
        // Implement browse functionality
    }

    void book(Member &member)
    {
        // Implement book functionality
    }

    void enableSupport()
    {
        // Implement enableSupport functionality
    }

    void endSession()
    {
        // Implement endSession functionality
    }

    void rate(Member &member)
    {
        // Implement rate functionality
    }

    static bool isValidAddress(std::string address);
};