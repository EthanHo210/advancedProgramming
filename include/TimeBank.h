#pragma once
#include "Member.h"
#include "User.h"
#include "Member.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#include <sstream>

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

    // Log in interface
    void login();

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

// Check if username exist for login function
bool isUsernameExist(std::string username);

// SHOW THE ENTIRE FILE
void logFile(std::string name);

// RETURN THE ENTIRE FILE
std::vector<std::string> readFile(std::string name);

// CLEAR ALL THE FILE CONTENT
void clearFile(std::string name);

// WRITE TO FILE
bool saveFile(std::string name);

// APPEND TO FILE
void appendFile(std::string path, std::stringstream &data);

// CHANGE FILE CONTENT BY LINE
bool changeContentByLine(std::string filename, int lineNumber, std::string newContent);

// APPEND FILE CONTENT BY LINE
bool appendContentByLine(std::string filename, int lineNumber, std::string newContent);

// CHANGE THE FILE CONTENT IN DESIRE POSITION (MATCHED SEARCH STRING)
bool changeFileContent(std::string name, std::string search, std::string input, char ch);

// SEARCH FILE CONTENT AT CERTAIN POSITION BY LINE
bool searchContentAtLine(string filename, int lineNumber, string targetContent);

// SHOW FILE CONTENT BY LINE
string showContentAtLine(string filename, int lineNumber);