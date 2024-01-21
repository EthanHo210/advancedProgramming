#include "include/TimeBank.h"

TimeBank::TimeBank() : session(""){};

void TimeBank::saveAllData(){
    // Add code to save data to a file or database
    // std::cout << "Saving all data..." << std::endl;
};

void TimeBank::loadAllData()
{
    std::fstream dataFile("data/system/TimeBank.dat", std::ios::app);
    dataFile << "";
    // std::string temp;
    // while (std::getline(dataFile, temp))
    // {
    //     allUser.push_back(temp);
    // }

    // for (std::string name : allUser)
    // {
    //     std::cout << name;
    // }
}

// SHOW THE ENTIRE FILE
void logFile(std::string path)
{
    std::string temp;
    std::ifstream dataFile;
    dataFile.open(path, std::ios::in); // read
    if (!dataFile.is_open())
    {
        std::cout << "Fail to create/open file \n";
    }

    while (getline(dataFile, temp))
    {
        std::cout << temp << "\n";
    }
    dataFile.close();
}

// RETURN THE ENTIRE FILE
std::vector<std::string> readFile(std::string path)
{
    std::vector<std::string> file;
    std::string temp;
    std::ifstream dataFile;

    dataFile.open(path, std::ios::in); // read
    if (!dataFile.is_open())
    {
        std::cout << "Fail to create/open file \n";
    }

    while (getline(dataFile, temp))
    {
        file.push_back(temp);
    }
    dataFile.close();

    return file;
}

// CLEAR ALL THE FILE CONTENT
void clearFile(std::string path)
{
    std::ofstream dataFile;
    dataFile.open(path, std::ios::out);
    dataFile << "";
    dataFile.close();
}

// WRITE TO FILE
bool saveFile(std::string path, std::stringstream &data)
{
    std::ofstream dataFile;
    dataFile.open(path, std::ios::in);
    if (!dataFile.is_open())
    {
        std::cerr << "Fail to create/open file \n";
        return false;
    }
    else
    {
        std::string line;
        while (std::getline(data, line))
        {
            dataFile << line << '\n';
        }
    }

    dataFile.close();
    return true;
}

// APPEND LINES TO FILE
void appendFile(std::string path, std::stringstream &data)
{
    std::ofstream dataFile;
    dataFile.open(path, std::ios::app);
    if (!dataFile.is_open())
    {
        std::cerr << "Fail to create/open file \n";
    }
    else
    {
        std::string line;
        while (std::getline(data, line))
        {
            dataFile << line << '\n';
        }
    }

    dataFile.close();
}

// CHANGE FILE CONTENT BY LINE
bool changeContentByLine(std::string path, int lineNumber, std::string newContent)
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
bool appendContentByLine(std::string path, int lineNumber, std::string newContent)
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
    lines[lineNumber - 1] += (newContent + ";");
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
bool changeFileContent(std::string path, std::string search, std::string input, char ch) // string to search and newcontent as input
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

// SEARCH FILE CONTENT AT CERTAIN POSITION BY LINE
bool searchContentAtLine(string filename, int lineNumber, string targetContent)
{
    bool status = false;
    std::ifstream inputFile(filename);
    if (!inputFile.is_open())
    {
        std::cerr << "Failed to open the file." << std::endl;
        return status;
    }
    string line = "";
    int currentLine = 0;
    // Read the file until reaching the target line
    while (currentLine < lineNumber && std::getline(inputFile, line))
    {
        currentLine++;
    }
    // Check if the target line was found
    if (currentLine == lineNumber)
    {
        std::transform(line.begin(), line.end(), line.begin(), ::tolower);

        // Search for the target content in the line
        if (line.find(targetContent) != std::string::npos)
        {
            inputFile.close();
            status = true;
        }
    }

    inputFile.close();
    return status;
}

// SHOW FILE CONTENT BY LINE
std::string showContentAtLine(std::string filename, int lineNumber)
{
    std::ifstream inputFile(filename);
    if (!inputFile.is_open())
    {
        std::cerr << "Failed to open the file." << std::endl;
    }
    std::string line = "";
    int currentLine = 0;
    // Read the file until reaching the target line
    while (currentLine < lineNumber && std::getline(inputFile, line))
    {
        currentLine++;
    }
    if (currentLine == lineNumber)
    {
        // Search for the target content in the line
        // cout << line << "\n";
        return line;
    }
    inputFile.close();
    return line;
}

