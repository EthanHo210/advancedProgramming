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
using std::string, std::vector;

Member::Member(std::string &username, std::string &password,
               std::string &fullName, std::string &phoneNumber, std::string &email,
               std::string &address, int creditPoints)
    : User(username, password), fullName(fullName), phoneNumber(phoneNumber),
      email(email), address(address), isSupporting(false) {}

Member::Member(std::string &username, std::string &password)
    : User(username, password), fullName(""), phoneNumber(""),
      email(""), address(""), isSupporting(false) {}

void Member::displayInformation() const {
    std::cout << "Member Information:\n";
    std::cout << "ID: " << getID() << "\n";
    std::cout << "Username: " << getUsername() << "\n";
    std::cout << "Password: " << getPassword() << "\n";
    std::cout << "Full Name: " << getFullName() << "\n";
    std::cout << "Phone Number: " << getPhoneNumber() << "\n";
    std::cout << "Email: " << getEmail() << "\n";
    std::cout << "Address: " << getAddress() << "\n";
    std::cout << "Credit Points: " << getCreditPoints() << "\n";
}

void Member::book(Member& supporter) {
    // Implementation for booking a supporter
    std::cout << "Booking supporter: " << supporter.getUsername() << std::endl;
    // Add your logic here
}

void Member::enableSupport() {
    // Implementation for enabling support
    std::cout << "Support enabled\n";
    // Add your logic here
}

void Member::endSession() {
    // Implementation for ending the session
    std::cout << "Session ended\n";
    // Add your logic here
}

void Member::rate(const Member& ratedMember) {
    // Implementation for rating a member
    std::cout << "Rating member: " << ratedMember.getUsername() << std::endl;

    // Get the rating from the user (you can add more validation logic)
    int skillRating, supporterRating;
    std::cout << "Enter skill rating (1-5): ";
    std::cin >> skillRating;

    std::cout << "Enter overall supporter rating (1-5): ";
    std::cin >> supporterRating;

    // Create Score objects for skill and supporter ratings
    SkillScore skillScore(skillRating);
    SupporterScore supporterScore(supporterRating);

    // Update the rated member's scores
    ratedMember.skillScore = skillScore;
    ratedMember.supporterScore = supporterScore;

    std::cout << "Rating successful!\n";
}
