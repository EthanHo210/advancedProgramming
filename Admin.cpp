#include <iostream>
#include "include/Admin.h"
#include "include/User.h"
#include <cstdlib> 
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>

Admin::Admin(std::string &username, std::string &password)
    : User(username, password) {
    // Additional admin-specific initialization if needed
}

void Admin::changeInfo(User &user) {
    // Implement your logic for changing admin information
    std::cout << "Enter new username for admin: ";
    std::cin >> user.getUsername();  // Use the getter function
    std::cout << "Enter new password for admin: ";
    std::cin >> user.getPassword();  // Use the getter function
}

void Admin::resetPassword(User &user) {
    // Implement your logic for resetting the password of a user
    std::cout << "Enter new password for user " << user.getUsername() << ": ";
    std::cin >> user.getPassword();  // Use the getter function
}