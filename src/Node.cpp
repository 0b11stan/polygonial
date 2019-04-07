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
    record.set_label(last_record.get_label());
}
