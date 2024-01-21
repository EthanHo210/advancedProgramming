#pragma once
#include <string>
#include "Time.h"
#include "Member.h"
#include "Time.h"
#include <fstream>
#include "TimeBank.h"

class Request
{
private:
    enum State
    {
        Accepted,
        Rejected,
        Pending
    };

    std::string hostName;
    std::string supporterName;
    std::string skill;
    Time timeObject;
    State state;

public:
    Request(std::string hostName, std::string supporterName, Time &time_Object, std::string skill);

    void curReq(std::string hostName, std::string supporterName);

    void pendingReq(std::string supporterName, std::string hostName);

    void setAccepted();

    void setRejected();

    void clearRequest();
};