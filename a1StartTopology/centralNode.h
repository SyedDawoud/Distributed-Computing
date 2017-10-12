//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#ifndef CENTRALNODE_H_
#define CENTRALNODE_H_

#include <omnetpp.h>
#include <string.h>
#include <map>
#include <list>
#include "query_m.h"

using namespace omnetpp;
using namespace std;

#include <omnetpp/csimplemodule.h>

class centralNode: public omnetpp::cSimpleModule {
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

    //const char* findDestination(int i);

};

#endif /* CENTRALNODE_H_ */
