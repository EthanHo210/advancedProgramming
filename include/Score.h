#pragma once

#include <vector>
#include <string>

class Score {
private:
    std::vector<std::string> ratingList;
public:
    Score(std::vector<std::string> ratings);
   
    double getAvgScore();

    static Score getScores(const std::string path);

    static giveRating(const std::string path);
};