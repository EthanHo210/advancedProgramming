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

Guest::Guest(std::string &username, std::string &password) : User(username, password) {}

std::string Guest::getUserName(){
    return this->username;
};

std::string Guest::getPassWord(){
    return this->password;
};

Member Guest::registerAsMember(){
    Member newMember(this->username, this->password);

    return newMember;
}

bool Guest::memberIDExists(const std::string& memberId) const {
    // Implementation to check if the member ID already exists in the system
    // You may need to read from a file or query a database
    // For this example, let's assume a simple check based on file existence
    std::ifstream file(memberId + ".txt");
    return file.good();
}

Member Guest::registerAsMember() {
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
