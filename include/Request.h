#pragma once

#include "Member.h"
#include "Time.h"

class Request
{
private:
    enum State
    {
        Accepted,
        Rejected,
        Pending
    };

    string hostName;
    string supporterName;
    string skill;
    Time timeObject;
    State state;
public:
    Request(string hostName,string supporterName, Time &time_Object, string skill);

    void curReq(string hostName, string supporterName);

    void pendingReq(string supporterName, string hostName);

    void setAccepted();

    void setRejected();

    void clearRequest();
};