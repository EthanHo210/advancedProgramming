#pragma once
#include "include/User.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>


using std::string, std::vector;

class Member : public User {
private:
    std::string ID;
    string fullName;
    string phoneNumber;
    string email;
    string address;
    int creditPoints;
    bool isSupporting;
    vector<Member *> blockList;
public:
    // Constructor
    Member(string &username, string &password,
           string &fullName, string &phoneNumber, string &email,
           string &address, int creditPoints);

    Member(std::string &username, std::string &password);

    // Implementation of the displayInfo function
    std::string getID() const { return ID; }
    std::string getUsername() const { return username; }
    std::string getPassword() const { return password; }
    std::string getFullName() const { return fullName; }
    std::string getPhoneNumber() const { return phoneNumber; }
    std::string getEmail() const { return email; }
    std::string getAddress() const { return address; }
    int getCreditPoints() const { return creditPoints; }

    // Public setter functions
    void setID(const std::string& newID) { ID = newID; }
    void setUsername(const std::string& newUsername) { username = newUsername; }
    void setPassword(const std::string& newPassword) { password = newPassword; }
    void setFullName(const std::string& newFullName) { fullName = newFullName; }
    void setPhoneNumber(const std::string& newPhoneNumber) { phoneNumber = newPhoneNumber; }
    void setEmail(const std::string& newEmail) { email = newEmail; }
    void setAddress(const std::string& newAddress) { address = newAddress; }
    void setCreditPoints(int newCreditPoints) { creditPoints = newCreditPoints; }

    void browse(const std::string& searchString);
    void book(Member& supporter);
    void enableSupport();
    void endSession();
    void rate(const Member& ratedMember);
    void displayInformation() const;

    friend class TimeBank;
};