#include "include/Member.h"
#include "include/Time.h"
#include "include/Request.h"
#include <vector>
#include <fstream>

using std::cin;
using std::cout;
using std::string;

Member::Member(std::string username, std::string password,
               std::string fullName = "", std::string phoneNumber = "", std::string email = "",
               std::string address = "", int creditPoints = 20, bool isSupporting = false, vector<std::string> blockList = {}, std::string skill = "", double requiredHostScore = 0)
    : User(username, password), fullName(fullName), phoneNumber(phoneNumber),
      email(email), address(address), isSupporting(isSupporting), creditPoints(creditPoints), blockList(blockList), skill(skill), requiredHostScore(requiredHostScore)
{
}

void Member::book(string skill, string start_Time, string end_Time, string bookedPerson)
{
  // Implement book functionality
  Time time_Object;
  time_Object.startTime = start_Time;
  time_Object.endTime = end_Time;
  Request requested(this->fullName, bookedPerson, time_Object, skill);
}

void Member::enableSupport()
{
  // Implement enableSupport functionality
  string filename;
  string mainFile;
  filename = "data/skill/" + this->username + ".dat";
  mainFile = "data/account/" + this->username + ".dat";
  string pointsConsume;
  string minHost;
  int minHostscore;

  // set status = true
  isSupporting = true;

  // input skill
  cout << "Please input your skill:\n";
  std::getline(cin >> std::ws, skill);

  // input point/hour
  cout << "What is your consuming point/hour:\n";
  cin >> pointsConsume; // save to skill file

  std::stringstream newData;
  newData << skill << pointsConsume;

  appendFile(filename, newData);

  // input min rating score
  setRequiredHostScore();
}

void Member::disableSupport()
{
  isSupporting = false;
}

void Member::registerMember(std::string username, std::string password)
{
  std::string fullName;
  std::string phoneNumber;
  std::string email;
  std::string address;
  std::string skill;

  // Check if the username exists in database
  std::string path = "data/account/" + username + ".dat";
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
    std::cout << "\nPlease enter the following fields:\n";

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
  }

  Member newMember(username, password, fullName, phoneNumber, email, address, 20, false, {}, skill, 0);

  // Store data in the files with the username
  std::ofstream dataFile(path, std::ios::out);

  dataFile << username << "\n"
           << password << "\n"
           << fullName << "\n"
           << phoneNumber << "\n"
           << email << "\n"
           << address << "\n"
           << 20 << "\n"
           << "false"
           << "\n"
           << skill << "\n"
           << 0 << "\n";

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

bool Member::isValidAddress(std::string address)
{
  // Convert the address to lowercase for case-insensitive comparison
  std::string lowercaseAddress = address;
  std::transform(lowercaseAddress.begin(), lowercaseAddress.end(), lowercaseAddress.begin(), ::tolower);

  // Check if the address contains "ha noi" or "sai gon"
  return (lowercaseAddress.find("ha noi") != std::string::npos || lowercaseAddress.find("sai gon") != std::string::npos);
}

Member Member::getMember(std::string username)
{
  std::string path = "data/account/" + username + ".dat";

  std::vector<std::string> dataLines = readFile(path);

  std::string password = dataLines[1];
  std::string fullName = dataLines[2];
  std::string phoneNumber = dataLines[3];
  std::string email = dataLines[4];
  std::string address = dataLines[5];
  int creditPoints = std::stoi(dataLines[6]);
  bool isSupporting = (dataLines[7] == "true");
  std::vector<std::string> blockList = Member::extractBlockList(dataLines[8]);
  std::string skill = dataLines[9];
  double requiredHostScore = std::stod(dataLines[10]);

  Member member(username, password, fullName, phoneNumber, email, address, creditPoints, isSupporting, blockList, skill, requiredHostScore);

  return member;
}

std::vector<std::string> Member::extractBlockList(std::string data)
{
  if (data.empty())
  {
    return {}; // Return an empty vector if the line is empty
  }

  std::vector<std::string> result;
  std::istringstream stream(data);
  std::string token;

  while (std::getline(stream, token, ';'))
  {
    result.push_back(token);
  }

  return result;
}

void Member::displayInfo()
{
  std::cout << "Username: " << username << "\n";
  std::cout << "Full Name: " << fullName << "\n";
  std::cout << "Phone Number: " << phoneNumber << "\n";
  std::cout << "Email: " << email << "\n";
  std::cout << "Address: " << address << "\n";
}

void Member::displayAllInfo()
{
  std::string blockedUsers = "";
  for (std::string user : blockList)
  {
    blockedUsers += user + ';';
  }
  blockedUsers.pop_back();

  std::cout << "Username: " << username << "\n"
            << "Password: " << password << "\n"
            << "Full Name: " << fullName << "\n"
            << "Phone number: " << phoneNumber << "\n"
            << "Email Address: " << email << "\n"
            << "Home Address: " << address << "\n"
            << "Remaining Credits: " << creditPoints << "\n"
            << "Is supporting: " << (isSupporting ? "true" : "false") << "\n"
            << "Users blocked: " << blockedUsers << "\n"
            << "Skill: " << skill << "\n"
            << "Required Host Score: " << requiredHostScore << "\n";
}

bool Member::verifyLogin(std::string username, std::string password)
{
  if (!isUsernameExist(username))
  {
    std::cerr << "This username does not exist.\n";
    return false;
  }

  std::string path = "data/account/" + username + ".dat";
  std::ifstream dataFile(path);

  if (!dataFile.is_open())
  {
    std::cerr << "Error opening user file\n"
              << std::endl;
    return false; // Return false if the file cannot be opened
  }

  std::string temp;
  std::getline(dataFile, temp);
  std::getline(dataFile, temp);

  if (temp == password)
  {
    return true;
  }

  std::cerr << "Invalid password.\n";
  return false;
}

