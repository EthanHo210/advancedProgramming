#include <iostream>
#include "include/Admin.h"
#include "include/Member.h"
#include "include/Request.h"
#include "include/TimeBank.h"
#include "include/User.h"
#include "include/Time.h"
#include "include/Score.h"
#include <cstdlib>

int main(int argc, char const *argv[])
{
    // Score score = Score::getScores("data/system/Score.dat");
    // std::cout << score.getAvgScore();
    TimeBank system;

    system.loadAllData();

    std::cout << "EEET2482/COSC2082 ASSIGNMENT\n"
              << "\"TIME BANK\" APPLICATION\n"
              << "Instructor: Mr. Tran Duc Linh\n"
              << "Group: Group 05\n"
              << "s3970254, Tran Tuan Bao\n"
              << "s3978724, Nguyen Ich Kiet\n"
              << "s3978965, Ho Anh Khoa\n"
              << "s3752578, Nguyen Quoc Hung\n"
              << "Welcome to Time Bank:\n";

    system.login();

    if (!system.getSession().empty())
    {
        std::string sessionUser = system.getSession();

        // Main menu
        system.main_menu();
    }

    return 0;
}
