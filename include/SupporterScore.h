#ifndef SUPPORTER_SCORE_H
#define SUPPORTER_SCORE_H
#include "Score.h"
#include <vector>

class SupporterScore : public Score
{
public:
    SupporterScore(std::vector<std::string> ratings);

    static SupporterScore getScores(const std::string path);

    static giveRating() override;
};

#endif // SUPPORTER_SCORE_H