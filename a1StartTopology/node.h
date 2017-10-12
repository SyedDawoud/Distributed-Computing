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

#ifndef NODE_H_
#define NODE_H_

#include <omnetpp/csimplemodule.h>
#include <omnetpp.h>
#include <string.h>
#include <map>
#include <list>
#include "query_m.h"

using namespace omnetpp;
using namespace std;

// This class specify the branches of the star Topology
class node: public omnetpp::cSimpleModule {
public:

    map<int, string> id_source;
    map<const char*, const char*> neightbour_out;

    list<const char*> content_list;
    // List to hold all those nodes' names that have the required file
    list <const char*> file_location_list;

    node();
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;

    void broadcastMessage(query *q, const char* src);
    void sendBack(query *q, const char* destination);
    bool checkForFile(const char *check);
};

#endif /* NODE_H_ */
