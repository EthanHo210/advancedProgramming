#include <iostream>
#include "include/Admin.h"
#include "include/Guest.h"
#include "include/Member.h"
#include "include/Request.h"
#include "include/TimeBank.h"
#include "include/User.h"

int main(int argc, char const *argv[])
{
    std::cout << "Welcome to Time Bank:" << std::endl;
    std::cout << "--Register as member--\nUsername: ";

    std::string name;
    std::cin >> name;

    std::cout << "Password: ";
    std::string password;
    std::cin >> password;

    Member newMember(name, password);
    newMember.displayInfo();

    return 0;
}
