#pragma once
#include "include/User.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
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
    std::string getUsername() const { return username; }
    std::string getPassword() const { return password; }
    std::string getFullName() const { return fullName; }
    std::string getPhoneNumber() const { return phoneNumber; }
    std::string getEmail() const { return email; }
    std::string getAddress() const { return address; }
    int getCreditPoints() const { return creditPoints; }

    // Public setter functions
    void setUsername(const std::string& newUsername) { username = newUsername; }
    void setPassword(const std::string& newPassword) { password = newPassword; }
    void setFullName(const std::string& newFullName) { fullName = newFullName; }
    void setPhoneNumber(const std::string& newPhoneNumber) { phoneNumber = newPhoneNumber; }
    void setEmail(const std::string& newEmail) { email = newEmail; }
    void setAddress(const std::string& newAddress) { address = newAddress; }
    void setCreditPoints(int newCreditPoints) { creditPoints = newCreditPoints; }
    static void displayInfo(std::string name);

    void browse(const std::string &searchString);
    void book(Member &supporter);
    void enableSupport();
    void endSession();
    void rate(const Member &ratedMember);
    void static displayInfo(std::string name);

    static bool isValidAddress(std::string address);
    friend class TimeBank;
};