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

#include "twoGateNode.h"

Define_Module(twoGateNode);

void twoGateNode::initialize() {

    if (strcmp(getName(), "A") == 0) {
        this->neightbour_out["B"] = "out1";
        this->neightbour_out["E"] = "out2";

        this->content_list.push_back("file1");
        this->content_list.push_back("file2");
        this->content_list.push_back("file3");
        this->content_list.push_back("file4");
        this->content_list.push_back("file5");
        this->content_list.push_back("file6");
        this->content_list.push_back("file7");
        this->content_list.push_back("file8");
        this->content_list.push_back("file9");
        this->content_list.push_back("file10");

        query *q = new query();
        q->setSeq_id(11);
        q->setTTL(10);
        q->setHops(0);
        q->setSource("A");
        q->setOrigin("A");
        q->setLocation_found(false);
        q->setQueriedData("file20-a");
        id_source[q->getSeq_id()] = getName();
        this->broadcastMessage(q, getName());
    }

    if (strcmp(getName(), "D") == 0) {
        this->neightbour_out["C"] = "out1";
        this->neightbour_out["H"] = "out2";

        this->content_list.push_back("file11");
        this->content_list.push_back("file12");
        this->content_list.push_back("file13");
        this->content_list.push_back("file14");
        this->content_list.push_back("file15");
        this->content_list.push_back("file6");
        this->content_list.push_back("file7");
        this->content_list.push_back("file8");
        this->content_list.push_back("file19");
        this->content_list.push_back("file20");

//        query *q = new query();
//        q->setSeq_id(12);
//        q->setTTL(10);
//        q->setHops(0);
//        q->setSource("D");
//        q->setOrigin("D");
//        q->setLocation_found(false);
//        q->setQueriedData("file17blah");
//        id_source[q->getSeq_id()] = getName();
//        this->broadcastMessage(q, getName());
    }

    if (strcmp(getName(), "I") == 0) {
        this->neightbour_out["E"] = "out1";
        this->neightbour_out["J"] = "out2";

        this->content_list.push_back("file14");
        this->content_list.push_back("file15");
        this->content_list.push_back("file16");
        this->content_list.push_back("file17");
        this->content_list.push_back("file25");
        this->content_list.push_back("file26");
        this->content_list.push_back("file27");
        this->content_list.push_back("file28");
        this->content_list.push_back("file29");
        this->content_list.push_back("file30-a");
    }

    if (strcmp(getName(), "L") == 0) {
        this->neightbour_out["H"] = "out1";
        this->neightbour_out["K"] = "out2";

        this->content_list.push_back("file1");
        this->content_list.push_back("file2");
        this->content_list.push_back("file3");
        this->content_list.push_back("file14");
        this->content_list.push_back("file15");
        this->content_list.push_back("file16");
        this->content_list.push_back("file17");
        this->content_list.push_back("file18");
        this->content_list.push_back("file19");
        this->content_list.push_back("file20-a");

//        query *q = new query();
//        q->setSeq_id(16);
//        q->setTTL(10);
//        q->setHops(0);
//        q->setSource("L");
//        q->setOrigin("L");
//        q->setLocation_found(false);
//        q->setQueriedData("file30");
//        id_source[q->getSeq_id()] = getName();
//        this->broadcastMessage(q, getName());
    }

}

void twoGateNode::sendBack(query *q, const char* destination) {

    q->setSource(getName());
    if (strcmp(q->getSource(), destination) == 0) {
        return;
    }
    //EV<<destination<<endl;
    //Decrease TTL and increase hops
    q->setTTL(q->getTTL() - 1);
    q->setHops(q->getHops() + 1);

    const char *des;
    for (const auto &myPair : neightbour_out) {
        if (strcmp(myPair.first, destination) == 0) {
            des = myPair.second;
            //EV<<des<<endl;
            break;
        }
    }
    // Send the message to the source

    send(q, des);

}

void twoGateNode::broadcastMessage(query *q, const char* src) {

    // For each neighbor of a node
    for (const auto &myPair : neightbour_out) {
        query* q1 = new query();
        // Decrease TTP and increase HOps
        q1->setTTL(q->getTTL() - 1);
        q1->setHops(q->getHops() + 1);
        // Assign the sequence id
        q1->setSeq_id(q->getSeq_id());

        q1->setLocation_found(q->getLocation_found());
        //q1->setQueriedData(q->getQueriedData());
        // Set where the packet is headed
        q1->setDestination(myPair.first);
        // From where the current location is
        q1->setSource(getName());
        // Don't send back to the source
        if (strcmp(myPair.first, src) == 0) {
            continue;
        }
        q1->setQueriedData(q->getQueriedData());
        //q1->setQueriedData(q->getQueriedData());
        send(q1, myPair.second);
    }

}

// Check if the queried file actually on the current node
bool twoGateNode::checkForFile(const char *check) {
    bool fileFound = false;

    list<const char*>::iterator iter;
    for (iter = content_list.begin(); iter != content_list.end(); ++iter) {

        if (strcmp(*iter, check) == 0) {
            fileFound = true;
        }

    }

    return fileFound;

}

void twoGateNode::handleMessage(cMessage *msg) {

    query *q = check_and_cast<query *>(msg);
    // If the TTL has decremented to 0, stop sending the packet
    if (q->getTTL() <= 0) {
        return;
    }

    // Adding the Packet's identification Id and source to the map
    if (this->id_source.find(q->getSeq_id()) == this->id_source.end()) {
        // Previous Node is the data sender
        this->id_source[q->getSeq_id()] = q->getSource();
    } else if (this->id_source.find(q->getSeq_id()) != this->id_source.end()
            && !q->getLocation_found()) {
        return;
    }

    for (const auto &myPair : this->id_source) {
        EV << myPair.first << " " << myPair.second << endl;

    }

    // Checking if the packet is meant for current node
    if (strcmp((id_source[q->getSeq_id()]).c_str(), getName()) == 0) {
        EV << "REcord found " << q->getOrigin() << endl;
        file_location_list.push_back(q->getOrigin());
        return;
    }

    // Checking if the current node is the data node
    if (q->getLocation_found() == false) {
        if (this->checkForFile(q->getQueriedData()) == true) {
            // Set the fields if file is on the current server
            q->setLocation_found(true);
            q->setOrigin(getName());
            q->setTTL(q->getHops() + 1);
            q->setHops(-1);
        }

        else
            q->setLocation_found(false);
    }

    bool fileFound = q->getLocation_found();

    if (this->id_source.size() >= 100) {
        this->id_source.clear();
    }

    if (fileFound) {
        // If file has been found, send the packet back from where it originally came

        //q->setDestination(findDestination(q->getSeq_id()));
        q->setDestination((this->id_source[q->getSeq_id()]).c_str());
        //EV<<q->getSeq_id()<<endl;
        sendBack(q, q->getDestination());
    } else {
        const char *temp = q->getSource();
        q->setSource(getName());
        //Otherwise send to all other nodes, except the source
        broadcastMessage(q, temp);
    }

}
