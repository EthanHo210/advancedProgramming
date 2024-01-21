#include "include/Request.h"

Request::Request(std::string hostName, std::string supporterName, Time &time_Object, std::string skill)
    : timeObject(time_Object), state(Pending)
{
    curReq(hostName, supporterName);
    pendingReq(supporterName, hostName);
}

void Request::curReq(std::string hostName, std::string supporterName)
{
    std::string filename = "data/current/" + hostName + ".dat";
    // innit(filename);
    std::stringstream input(supporterName);
    appendFile(filename, input);
}
void Request::pendingReq(std::string supporterName, std::string hostName)
{
    std::string filename = "data/pending/" + supporterName + ".dat";
    // innit(filename);
    std::stringstream input(hostName);
    appendFile(filename, input);
}

void Request::setAccepted()
{
}

void Request::setRejected(){};
