#include "include/Request.h"

Request::Request(std::string host, std::string supporter) : host(host), supporter(supporter) /*, state(Pending)*/ {};

void Request::setAccepted()
{
}

void Request::setRejected(){};
