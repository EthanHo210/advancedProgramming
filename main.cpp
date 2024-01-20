#include <iostream>
#include "include/Admin.h"
#include "include/Guest.h"
#include "include/Member.h"
#include "include/Request.h"
#include "include/TimeBank.h"
#include "include/User.h"
#include <cstdlib>

int main(int argc, char const *argv[])
{

    std::string session = "";

    std::cout << "EEET2482/COSC2082 ASSIGNMENT\n"
              << "\"TIME BANK\" APPLICATION\n"
              << "Instructor: Mr. Tran Duc Linh\n"
              << "Group: Group 05\n"
              << "s3970254, Tran Tuan Bao\n"
              << "s3978724, Nguyen Ich Kiet\n"
              << "s3978965, Ho Anh Khoa\n"
              << "s3752578, Nguyen Quoc Hung\n"
              << "Welcome to Time Bank:\n";

    while (session.empty())
    {
        session = TimeBank::login();
    }

    int memberChoice;

    do
    {
        std::cout << "\nMain menu:\n"
                  << "0. Exit\n"
                  << "1. View Information\n"
                  << "2. ...\n"
                  << "Enter your choice: ";
        std::cin >> memberChoice;
        switch (memberChoice)
        {
        case 0:
            std::cout << "Exiting.\n";
            return 0;
        default:
            std::cout << "Invalid choice.\n";
            break;
        }
    } while (memberChoice != 0);

    return 0;
}
