//
// Created by tristan on 07/04/19.
//

#include "Node.h"

Node::Node(Record record) {
    this->key = record.get_sides();
    this->records.push_back(record);
}

void Node::fill(Record &record) {
    Record last_record = records.back();

    if (record.get_sides() == key) {
        record.set_label(last_record.get_label());
    }
}

void Node::order(Record record) {
    if (record.get_sides() < key) left.reset(new Node(record));
    else if (record.get_sides() > key) right.reset(new Node(record));
}
