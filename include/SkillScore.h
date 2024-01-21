#ifndef SKILL_SCORE_H
#define SKILL_SCORE_H
#include "Score.h"
#include <vector>

class SkillScore : public Score
{
public:
    SkillScore(std::vector<std::string> ratings);

    static SkillScore getScores(const std::string path);

    static giveRating() override;
};

#endif // SKILL_SCORE_H