#include <string>

class Skill
{
private:
    std::string name;
    int pph;
    double score;

public:
    Skill(std::string name, int pph, double score);

    friend class Member;
};
