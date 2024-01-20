#pragma once

#include "Member.h"
#include "User.h"
#include "Member.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
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
    Request(Member &host, Member &supporter);

    void setAccepted();

    void setRejected();

    void clearRequest();
};