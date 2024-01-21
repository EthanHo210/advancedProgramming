#define ADMIN_H

#include "User.h"
#include "Member.h"

class Admin : public User
{
public:
    Admin(std::string username, std::string password);

    void resetPassword(const std::string username);
};
