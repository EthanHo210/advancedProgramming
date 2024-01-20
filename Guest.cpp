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


bool Guest::memberIDExists(const std::string& memberId) const {
    // Implementation to check if the member ID already exists in the system
    // You may need to read from a file or query a database
    // For this example, let's assume a simple check based on file existence
    std::ifstream file(memberId + ".txt");
    return file.good();
}

   