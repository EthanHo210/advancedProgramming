#ifndef USER_H
#define USER_H
#include <string>
#include <vector>

// Abstract class User
class User
{
protected:
    std::string username;
    std::string password;
    static std::vector<std::string> nameList;

public:
    // Constructor
    User(std::string username, std::string password);

    // Getter for username
    std::string getUsername();

    // Getter for password
    std::string getPassword();
};

#endif // USER_H