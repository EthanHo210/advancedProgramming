#include "include/Member.h"
#include <vector>
#include <fstream>

Member::Member(std::string username, std::string password,
               std::string fullName = "", std::string phoneNumber = "", std::string email = "",
               std::string address = "", int creditPoints = 20, bool isSupporting = false, vector<std::string> blockList = {}, std::string skill = "", double requiredHostScore = 0)
    : User(username, password), fullName(fullName), phoneNumber(phoneNumber),
      email(email), address(address), isSupporting(isSupporting), creditPoints(creditPoints), blockList(blockList), skill(skill), requiredHostScore(requiredHostScore)
{
  std::string path = "data/account/" + username + ".dat";

  // Check if the username exists in database
  std::ifstream checkFile(path, std::ios::out);
  if (checkFile.is_open())
  {
    checkFile.close();
    throw std::runtime_error("This username already exists.");
  }
  else
  {
    // Store in the file with the username
    std::ofstream dataFile(path, std::ios::out);

    dataFile << username << "\n"
             << password << "\n"
             << fullName << "\n"
             << phoneNumber << "\n"
             << email << "\n"
             << address << "\n"
             << creditPoints << "\n"
             << isSupporting << "\n";
    for (std::string name : blockList)
    {
      dataFile << name << ";";
    }
    dataFile << skill << "\n"
             << requiredHostScore << "\n";

    std::cout << "Account registered successfully.\n";

    std::ofstream systemFile("data/system/TimeBank.dat", std::ios::app);

    if (systemFile.is_open())
    {
      systemFile << username << "\n";
      std::cout << "Username added to database.\n";
    }
    else
    {
      throw std::runtime_error("System file is missing!\n");
    }

    checkFile.close();
    dataFile.close();
    systemFile.close();
  }
}

void Member::registereMember()
{
  Member newMember(std::string username, std::string password);
  std::string path = "data/account/" + username + ".dat";

  // Check if the username exists in database
  std::ifstream checkFile(path, std::ios::out);
  if (checkFile.is_open())
  {
    checkFile.close();
    throw std::runtime_error("This username already exists.");
  }
  else
  {
    // Store in the file with the username
    std::ofstream dataFile(path, std::ios::out);

    dataFile << username << "\n";
    dataFile << password << "\n";
    std::cout << "Account registered successfully.\n";

    std::ofstream systemFile("data/system/TimeBank.dat", std::ios::app);

    if (systemFile.is_open())
    {
      systemFile << username << "\n";
      std::cout << "Username added to database.\n";
    }
    else
    {
      throw std::runtime_error("System file is missing!\n");
    }

    checkFile.close();
    dataFile.close();
    systemFile.close();
  }
}