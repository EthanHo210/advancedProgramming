#pragma once
#include <string>

class Time 
{
    public: 
    std::string startTime;
    std::string endTime;

    Time (std::string start = "", std::string end = "");
};