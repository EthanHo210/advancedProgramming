#include <iostream>
#include "include/Admin.h"
#include "include/Guest.h"
#include "include/Member.h"
#include "include/Request.h"
#include "include/TimeBank.h"
#include "include/User.h"
#include "include/Time.h"
#include <cstdlib> 

int main(int argc, char const *argv[]) {
    int userType;

    Member newMember ("","","Hung","","","", 0, "");
    Member secondMember ("","","Long","","","", 0, "");
    Member thirdMember ("","","Hieu","","","", 0, "");
    Member fourthMember ("","","Ha","","","", 0, "");
    newMember.book("suck cock", "2:00", "7:00", secondMember.getname());
    newMember.book("suck cock", "2:00", "7:00", thirdMember.getname());
    newMember.book("suck cock", "2:00", "7:00", fourthMember.getname());
    
    std::cout << "EEET2482/COSC2082 ASSIGNMENT\n" <<
                 "\"TIME BANK\" APPLICATION\n" <<
                 "Instructor: Mr. Tran Duc Linh\n" <<
                 "Group: Group 05\n" <<
                 "s3970254, Tran Tuan Bao\n" <<
                 "s3978724, Nguyen Ich Kiet\n" <<
                 "s3978965, Ho Anh Khoa\n" <<
                 "s3752578, Nguyen Quoc Hung\n" <<
                 "Welcome to Time Bank:\n" <<
                 "Use the app as:  1. Guest -  2. Member  -  3. Admin\n" <<
                 "Enter your choice: ";

    std::cin >> userType;
    std::string username;
    std::string password;

    switch (userType)
    {
    case 1: {
        std::cout << "Are you new here?\n" <<
                     "--Register as member--\n" <<
                     "Username: ";
        std::cin >> username;

        std::cout << "Password: ";
        std::cin >> password;

        Member newMember(username, password);
        newMember.displayInfo();

        std::cout << "Account registered successfully.\n" <<
                     "Returning to main menu\n";
        break;             
    }

    case 2: {
    std::cout << "Logging in as a member.\n" <<
                 "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;    

    int memberChoice;
    do {
        std::cout << "\nThis is your menu:\n" <<
                     "0. Exit\n" <<
                     "1. View Information\n" <<
                     "2. ...\n" <<
                     "Enter your choice: ";
        std::cin >> memberChoice;
        switch (memberChoice) {
            case 0:
                std::cout << "Returning to the main menu.\n";
                break;
            default:
                std::cout << "Invalid choice. Returning to the main menu.\n";
                break;
        }
        } while (memberChoice != 0);
    break;
    }

    case 3: {
        std::cout << "Logging in as admin.\n" <<
                     "Enter username: ";
            std::cin >> username;
        std::cout << "Enter password: ";
            std::cin >> password;   
         break;
    }
    
    default:
         std::cout << "Invalid choice. Returning to main menu.\n";
    }
}    


