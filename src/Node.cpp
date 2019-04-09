//
// Created by tristan on 07/04/19.
//

#include "Node.h"

Node::Node(Record record) {
    if (record.get_label() == Label::NONE) throw UnfilledRecordException();
    this->key = record.get_sides();
    this->records.push_back(record);
}

void Node::fill(Record &record) {
    Record last_record = records.back();
    if (record.get_sides() == key) record.set_label(last_record.get_label());
    else if (record.get_sides() < key) {
        if (has_left()) left->fill(record);
    } else if (record.get_sides() > key) {
        if (has_right()) right->fill(record);
    }
}

void Node::order(Node *node) {
    if (node->get_key() < key) {
        if (left == nullptr) left = node;
        else left->order(node);
    } else if (node->get_key() > key) {
        if (right == nullptr) right = node;
        else right->order(node);
    } else records.push_back(node->get_record());
}
