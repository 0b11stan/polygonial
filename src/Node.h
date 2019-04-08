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
    void order(Node *node);

    /*
     * If the record sides number match this node key, go trough the records to find a matching one.
     * If a matching record is found, fill the label.
     */
    void fill(Record &record);

    bool has_left() { return left != nullptr; }

    bool has_right() { return right != nullptr; }

    unsigned get_size() { return records.size(); }

    int get_key() { return key; }

    Record get_record() { return records.back(); }
};


#endif //POLYGONIAL_NODE_H
