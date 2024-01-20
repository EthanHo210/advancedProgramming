#include "include/Request.h"

Request::Request(Member host, Member supporter) : host(host), supporter(supporter)/*, state(Pending)*/{};

void Request::setAccepted(){
    this->state = Accepted;
}

void Request::setRejected(){
    this->state = Rejected;
};

