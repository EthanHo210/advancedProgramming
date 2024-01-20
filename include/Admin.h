#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "Member.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>

class Admin: public User {
public:
    //Constructor
    Admin(std::string &username, std::string &password);

    //Function to change data of a user
    void changeInfo(Member member);

    void resetPassword(Member member);

    void changeInfo(User user);

    void resetPassword(User user);
};

class Member;

class TimeBank {
private:
    static const int initialEntryFee;

public:
    void saveAllData(const std::vector<Member>& members);
    std::vector<Member> loadAllData();
};

class User {
private:
    std::string ID;
    std::string username;
    std::string password;

public:
    void viewMember(const Member& member);
};

class Admin {
public:
    void changeInfo(std::vector<Member>& members, TimeBank& timeBank);
};

class NonMember {
public:
    Member registerMember();
    void viewSupporters(const std::vector<Member>& supporters);

private:
    bool memberIDExists(const std::string& memberId) const;
};

class Member {
private:
    std::string ID;
    std::string username;
    std::string password;
    std::string fullName;
    std::string phoneNumber;
    std::string email;
    std::string address;
    int creditPoints;

public:
    // Public getter functions
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

#endif // ADMIN_H
