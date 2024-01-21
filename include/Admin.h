#define ADMIN_H

#include "User.h"
#include "Member.h"

class Admin : public User
{
public:
    // Constructor
    Admin(std::string username, std::string password);

    // Function to change data of a user
    void changeInfo(Member member);
    void resetPassword(Member member);
};