void TimeBank::login()
{
    int userType = 1;
    std::string username;
    std::string password;

    while (userType != 0)
    {
        std::cout << "\nUse the app as:\n0. Exit \n1. Guest\n2. Member\n3. Admin\n"
                  << "Enter your choice: ";

        std::cin >> userType;

        switch (userType)
        {
        case 1:
        {
            int option;

            while (option != 0)
            {

                std::cout << "\nAre you new here?\n"
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
                        std::cout << "\n--- Register as member ---\n"
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
            std::cout << "\nLogging in as a member.\n"
                      << "Enter username: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, username);
            std::cout << "Enter password: ";
            std::cin >> password;

            if (Member::verifyLogin(username, password))
            {
                std::cout << "Logged in successfully.\n";
                session = username;
                userType = 0;
            }
            else
            {
                std::cout << "Failed to login.\n";
            };

            break;
        }

        case 3:
        {
            std::cout << "\nLogging in as admin.\n";
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
            std::cout << "\nExiting...";
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

// Check if username exist for login function
bool isUsernameExist(std::string username)
{
    std::ifstream file("data/system/TimeBank.dat");

    if (!file.is_open())
    {
        std::cerr << "Error opening system file: " << std::endl;
        return false; // Return false if the file cannot be opened
    }

    std::string line;
    while (std::getline(file, line))
    {
        if (line == username)
        {
            file.close();
            return true; // Username found
        }
    }

    file.close();
    return false; // Username not found
}

// Main menu
void TimeBank::main_menu()
{
    int memberChoice;
    Member currUser = Member::getMember(session);

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
                TimeBank::search_supporter();
                break;
            default:
                std::cout << "Invalid choice.\n";
                break;
            }
        } while (memberChoice != 0);
    }
    else if (session == "admin")
    {
        Admin admin;
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
            {
                std::string username;
                std::cout << "Enter username to change password: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, username);

                admin.resetPassword(username);
            }
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
                      << "3. Book user"
                      << "Enter your choice: ";
            std::cin >> memberChoice;
            switch (memberChoice)
            {
            case 0:
                std::cout << "Exiting.\n";
                break;
            case 1:
                TimeBank::search_supporter();
                break;
            case 2:
                TimeBank::manage_account();
                break;
            case 3:
            {
                std::string name;
                std::string skill;
                std::string startTime;
                std::string endTime;

                std::cout << "BOOKING\n";
                std::cout << "Enter username you want to book: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, name);

                std::cout << "Enter their skill: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, skill);

                std::cout << "Enter start-time: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, startTime);

                std::cout << "Enter end-time: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, endTime);

                currUser.book(skill, startTime, endTime, name);
                break;
            }
            default:
                std::cout << "Invalid choice.\n";
                break;
            }
        } while (memberChoice != 0);
    }
};

void TimeBank::manage_account()
{
    std::string path = "data/account/" + session + ".dat";
    std::ifstream userData(path);
    Member currUser = Member::getMember(session);

    int option;
    while (option != 0)
    {
        std::cout << "\nMANAGE ACCOUNT\n";
        std::cout << "0. Return\n"
                  << "1. View your information\n"
                  << "2. Manage supporting status\n"
                  << "3. Check your on-going requests\n"
                  << "4. Check pending requests from other users\n"
                  << "5. Set minimum host score\n"
                  << "6. Block user\n"
                  << "Enter your choice: ";

        std::cin >> option;
        switch (option)
        {
        case 0:
            std::cout << "\nReturning to main menu.\n";
            break;
        case 1:
            TimeBank::view_account();
            break;
        case 2:
        {
            if (currUser.supporting())
            {
                int option;

                std::cout << "You are supporting. Do you want to stop?\n0. Stop supporting\n1. Continue supporting and return to main menu.";
                std::cin >> option;

                switch (option)
                {
                case 0:
                    currUser.disableSupport();
                    break;
                case 1:
                    break;
                default:
                    std::cout << "Invalid input.";
                    break;
                }
            }
            else
            {
                int option;
                std::cout << "You are not supporting. Enable now?\n0. Start supporting\n1. Return to main menu.";
                std::cin >> option;

                switch (option)
                {
                case 0:
                    currUser.enableSupport();
                    break;
                case 1:
                    break;
                default:
                    std::cout << "Invalid input.";
                    break;
                }
            }
            break;
        case 5:
            TimeBank::set_min_host_score();
            break;
        default:
            std::cerr << "Invalid input.";
            break;
        }
        }
    }
}

void TimeBank::view_account()
{
    std::cout << "\nYour Account Information:\n";

    Member currUser = Member::getMember(session);
    currUser.displayAllInfo();
}

void TimeBank::set_min_host_score()
{
    Member currUser = Member::getMember(session);
    currUser.setRequiredHostScore();
}

void TimeBank::search_supporter()
{
    int option;
    bool result;
    std::vector<std::string> userList = Member::getAllMembers();

    Member currUser;

    if (session != "guest")
    {
        currUser = Member::getMember(session);
    }

    while (option != 0)
    {
        result = false;
        std::cout << "\n--- View supporters ---\n"
                  << "0. Return\n"
                  << "1. All\n"
                  << "2. Ha noi\n"
                  << "3. Sai gon\n"
                  << "Enter your choice: ";
        std::cin >> option;

        switch (option)
        {
        case 0:
            break;
        case 1:
        case 2:
        case 3:
            for (std::string name : userList)
            {
                if (session == "guest")
                {
                    result = result || Member::viewSupporter(option, name);
                }
                else
                {
                    result = result || currUser.searchSupporter(option, name);
                }
            }
            if (!result)
            {
                std::cout << "There is no matched supporters.\n";
            }

            break;
        default:
            std::cout << "Invalid input.\n";
            break;
        }
    }
}