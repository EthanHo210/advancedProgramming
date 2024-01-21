#include <iostream>
#include <fstream>
#include <sstream>
#include "include/SupporterScore.h"

SupporterScore::SupporterScore(std::vector<std::string> ratings) : Score(ratings) {}

SupporterScore SupporterScore::getScores(const std::string path)
{
    std::ifstream file(path);
    if (!file.is_open())
    {
        std::cerr << "Error: Unable to open file " << path << std::endl;
        return SupporterScore(std::vector<std::string>{});
    }

    std::vector<std::string> ratings;
    std::string line;

    while (std::getline(file, line))
    {
        ratings.push_back(line);
    }

    file.close();

    return SupporterScore(ratings);
}

void SupporterScore::giveRating(std::string user)
{
    std::string path = "/data/score/supporter" + user + ".dat";
    std::cout << "Rating your Supporter.\n";
    Score::giveRating(path);
}
