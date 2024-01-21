#include <iostream>
#include <fstream>
#include <sstream>
#include "include/SkillScore.h"

SkillScore::SkillScore(std::vector<std::string> ratings) : Score(ratings) {}

SkillScore SkillScore::getScores(const std::string path)
{
    std::ifstream file(path);
    if (!file.is_open())
    {
        std::cerr << "Error: Unable to open file " << path << std::endl;
        return SkillScore(std::vector<std::string>{});
    }

    std::vector<std::string> ratings;
    std::string line;

    while (std::getline(file, line))
    {
        ratings.push_back(line);
    }

    file.close();

    return SkillScore(ratings);
}

void SkillScore::giveRating(std::string user)
{
    std::string path = "/data/score/skill/" + user + ".dat";
    std::cout << "Rating your Skill.\n";
    Score::giveRating(path);
}
