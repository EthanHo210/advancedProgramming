#include <iostream>
#include <fstream>
#include <sstream>
#include "include/SupporterScore.h"

SupporterScore::SupporterScore(std::vector<std::string> ratings) : Score(ratings) {}

double SupporterScore::getAvgScore() {
    if (ratingList.empty()) {
        return 0.0;
    }

    double sum = 0.0;
    for (const std::string &rating : ratingList) {
        std::istringstream ss(rating);
        std::string ratingLine;
        if (std::getline(ss, ratingLine, ':')) {
            try {
                double ratingValue = std::stod(ratingLine);
                sum += ratingValue;
            } catch (const std::invalid_argument &e) {
                std::cerr << "Error: Invalid rating found: " << rating << std::endl;
            }
        }
    }
    for (const std::string rating : ratingList) {
        std::cout << rating << "\n";
    }
    return sum / ratingList.size();

SupporterScore SupporterScore::getScores(const std::string path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << path << std::endl;
        return HostScore(std::vector<std::string>{});
    }

    std::vector<std::string> ratings;
    std::string line;

    while (std::getline(file, line)) {
        ratings.push_back(line);
    }

    file.close();

    return SupporterScore(ratings);
    }
}