/*void Member::processRequest(Request& request, bool accept) {
    if (accept) {
        request.setAccepted();
        rejectOtherRequests(request.getHost().getUsername());
    } else {
        request.setRejected();
    }
}

void Member::rejectOtherRequests(const std::string& username) {
    // for (Request& otherRequest : requestsList) {
    //     if (otherRequest.getHost().getUsername() == username) {
    //         otherRequest.setRejected();
    //     }
    // }
}*/

void Member::blockMember(std::string username)
{
  if (isMemberBlocked(username))
  {
    std::cout << "You have successfully blocked this member." << std::endl;
    return;
  }
  blockList.push_back(username);
  std::string path = "data/account/" + this->username + ".dat";
  appendContentByLine(path, 9, username);
}

bool Member::isMemberBlocked(std::string username)
{
  return std::find(blockList.begin(), blockList.end(), username) != blockList.end();
}

/*if (!Member::isMemberBlocked()) {
        Member::displayInfo();
    } else {
        std::cout << "Access Denied. You have been blocked by this member.\n";
    } */

std::vector<std::string> Member::browseAllSupporters(std::string city)
{
  std::ifstream systemFile("data/system/TimeBank.dat");

  std::vector<std::string> fileNames;

  std::string line;
  while (std::getline(systemFile, line))
  {
    fileNames.push_back(line);
  }
}

void Member::browse(int city, int creditPoint, int hostscore, std::string name)
{ // ho chi minh & ha noi
  // city false = hcm, true = hn
  // browse city base on address of each person
  const std::string folderPath = "data/account/" + name + ".dat";
  bool hanoi = false;
  bool hochiminh = false;
  string hostRateScore;   // wanted host score of each supporters
  string hostScoreSingle; // current host score of Host
  string supportCreditPoints;
  string hostCreditPoints;
  string name;
  int hostScore;
  int supportScore;
  int supportCredit;
  int hostCredit;
  bool flag = false;

  if (city == 1) // ha noi
  {
    cout << "Here's some supporter might be perfect for you: \n";
    // file traverse
    for (const auto &entry : std::filesystem::directory_iterator(folderPath))
    {
      if (entry.is_regular_file())
      {
        // search for ha noi city in the address
        hanoi = searchContentAtLine(entry.path(), 5, "ha noi");
        if (hanoi)
        {
          // get the host score & supporter score
          hostRateScore = showContentAtLine(entry.path(), 11);
          supportScore = std::stoi(hostRateScore);
          hostScoreSingle = showContentAtLine("data/score/host/" + this->fullName + ".dat", 1);
          hostScore = std::stoi(hostScoreSingle);
          // get the host credit points & supporter credit points
          name = showContentAtLine(entry.path(), 1);
          supportCreditPoints = showContentAtLine("data/skill/" + name + ".dat", 2);
          supportCredit = std::stoi(supportCreditPoints);
          hostCreditPoints = showContentAtLine("data/account/" + this->fullName + ".dat", 7);
          hostCredit = std::stoi(hostCreditPoints);

          if (hostScore > supportScore && hostCredit > supportCredit)
          {
            flag = true;
            showContentAtLine(entry.path(), 1);
            showContentAtLine(entry.path(), 11);
            cout << "\n";
          }
        }
      }
    }
    if (!flag)
    {
      cout << "Currently there's maybe no one at Ha Noi is avaiable. \n";
    }
  }
  else if (city == 2) // sai gon
  {
    cout << "Here's some supporter might be perfect for you: \n";
    // file traverse
    for (const auto &entry : std::filesystem::directory_iterator(folderPath))
    {

      if (entry.is_regular_file())
      {
        // search for ha noi city in the address
        hochiminh = searchContentAtLine(entry.path(), 5, "sai gon");
        if (hochiminh)
        {
          // get the host score & supporter score
          hostRateScore = showContentAtLine(entry.path(), 11);
          supportScore = std::stoi(hostRateScore);
          hostScoreSingle = showContentAtLine("data/score/host/" + this->fullName + ".dat", 1);
          hostScore = std::stoi(hostScoreSingle);
          // get the host credit points & supporter credit points
          name = showContentAtLine(entry.path(), 1);
          supportCreditPoints = showContentAtLine("data/skill/" + name + ".dat", 2);
          supportCredit = std::stoi(supportCreditPoints);
          hostCreditPoints = showContentAtLine("data/account/" + this->fullName + ".dat", 7);
          hostCredit = std::stoi(hostCreditPoints);

          if (hostScore > supportScore && hostCredit > supportCredit)
          {
            // show people in hcm city
            flag = true;
            cout << showContentAtLine(entry.path(), 1) << "\n";
            cout << showContentAtLine(entry.path(), 10) << "\n";
            cout << "\n";
          }
        }
      }
    }
    if (!flag)
    {
      cout << "Currently there's maybe no one at Ho Chi Minh is avaiable. \n";
    }
  }
}

void Member::setRequiredHostScore()
{
  double newScore;

  while (true)
  {
    std::cout << "\nSetting required host score:\n"
              << "Input a score between 0-5 (enter 0 to disable min host score): ";
    std::cin >> newScore;

    if (newScore < 0 || newScore > 5)
    {
      std::cerr << "Invalid input.\n";
    }
    else
    {
      break;
    }
  }

  requiredHostScore = newScore;

  std::string path = "data/account/" + username + ".dat";

  std::string newData = std::to_string(newScore);
  changeContentByLine(path, 11, newData);

  std::cout << "Upated successfully.\n";
}