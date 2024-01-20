#include "include/Member.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include <limits>

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
  else if (username == "guest" && username == "admin")
  {
    throw std::runtime_error("This username cannot be used.");
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
    dataFile << "\n"
             << skill << "\n"
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

void Member::registerMember(std::string username, std::string password)
{
  std::string fullName;
  std::string phoneNumber;
  std::string email;
  std::string address;
  std::string skill;

  std::cout << "Please enter the following fields:\n";

  std::cout << "Full name: ";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::getline(std::cin, fullName);

  std::cout << "Phone number: ";
  std::getline(std::cin, phoneNumber);

  std::cout << "Email: ";
  std::getline(std::cin, email);

  do
  {
    std::cout << "Address: ";
    std::getline(std::cin, address);

    if (!isValidAddress(address))
    {
      std::cout << "Invalid address. Please enter an address containing 'Ha Noi' or 'Sai Gon'.\n";
    }
  } while (!isValidAddress(address));

  std::cout << "Your skill: ";
  std::getline(std::cin, skill);

  Member newMember(username, password, fullName, phoneNumber, email, address, 20, false, {}, skill, 0);

  std::string path = "data/account/" + username + ".dat";
}

bool Member::isValidAddress(std::string address)
{
  // Convert the address to lowercase for case-insensitive comparison
  std::string lowercaseAddress = address;
  std::transform(lowercaseAddress.begin(), lowercaseAddress.end(), lowercaseAddress.begin(), ::tolower);

  // Check if the address contains "ha noi" or "sai gon"
  return (lowercaseAddress.find("ha noi") != std::string::npos || lowercaseAddress.find("sai gon") != std::string::npos);
}

void Member::displayInfo()
{
  std::cout << "-- Member Info --" << std::endl;
  std::cout << "Username: " << username << std::endl;
  std::cout << "Password: " << password << std::endl;
  std::cout << "Full Name: " << fullName << std::endl;
  std::cout << "Phone Number: " << phoneNumber << std::endl;
  std::cout << "Email: " << email << std::endl;
  std::cout << "Address: " << address << std::endl;
}