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

Admin::Admin(std::string &username, std::string &password): User(username, password){}



void Admin::changeInfo(std::vector<Member>& members, TimeBank& timeBank) {
    std::cout << "Changing member information...\n";

    // Prompt for member ID
    std::string memberId;
    std::cout << "Enter the member's ID: ";
    std::cin >> memberId;

    // Check if the member exists
    bool memberFound = false;
    Member* foundMember = nullptr;

    for (Member& member : members) {
        if (member.getID() == memberId) {
            memberFound = true;
            foundMember = &member;
            break;
        }
    }

    if (!memberFound) {
        std::cout << "Member not found in the database. Exiting...\n";
        return;
    }

    Member& member = *foundMember;

    int choice;
    do {
        std::cout << "Select the attribute to change:\n";
        std::cout << "1. Username\n";
        std::cout << "2. Password\n";
        std::cout << "3. Full Name\n";
        std::cout << "4. Phone Number\n";
        std::cout << "5. Email\n";
        std::cout << "6. Address\n";
        std::cout << "7. Credit Points\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string newUsername;
            std::cout << "Enter new username: ";
            std::cin >> newUsername;
            member.setUsername(newUsername);
            break;
        }
        case 2: {
            std::string newPassword;
            std::cout << "Enter new password: ";
            std::cin >> newPassword;
            member.setPassword(newPassword);
            break;
        }
        case 3: {
            std::string newFullName;
            std::cout << "Enter new full name: ";
            std::cin.ignore(); // Clear newline character from the buffer
            std::getline(std::cin, newFullName);
            member.setFullName(newFullName);
            break;
        }
        case 4: {
            std::string newPhoneNumber;
            std::cout << "Enter new phone number: ";
            std::cin >> newPhoneNumber;
            member.setPhoneNumber(newPhoneNumber);
            break;
        }
        case 5: {
            std::string newEmail;
            std::cout << "Enter new email: ";
            std::cin >> newEmail;
            member.setEmail(newEmail);
            break;
        }
        case 6: {
            std::string newAddress;
            std::cout << "Enter new address: ";
            std::cin.ignore(); // Clear newline character from the buffer
            std::getline(std::cin, newAddress);
            member.setAddress(newAddress);
            break;
        }
        case 7: {
            int newCreditPoints;
            std::cout << "Enter new credit points: ";
            std::cin >> newCreditPoints;
            member.setCreditPoints(newCreditPoints);
            break;
        }
        case 0:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    timeBank.saveAllData(members);

    std::cout << "Member information changed successfully.\n";
}




void Member::browse(const std::string& city) {
    // Implementation for browsing suitable supporters in the specified city

    // Iterate through supporters and filter based on criteria
    for (const Member& supporter : supportersList) {
        // Check if supporter is in the specified city
        if (supporter.getAddress() == city) {
            // Check if member has enough credit points to book the supporter
            if (creditPoints >= supporter.getConsumingPoints()) {
                // Check if supporter's rating score is acceptable (modify as needed)
                if (supporter.getRatingScore() >= minRatingScore) {
                    // Display supporter information
                    std::cout << "Supporter ID: " << supporter.getID() << "\n";
                    std::cout << "Username: " << supporter.getUsername() << "\n";
                    std::cout << "Rating Score: " << supporter.getRatingScore() << "\n";
                    // Add more supporter information if needed
                    std::cout << "-----------------------------\n";
                }
            }
        }
    }
}





