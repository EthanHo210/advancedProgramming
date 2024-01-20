#pragma once

#include "Member.h"

class Request
{
private:
    enum State
    {
        Accepted,
        Rejected,
        Pending
    };
   
    Member host;
    Member supporter;
    State state;
public:
    Request(Member host, Member supporter);

    void setAccepted();

    void setRejected();

    void clearRequest();
};