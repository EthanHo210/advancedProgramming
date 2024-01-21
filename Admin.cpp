#include "include/Admin.h"

Admin::Admin() : User(){};
Admin::Admin(std::string username, std::string password) : User(username, password) {}

void Admin::resetPassword(std::string username)
{
    TimeBank timeBank;
    std::string newPassword;
    std::cout << "Changing password for user: " << username << std::endl;
    std::cout << "Enter the new password: ";
    std::cin >> newPassword;
    std::string path = "data/account/" + username + ".dat";
    int lineNumber = 2;
    changeContentByLine(path, lineNumber, newPassword);
    std::cout << "Password changed successfully for user: " << username << std::endl;
}
