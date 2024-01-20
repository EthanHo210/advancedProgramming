#pragma once

#include <iostream>

class TimeBank
{
private:
    int initialEntryFee;

public:
    // Constructor
    TimeBank();

    // Member function to save all data
    void saveAllData();

    // Member function to load all data
    void loadAllData();

    static std::string login();
};