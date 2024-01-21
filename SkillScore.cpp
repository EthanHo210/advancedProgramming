#include <iostream>
#include <fstream>
#include <sstream>
#include "include/SkillScore.h"

SkillScore::SkillScore(std::vector<std::string> ratings) : Score(ratings) {}

double SkillScore::getAvgScore() {
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

SkillScore SkillScore::getScores(const std::string path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << path << std::endl;
        return HostScore(std::vector<std::string>{});
    }

    std::vector<std::string> ratings;
    std::string line;

    for (int i = 0; i < 2; ++i)
    {
        std::getline(file, line);
    }

    while (std::getline(file, line)) {
        ratings.push_back(line);
    }

    file.close();

    return SkillScore(ratings);
    }
}