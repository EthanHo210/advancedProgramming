#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "Member.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>

class Admin: public User {
public:
    //Constructor
    Admin(const std::string &username, const std::string &password);

    //Function to change data of a user

    void changeInfo(User &user);

    void resetPassword(User &user);
};

#endif // ADMIN_H
