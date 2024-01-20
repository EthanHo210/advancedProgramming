#ifndef USER_H
#define USER_H
#include <string> 
#include <vector>

// Abstract class User
class User {
protected:
    std::string username;
    std::string password;
    static std::vector<std::string> nameList;
public:
    // Constructor
    User(std::string username, std::string password);

    // Pure virtual function to make the class abstract
    virtual void displayInfo() = 0;

    static void displayNames();

    // Getter for username
    std::string getUsername() const;

    // Getter for password
    std::string getPassword() const;

    void User::viewMember(const Member& member);
};

#endif // USER_H