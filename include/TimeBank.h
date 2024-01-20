#pragma once
#include "Member.h"
#include "User.h"
#include "Member.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>

class TimeBank {
private:
    static const int initialEntryFee;

public:
    TimeBank();
    void saveAllData(const std::vector<Member>& members);
    std::vector<Member> loadAllData();
};