#include "include/Member.h"
#include <vector>

using std::string, std::vector;

Member::Member(std::string &username, std::string &password,
               std::string &fullName, std::string &phoneNumber, std::string &email,
               std::string &address, int creditPoints)
    : User(username, password), fullName(fullName), phoneNumber(phoneNumber),
      email(email), address(address), isSupporting(false) {}

Member::Member(std::string &username, std::string &password)
    : User(username, password), fullName(""), phoneNumber(""),
      email(""), address(""), isSupporting(false) {}