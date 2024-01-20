#include "include/TimeBank.h"
#include "include/Guest.h"
#include <limits>

TimeBank::TimeBank() : allUser({}), session(""){};

void TimeBank::saveAllData()
{
    // Add code to save data to a file or database
    std::cout << "Saving all data..." << std::endl;
};

void TimeBank::loadAllData()
{
    std::fstream dataFile("data/system/TimeBank.dat");
    std::string temp;
    while (std::getline(dataFile, temp))
    {
        allUser.push_back(temp);
    }

    for (std::string name : allUser)
    {
        std::cout << name;
    }
}

// SHOW THE ENTIRE FILE
void TimeBank::readFile(std::string path)
{
    std::string temp;
    std::ifstream dataFile;
    dataFile.open(path, std::ios::in); // read
    if (!dataFile.is_open())
    {
        std::cout << "Fail to create/open file \n";
    }
    std::cout << "Reading file: \n";
    while (getline(dataFile, temp))
    {
        std::cout << temp << "\n";
    }
    dataFile.close();
}

// CLEAR ALL THE FILE CONTENT
void TimeBank::clearFile(std::string path)
{
    std::ofstream dataFile;
    dataFile.open(path, std::ios::out);
    dataFile << "";
    dataFile.close();
}

// WRITE TO FILE
bool TimeBank::saveFile(std::string path)
{
    std::ofstream dataFile;
    dataFile.open(path, std::ios::in | std::ios::app);
    if (!dataFile.is_open())
    {
        std::cerr << "Fail to create/open file \n";
        return false;
    }
    // Store in the file
    dataFile.seekp(0, std::ios::end); // set the pointer back to end of file
    dataFile.close();
    return true;
}

// CHANGE FILE CONTENT BY LINE
bool TimeBank::changeContentByLine(std::string path, int lineNumber, std::string newContent)
{
    std::ifstream inputFile(path);
    if (!inputFile.is_open())
    {
        std::cerr << "Error opening file: " << path << std::endl;
        return false;
    }
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(inputFile, line))
    {
        lines.push_back(line);
    }
    inputFile.close();
    // check if input invalid line
    if (lineNumber < 0 || lineNumber > lines.size())
    {
        std::cerr << "Invalid line number: " << lineNumber << std::endl;
        return false;
    }
    // write to line string
    lines[lineNumber - 1] = newContent;
    // write new content to line
    std::ofstream outputFile(path);
    if (!outputFile.is_open())
    {
        std::cerr << "Error opening file: " << path << std::endl;
        return false;
    }
    for (std::string line : lines)
    {
        outputFile << line << std::endl;
    }
    outputFile.close();
    return true;
}

// APPEND FILE CONTENT TO LINE
bool TimeBank::appendContentByLine(std::string path, int lineNumber, std::string newContent)
{
    std::ifstream inputFile(path);
    if (!inputFile.is_open())
    {
        std::cerr << "Error opening file: " << path << std::endl;
        return false;
    }
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(inputFile, line))
    {
        lines.push_back(line);
    }
    inputFile.close();
    // check if input invalid line
    if (lineNumber < 0 || lineNumber > lines.size())
    {
        std::cerr << "Invalid line number: " << lineNumber << std::endl;
        return false;
    }
    // write to line string
    lines[lineNumber - 1] += newContent;
    // write new content to line
    std::ofstream outputFile(path);
    if (!outputFile.is_open())
    {
        std::cerr << "Error opening file: " << path << std::endl;
        return false;
    }
    for (std::string line : lines)
    {
        outputFile << line << std::endl;
    }
    outputFile.close();
    return true;
}

// CHANGE THE FILE CONTENT IN DESIRE POSITION (MATCHED SEARCH STRING)
bool TimeBank::changeFileContent(std::string path, std::string search, std::string input, char ch) // string to search and newcontent as input
{
    std::vector<std::string> vec_Content;
    std::string temp;
    std::string output;
    int count = 0;
    int line = 0;
    search = search + " :";
    std::ifstream dataFile(path);
    // dataFile.open(path, std::ios::in); // read
    if (!dataFile.is_open())
    {
        std::cout << "Fail to create/open file \n";
        return false;
    }
    // algorithm to find match string
    int j;
    while (getline(dataFile, temp))
    {
        // write all file content to vector
        vec_Content.push_back(temp);
        // count number of lines
        count++;
        int position = temp.find(search);
        if (position != std::string::npos)
        {
            output = temp;
            line = count;
        }
    }
    dataFile.close();
    // change the content in the output string
    int index = 0;
    index = output.find(ch);
    if (index != std::string::npos)
    {
        output = output.substr(0, index + 1) + input + output.substr(index + input.length() + 1);
    }
    vec_Content[line - 1] = output; // write new content to vector
    // write back to the file position
    std::ofstream out_dataFile(path);
    // dataFile.open(path, std::ios::out); // write
    if (!out_dataFile.is_open())
    {
        std::cerr << "Fail to create/open file \n";
        return false;
    }
    // Rewrite the file with modified content
    for (std::string &vec : vec_Content)
    {
        out_dataFile << vec << std::endl;
    }
    out_dataFile.close();

    return true;
}

