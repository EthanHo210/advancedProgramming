#ifndef ADMIN_H
#define ADMIN_H

#include "include/User.h"
#include "include/Member.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>

class Admin: public User {
public:
    //Constructor
    Admin(std::string &username, std::string &password);

    //Function to change data of a user
    void changeInfo(std::vector<Member>& members, TimeBank& timeBank);

    void resetPassword(Member member);

    void changeInfo(User user);

    void resetPassword(User user);
};




#endif // ADMIN_H
