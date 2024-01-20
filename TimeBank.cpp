#include "include/TimeBank.h"
#include "include/Guest.h"
#include <limits>

TimeBank::TimeBank() : initialEntryFee(20){};

void TimeBank::saveAllData()
{
    // Add code to save data to a file or database
    std::cout << "Saving all data..." << std::endl;
};

void TimeBank::loadAllData()
{
    // Add code to load data from a file or database
    std::cout << "Loading all data..." << std::endl;
}

std::string TimeBank::login()
{
    int userType;

    std::cout << "Use the app as:  1. Guest -  2. Member  -  3. Admin\n"
              << "Enter your choice: ";

    std::cin >> userType;
    std::string username;
    std::string password;

    switch (userType)
    {
    case 1:
    {
        int option;

        while (option != 0)
        {

            std::cout << "Are you new here?\n"
                      << "1. Register\n"
                      << "2. View supporters\n";

            if (!(std::cin >> option))
            {
                std::cerr << "Error: Invalid input";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            switch (option)
            {
            case 1:
                while (true)
                {
                    std::cout << "-- Register as member --\n"
                              << "Username: ";
                    std::cin >> username;

                    std::cout << "Password: ";
                    std::cin >> password;
                    try
                    {
                        Guest newGuest(username, password);
                        newGuest.displayInfo();

                        break;
                    }
                    catch (const std::runtime_error &e)
                    {
                        std::cerr << "Error: " << e.what() << std::endl;
                    }
                }
                break;
            case 2:
                return "guest";
                break;
            default:
                std::cerr << "Error: Invalid input\n";
                break;
            }
        }

        return username;
    }
    case 2:
    {
        std::cout << "Logging in as a member.\n"
                  << "Enter username: ";
        std::cin >> username;
        std::cout << "Enter password: ";
        std::cin >> password;

        return username;
    }

    case 3:
    {
        std::cout << "Logging in as admin.\n"
                  << "Enter username: ";
        std::cin >> username;
        std::cout << "Enter password: ";
        std::cin >> password;
        return username;
    }

    default:
        std::cout << "Invalid choice. Returning to main menu.\n";
        return "";
    }
}