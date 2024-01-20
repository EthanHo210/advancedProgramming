#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

class TimeBank {
private:
    static const int initialEntryFee = 20;

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

// Implementations

void TimeBank::saveAllData(const std::vector<Member>& members) {
    std::ofstream file("members.txt");

    for (const Member& member : members) {
        // Write member data to the file
        file << member.getID() << " " << member.getUsername() << " " << member.getPassword() << " "
            << member.getFullName() << " " << member.getPhoneNumber() << " " << member.getEmail() << " "
            << member.getAddress() << " " << member.getCreditPoints() << std::endl;
        // Add additional data if needed
    }

    file.close();
}

std::vector<Member> TimeBank::loadAllData() {
    std::vector<Member> members;
    std::ifstream file("members.txt");

    if (file.is_open()) {
        while (!file.eof()) {
            Member member;
            // Use setter functions to set private attributes
            std::string newID, newUsername, newPassword, newFullName, newPhoneNumber, newEmail, newAddress;
            int newCreditPoints;

            file >> newID >> newUsername >> newPassword
                >> newFullName >> newPhoneNumber >> newEmail
                >> newAddress >> newCreditPoints;

            if (!file.fail()) {
                member.setID(newID);
                member.setUsername(newUsername);
                member.setPassword(newPassword);
                member.setFullName(newFullName);
                member.setPhoneNumber(newPhoneNumber);
                member.setEmail(newEmail);
                member.setAddress(newAddress);
                member.setCreditPoints(newCreditPoints);

                members.push_back(member);
            }
        }
        file.close();
    }

    return members;
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

bool NonMember::memberIDExists(const std::string& memberId) const {
    // Implementation to check if the member ID already exists in the system
    // You may need to read from a file or query a database
    // For this example, let's assume a simple check based on file existence
    std::ifstream file(memberId + ".txt");
    return file.good();
}

Member NonMember::registerMember() {
    std::cout << "Registering a new member...\n";

    Member newMember;

    // Prompt for username and password
    std::string newUsername;
    std::cout << "Enter username: ";
    std::cin >> newUsername;
    newMember.setUsername(newUsername);

    std::string newPassword;
    std::cout << "Enter password: ";
    std::cin >> newPassword;
    newMember.setPassword(newPassword);

    // Prompt for other member information...

    // Check if the generated ID already exists
    std::string generatedID;
    do {
        // Generate a unique ID (you may use a more sophisticated method)
        std::ostringstream oss;
        oss << std::setw(4) << std::setfill('0') << rand() % 10000;
        generatedID = oss.str();

        // Check if the ID already exists
        if (memberIDExists(generatedID)) {
            std::cout << "This ID already has an account. Please try a different one.\n";
        }
        else {
            newMember.setID(generatedID);
        }
    } while (memberIDExists(generatedID));

    // Display the information
    newMember.displayInformation();

    // Save member data to a file
    std::ofstream file(newMember.getID() + ".txt");
    file << newMember.getID() << " " << newMember.getUsername() << " " << newMember.getPassword()
        << " " << newMember.getFullName() << " " << newMember.getPhoneNumber() << " "
        << newMember.getEmail() << " " << newMember.getAddress() << " " << newMember.getCreditPoints();
    // Add additional data if needed

    std::cout << "Registration successful!\n";

    return newMember;
}


void NonMember::viewSupporters(const std::vector<Member>& supporters) {
    std::cout << "Viewing supporters' details...\n";

    for (const Member& supporter : supporters) {
        // Display supporter information (excluding reviews)
        std::cout << "ID: " << supporter.getID() << "\n";
        std::cout << "Username: " << supporter.getUsername() << "\n";
        std::cout << "Full Name: " << supporter.getFullName() << "\n";
        std::cout << "Phone Number: " << supporter.getPhoneNumber() << "\n";
        std::cout << "Email: " << supporter.getEmail() << "\n";
        std::cout << "Address: " << supporter.getAddress() << "\n";
        std::cout << "Credit Points: " << supporter.getCreditPoints() << "\n";
        // Display additional supporter data if needed
        std::cout << "-----------------------------\n";
    }

    // You can add more formatting or options as needed
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



