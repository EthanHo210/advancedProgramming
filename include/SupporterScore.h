#ifndef SUPPORTER_SCORE_H
#define SUPPORTER_SCORE_H
#include "Score.h"
#include <vector>

class SupporterScore : public Score
{
public:
    SupporterScore(std::vector<std::string> ratings);

    double getAvgScore() override;

    static SupporterScore getScores(const std::string path);
};

#endif // SUPPORTER_SCORE_H