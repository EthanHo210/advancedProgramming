#include "include/Member.h"
#include <vector>
#include <fstream>

Member::Member(std::string username, std::string password,
               std::string fullName, std::string phoneNumber, std::string email,
               std::string address, int creditPoints)
    : User(username, password), fullName(fullName), phoneNumber(phoneNumber),
      email(email), address(address), isSupporting(false) {}

Member::Member(std::string username, std::string password)
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

// CHANGE FILE CONTENT BY LINE
bool Member::changeContentByLine(string filename, int lineNumber, string newContent)
{
  std::ifstream inputFile(filename);
  if (!inputFile.is_open())
  {
    std::cerr << "Error opening file: " << filename << std::endl;
    return false;
  }
  std::vector<std::string> lines;
  std::string line;
  while (std::getline(inputFile, line))
  {
    lines.push_back(line);
  }
  inputFile.close();
  // check if input invalid line
  if (lineNumber < 1 || lineNumber > lines.size())
  {
    std::cerr << "Invalid line number: " << lineNumber << std::endl;
    return false;
  }
  // write to line string
  lines[lineNumber - 1] = newContent;
  // write new content to line
  std::ofstream outputFile(filename);
  if (!outputFile.is_open())
  {
    std::cerr << "Error opening file: " << filename << std::endl;
    return false;
  }
  for (const auto &l : lines)
  {
    outputFile << l << std::endl;
  }
  outputFile.close();
  return true;
}

// CHANGE THE FILE CONTENT IN DESIRE POSITION (MATCHED SEARCH STRING)
bool Member::changeFileContent(string name, string search, string input, char ch) // string to search and newcontent as input
{
  std::vector<std::string> vec_Content;
  string temp;
  string output;
  int count = 0;
  int line = 0;
  search = search + " :";
  std::ifstream dataFile(name);
  // dataFile.open(FILENAME, std::ios::in); // read
  if (!dataFile.is_open())
  {
    std::cout << "Fail to create/open file \n";
    return false;
  }
  // algorithm to find match string
  int j;
  while (getline(dataFile, temp))
  {
    // write all file content to vector
    vec_Content.push_back(temp);
    // count number of lines
    count++;
    int position = temp.find(search);
    if (position != std::string::npos)
    {
      output = temp;
      line = count;
    }
  }
  dataFile.close();
  // change the content in the output string
  int index = 0;
  index = output.find(ch);
  if (index != std::string::npos)
  {
    output = output.substr(0, index + 1) + input + output.substr(index + input.length() + 1);
  }
  vec_Content[line - 1] = output; // write new content to vector
  // write back to the file position
  std::ofstream out_dataFile(name);
  // dataFile.open(FILENAME, std::ios::out); // write
  if (!out_dataFile.is_open())
  {
    std::cerr << "Fail to create/open file \n";
    return false;
  }
  // Rewrite the file with modified content
  for (string &vec : vec_Content)
  {
    out_dataFile << vec << std::endl;
  }
  out_dataFile.close();

  return true;
}

void Member::processRequest(Request& request, bool accept) {
    if (accept) {
        request.setAccepted();
        rejectOtherRequests(request.getHost().getUsername());
    } else {
        request.setRejected();
    }
}

void Member::rejectOtherRequests(const std::string& memberUsername) {
    for (Request& otherRequest : requestsList) {
        if (otherRequest.getHost().getUsername() == memberUsername) {
            otherRequest.setRejected();
        }
    }
}