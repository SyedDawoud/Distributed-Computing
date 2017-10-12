#include <omnetpp.h>
#include <string.h>
#include <map>
#include <list>
#include "query_m.h"

using namespace omnetpp;
using namespace std;

#include <omnetpp/csimplemodule.h>

#ifndef FOURGATENODE_H_
#define FOURGATENODE_H_

class fourGateNode: public cSimpleModule {
    // map to hold Packet id and its original source
       map<int,string> id_source;
       // Map to hold neightbour and its output gate
       map<const char*,const char*> neightbour_out;
       // List of all the contents available on a node
       list<const char*> content_list;

       list<const char*> file_location_list;

       virtual void initialize() override;
       virtual void handleMessage(cMessage *msg) override;

       void broadcastMessage(query *q,const char* src);
       void sendBack(query *q, const char* destination);
       bool checkForFile(const char *check);
};

#endif /* FOURGATENODE_H_ */