void TimeBank::login()
{
    int userType = 1;
    std::string username;
    std::string password;

    while (userType != 0)
    {
        std::cout << "Use the app as:\n0. Exit \n1. Guest\n2. Member\n3. Admin\n"
                  << "Enter your choice: ";

        std::cin >> userType;

        switch (userType)
        {
        case 1:
        {
            int option;

            while (option != 0)
            {

                std::cout << "Are you new here?\n"
                          << "0. Return\n"
                          << "1. Register\n"
                          << "2. Continue as guest\n"
                          << "Your option: ";

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
                        std::cout << "--- Register as member ---\n"
                                  << "Username: ";
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::getline(std::cin, username);
                        if (username != "guest" && username != "admin")
                        {
                            std::cout << "Password: ";
                            std::cin >> password;
                            try
                            {
                                Member::registerMember(username, password);
                                std::string path = "data/account/" + username + ".dat";
                                TimeBank::readFile(path);
                                break;
                            }
                            catch (const std::runtime_error &e)
                            {
                                std::cerr << "Error: " << e.what() << std::endl;
                            }
                        }
                        else
                        {
                            std::cout << "This name cannot be used.";
                        }
                    }
                    option = 0;
                    userType = 0;
                    break;
                case 2:
                    username = "guest";
                    option = 0;
                    userType = 0;
                    break;
                default:
                    std::cerr << "Error: Invalid input\n";
                    break;
                }
            }

            break;
        }
        case 2:
        {
            std::cout << "Logging in as a member.\n"
                      << "Enter username: ";
            std::getline(std::cin, username);
            std::cout << "Enter password: ";
            std::cin >> password;

            break;
        }

        case 3:
        {
            std::cout << "Logging in as admin.\n";
            username = "admin";
            std::cout << "Enter password: ";
            std::cin >> password;
            if (password != "ADMINISTRATOR")
            {
                std::cerr << "Invalid password";
            }
            else
            {
                userType = 0;
            }

            break;
        }
        case 0:
        {
            std::cout << "Exiting...";
            username = "";
            break;
        }

        default:
            std::cout << "Invalid choice.\n";
            break;
        }
    }

    session = username;
}

// Main menu
void TimeBank::main_menu()
{
    int memberChoice;

    if (session == "guest")
    {
        do
        {
            std::cout << "\nMain menu:\n"
                      << "0. Exit\n"
                      << "1. View Supporters\n"
                      << "Enter your choice: ";
            std::cin >> memberChoice;
            switch (memberChoice)
            {
            case 0:
                std::cout << "Exiting...\n";
                break;
            case 1:

                break;
            default:
                std::cout << "Invalid choice.\n";
                break;
            }
        } while (memberChoice != 0);
    }
    else if (session == "admin")
    {
        do
        {
            std::cout << "\nMain menu:\n"
                      << "0. Exit\n"
                      << "1. Manage account\n"
                      << "Enter your choice: ";
            std::cin >> memberChoice;
            switch (memberChoice)
            {
            case 0:
                std::cout << "Exiting.\n";
                break;
            case 1:

                break;
            default:
                std::cout << "Invalid choice.\n";
                break;
            }
        } while (memberChoice != 0);
    }
    else
    {
        do
        {
            std::cout << "\nMain menu:\n"
                      << "0. Exit\n"
                      << "1. View Supporters\n"
                      << "2. Your account\n"
                      << "Enter your choice: ";
            std::cin >> memberChoice;
            switch (memberChoice)
            {
            case 0:
                std::cout << "Exiting.\n";
                break;
            case 1:

                break;
            case 2:

                break;
            default:
                std::cout << "Invalid choice.\n";
                break;
            }
        } while (memberChoice != 0);
    }
};

void TimeBank::view_account()
{
    std::string path = "data/account/" + session + ".dat";
    std::ifstream userData(path);
}
