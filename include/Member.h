#pragma once
#include "Time.h"
#include "Request.h"
#include "User.h"
#include "TimeBank.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

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
    static bool verifyLogin(std::string username, std::string password);

    // Get skill pph
    int getSkillPoints();

    // Implementation of the displayInfo function
    std::string getUsername();
    std::string getPassword() const { return password; }
    std::string getFullName() const { return fullName; }
    std::string getPhoneNumber() const { return phoneNumber; }
    std::string getEmail() const { return email; }
    std::string getAddress() const { return address; }
    int getCreditPoints() const { return creditPoints; }

    // Public setter functions
    void setUsername(const std::string &newUsername) { username = newUsername; }
    void setPassword(const std::string &newPassword) { password = newPassword; }
    void setFullName(const std::string &newFullName) { fullName = newFullName; }
    void setPhoneNumber(const std::string &newPhoneNumber) { phoneNumber = newPhoneNumber; }
    void setEmail(const std::string &newEmail) { email = newEmail; }
    void setAddress(const std::string &newAddress) { address = newAddress; }
    void setCreditPoints(int newCreditPoints) { creditPoints = newCreditPoints; }

    void searchSupporter(int city, std::string name);
    void static viewAllSupporter(int city, std::string name);

    void book(Member &supporter);

    void enableSupport();
    void disableSupport();

    void endSession();
    void rate(const Member &ratedMember);

    void displayAllInfo();
    void displayInfo();
    static bool isValidAddress(std::string address);

    // void processRequest(Request &request, bool accept);
    void rejectOtherRequests(const std::string &memberUsername);
    void blockMember(std::string username);
    bool isMemberBlocked(std::string username);

    static std::vector<std::string> getAllMembers();
    static Member getMember(std::string username);
    static std::vector<std::string> extractBlockList(std::string data);

    void setRequiredHostScore();

    void book(string skill, string start_Time, string end_Time, string bookedPerson);

    double getRequiredHostScore();

    friend class TimeBank;
};
