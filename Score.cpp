#include <iostream>
#include <fstream>
#include <sstream>
#include "include/Score.h"

Score::Score(std::vector<std::string> ratings) : ratingList(ratings) {}

double Score::getAvgScore(){
    if (ratingList.empty()) {
        return 0.0;
    }

    double sum = 0.0;
    for (const std::string& rating : ratingList) {
        std::size_t colonPos = rating.find(":");
        std::string ratingLine;
        if (colonPos != std::string::npos) {
            ratingLine = rating.substr(0, colonPos);
        }
        try {
            double ratingValue = std::stod(ratingLine);
            sum += ratingValue;
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: Invalid rating found: " << rating << std::endl;
        }
    }
    for (std::string rating : ratingList){
        std::cout << rating << "\n";
    }

    return sum / ratingList.size();
}

Score Score::getScores(const std::string path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << path << std::endl;
        return Score(std::vector<std::string>{}); 
    }

    std::vector<std::string> ratings;

    std::string line;
    while (std::getline(file, line)) {
            ratings.push_back(line);
    }

    file.close(); 

    return Score(ratings);
}