#include "include/Member.h"
#include <vector>
#include <fstream>

using std::string, std::vector;

Member::Member(std::string &username, std::string &password,
               std::string &fullName, std::string &phoneNumber, std::string &email,
               std::string &address, int creditPoints)
    : User(username, password), fullName(fullName), phoneNumber(phoneNumber),
      email(email), address(address), isSupporting(false) {}

Member::Member(std::string &username, std::string &password)
    : User(username, password), fullName(""), phoneNumber(""),
      email(""), address(""), isSupporting(false) {}

// SHOW THE ENTIRE MEMBERS FILE
void Member::showAllInfo(string name){
  string temp;
  std::ifstream dataFile;
  dataFile.open(name, std::ios::in); // read
  if (!dataFile.is_open())
  {
    std::cout << "Fail to create/open file \n";
  }
  std::cout << " Here are the list of members: \n";
  while (getline(dataFile, temp))
  {
    std::cout << temp << "\n";
  }
  dataFile.close();
}

// CLEAR ALL THE FILE CONTENT
void Member::clearMember(std::string name)
{
  std::ofstream dataFile;
  dataFile.open(name, std::ios::out);
  dataFile << "";
  dataFile.close();
}

// WRITE TO FILE
bool Member::saveMember(std::string name)
{
  std::ofstream dataFile;
  dataFile.open(name, std::ios::in | std::ios::app);
  if (!dataFile.is_open())
  {
    std::cerr << "Fail to create/open file \n";
    return false;
  }
  // Store in the file
  dataFile.seekp(0, std::ios::end); // set the pointer back to end of file
  dataFile.close();
  return true;
}