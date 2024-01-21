#pragma once
#include <string>

class Request
{
private:
    std::string host;
    std::string supporter;

public:
    Request(std::string host, std::string supporter);

    void setAccepted();

    void setRejected();

    void clearRequest();
};