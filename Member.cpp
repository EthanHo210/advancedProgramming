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

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

void Member::View() const {
    std::string filename = getUsername() + ".txt"; // Assuming username is unique and used as the filename
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cout << "User does not exist. Please try again.\n";
        return;
    }

    std::cout << "Member Information:\n";

    std::string line;
    if (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::vector<std::string> fields;

        // Split the line into fields
        while (std::getline(iss, line, ',')) {
            fields.push_back(line);
        }

        // Ensure there are at least 8 fields
        if (fields.size() >= 8) {
            std::cout << "Username: " << fields[0] << "\n";
            std::cout << "Full Name: " << fields[2] << "\n";
            std::cout << "Phone Number: " << fields[3] << "\n";
            std::cout << "Email: " << fields[4] << "\n";
            std::cout << "Address: " << fields[5] << "\n";
            std::cout << "Is Supervisor: " << (fields[7] == "1" ? "Yes" : "No") << "\n";
        }
    }

    inputFile.close();
}


void Member::book(Member& supporter) {
    // Implementation for booking a supporter
    std::cout << "Booking supporter: " << supporter.getUsername() << std::endl;
    // Add your logic here
}

void Member::browse(const std::string& city) {
    // Assuming you have a global vector of supporters or some other way to get supporters
    extern std::vector<Member> supportersList;

    // Assuming getConsumingPoints and getRatingScore are member functions of the Member class
    // Replace these with the actual functions you have in your class
    auto getConsumingPoints = [](const Member& supporter) { return supporter.getCreditPoints(); };
    auto getRatingScore = [](const Member& supporter) { /* replace with actual implementation */ return 0; };
    
    // Assuming minRatingScore is a constant or variable defined elsewhere
    int minRatingScore = /* replace with actual value */ 0;

    // Iterate through supporters and filter based on criteria
    for (const Member& supporter : supportersList) {
        // Check if supporter is in the specified city
        if (supporter.getAddress() == city) {
            // Check if member has enough credit points to book the supporter
            if (getCreditPoints() >= getConsumingPoints(supporter)) {
                // Check if supporter's rating score is acceptable (modify as needed)
                if (getRatingScore(supporter) >= minRatingScore) {
                    // Display supporter information
                    std::cout << "Username: " << supporter.getUsername() << "\n";
                    std::cout << "Rating Score: " << getRatingScore(supporter) << "\n";
                    // Add more supporter information if needed
                    std::cout << "-----------------------------\n";
                }
            }
        }
    }
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
    
    SupporterScore supporterScore(supporterRating);

    // Update the rated member's scores
-
    ratedMember.supporterScore = supporterScore;

    std::cout << "Rating successful!\n";
}
