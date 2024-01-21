#ifndef HOST_SCORE_H
#define HOST_SCORE_H
#include "Score.h"
#include <vector>

class HostScore : public Score
{
public:
    HostScore(std::vector<std::string> ratings);

    static HostScore getScores(const std::string path);

    static void giveRating(std::string user);
};

#endif // HOST_SCORE_H