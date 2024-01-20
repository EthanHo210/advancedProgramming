#pragma once
#include "Member.h"
#include "User.h"
#include "Member.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <limits>

class TimeBank
{
private:
    std::string session;

public:
    TimeBank();

    // Session
    void setSession(std::string username)
    {
        session = username;
    }

    std::string getSession()
    {
        return session;
    }

    // Member function to save all data
    void saveAllData();

    // Member function to load all data
    void loadAllData();

    // SHOW THE ENTIRE FILE
    static void logFile(std::string name);

    // RETURN THE ENTIRE FILE
    static std::vector<std::string> readFile(std::string name);

    // CLEAR ALL THE FILE CONTENT
    static void clearFile(std::string name);

    // WRITE TO FILE
    static bool saveFile(std::string name);

    // CHANGE FILE CONTENT BY LINE
    static bool changeContentByLine(std::string filename, int lineNumber, std::string newContent);

    // APPEND FILE CONTENT BY LINE
    static bool appendContentByLine(std::string filename, int lineNumber, std::string newContent);

    // CHANGE THE FILE CONTENT IN DESIRE POSITION (MATCHED SEARCH STRING)
    static bool changeFileContent(std::string name, std::string search, std::string input, char ch);

    // Log in interface
    void login();

    // Check if username exist for login function
    static bool isUsernameExist(std::string username);

    // Main menu interface
    void main_menu();

    // Account managing interface
    void manage_account();

    // View account information interface
    void view_account();

    // Set required host score interface
    void set_min_host_score();

    friend class Member;
};