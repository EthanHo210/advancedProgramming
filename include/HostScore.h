#include "Score.h"
#include <vector>

class HostScore : public Score
{
private:
public:
    HostScore(std::vector<std::string> ratings);
};