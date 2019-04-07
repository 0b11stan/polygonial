//
// Created by tristan on 07/04/19.
//

#ifndef POLYGONIAL_NODE_H
#define POLYGONIAL_NODE_H


#include <vector>
#include "Record.h"

class Node {

private:
    int key;
    Node *left = nullptr;
    Node *right = nullptr;
    std::vector<Record> records;

public:
    /*
     * Create a new node with a record.
     */
    explicit Node(Record record);

    /*
     * Order and store the record in the nodes tree.
     */
    void order(Record &record);

    /*
     * If the record sides number match this node key, go trough the records to find a matching one.
     * If a matching record is found, fill the label.
     */
    void fill(Record &record);

};


#endif //POLYGONIAL_NODE_H
