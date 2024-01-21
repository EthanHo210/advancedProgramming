#include <iostream>
#include <fstream>
#include <sstream>
#include "include/HostScore.h"

HostScore::HostScore(std::vector<std::string> ratings) : Score(ratings) {}

HostScore HostScore::getScores(const std::string path)
{
    std::ifstream file(path);
    if (!file.is_open())
    {
        std::cerr << "Error: Unable to open file " << path << std::endl;
        return HostScore(std::vector<std::string>{});
    }

    std::vector<std::string> ratings;
    std::string line;

    while (std::getline(file, line))
    {
        ratings.push_back(line);
    }

    file.close();

    return HostScore(ratings);
}

void HostScore::giveRating(std::string user)
{
    std::string path = "/data/score/host/" + user + ".dat";
    std::cout << "Rating your Host.\n";
    Score::giveRating(path);
}