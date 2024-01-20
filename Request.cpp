#include "include/Request.h"
#include "include/Time.h"
#include "include/data.h"
#include <string>
#include <fstream>


Request::Request(string hostName,string supporterName, Time &time_Object, string skill)
    :timeObject(time_Object), state(Pending)
    {
        curReq(hostName, supporterName);
        pendingReq(supporterName, hostName);
    }

void Request::curReq(string hostName, string supporterName)
    {
        string filename = "Data/current/" + hostName + ".dat";
        //innit(filename);
        save_All_Members(filename, supporterName);
    }
void Request::pendingReq(string supporterName, string hostName)
    {
        string filename = "Data/Pending/" + supporterName + ".dat";
        //innit(filename);
        save_All_Members(filename, hostName);
    }

void Request::setAccepted(){
    this->state = Accepted;
}

void Request::setRejected(){
    this->state = Rejected;
};