#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::cin;
using std::cout;

#define FILENAME "hihi"

// CREATE A INNIT FILE WHEN LOGIN TO ACCOUNT
    void innit (string name)
    {
         // create a file for account
        std::ofstream bookFile(name);
        //bookFile.open(name, std::ios::in| std::ios::app);
        bookFile.close();
    }

// SHOW THE ENTIRE MEMBERS FILE
    void show_All_Info()
    {
        string temp;
        std::ifstream dataFile;
        dataFile.open(FILENAME, std::ios::in); // read
        if (!dataFile.is_open()) {
            cout << "Fail to create/open file \n";
        }
        cout << " Here are the list of members: \n";
        while (getline(dataFile, temp))
        {
            cout  << temp << "\n";
        }
        dataFile.close();
    }

// CLEAR ALL THE FILE CONTENT
    void clear()
    {
        std::ofstream dataFile;
        dataFile.open(FILENAME, std::ios::out);
        dataFile << "";
        dataFile.close();
    }

// WRITE TO FILE
    bool save_All_Members(string filename, string name){
        std::ofstream dataFile;
        dataFile.open(filename, std::ios::in| std::ios::app);
        if (!dataFile.is_open()) {
            cout << "Fail to create/open file \n";
            return false;
        }
        //Store in the file
        dataFile  << name << "\n";
        dataFile.seekp(0, std::ios::end); // set the pointer back to end of file
        dataFile.close();
        return true;
    }
// CHANGE FILE CONTENT BY LINE
bool change_Content_By_Line (string& filename, int lineNumber, string newContent) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cout << "Error opening file: " << filename << std::endl;
        return false;
    } 
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(inputFile, line)) {
        lines.push_back(line);
    }
    inputFile.close();
// check if input invalid line
    if (lineNumber < 1 || lineNumber > lines.size()) {
        std::cout << "Invalid line number: " << lineNumber << std::endl;
        return false;
    }
    // write to line string 
    lines[lineNumber - 1] = newContent;
// write new content to line
    std::ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        std::cout << "Error opening file: " << filename << std::endl;
        return false;
    }
    for (const auto& l : lines) {
        outputFile << l << std::endl;
    }
    outputFile.close();
    return true;
}

// READ CONTENT BY LINE
bool read_Content_By_Line (string& filename, int lineNumber) {
    bool statusCheck;
    string readStatus;
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cout << "Error opening file: " << filename << std::endl;
        return false;
    } 
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(inputFile, line)) {
        lines.push_back(line);
    }
    inputFile.close();
// check if input invalid line
    if (lineNumber < 1 || lineNumber > lines.size()) {
        std::cout << "Invalid line number: " << lineNumber << std::endl;
        return false;
    }
    // write to line string 
    readStatus = lines[lineNumber - 1];
    if (readStatus == "true")
    {
        statusCheck = true;
    }
    else{
        statusCheck = false;
    }
    outputFile.close();
    return statusCheck;
}



// CHANGE THE FILE CONTENT IN DESIRE POSITION (MATCHED SEARCH STRING)
void change_FILE_Content (string search, string input, char ch) // string to search and newcontent as input
    {
        std::vector<std::string> vec_Content;
        string temp;
        string output;
        int count = 0;
        int line = 0;
        search = search + " :";
        std::ifstream dataFile(FILENAME);
        //dataFile.open(FILENAME, std::ios::in); // read
        if (!dataFile.is_open()) {
            cout << "Fail to create/open file \n";
            return;
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
            if (position != std::string::npos) {
                output = temp;
                line = count;
            }
        }
        dataFile.close();
        // change the content in the output string
        int index = 0;
        index = output.find(ch);
        if (index != std::string::npos) {
            output = output.substr(0, index + 1) + input + output.substr(index + input.length() + 1);
        } 
        vec_Content[line - 1] = output; // write new content to vector
        // write back to the file position
        std::ofstream out_dataFile (FILENAME);
        //dataFile.open(FILENAME, std::ios::out); // write
        if (!out_dataFile.is_open()) {
            cout << "Fail to create/open file \n";
            return;
        }
        // Rewrite the file with modified content
        for (string &vec : vec_Content)
        {
            out_dataFile << vec << std::endl;
        }
        out_dataFile.close();
    }

//

    