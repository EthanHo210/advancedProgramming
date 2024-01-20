#pragma once
#include "Member.h"

class Request {
private:

    Member host;
    Member supporter;

public:
    Request(Member host, Member supporter);

    void setAccepted();

    void setRejected();

    void clearRequest();

    Member getHost() const { return host; }

    Member getSupporter() const { return supporter; }

};