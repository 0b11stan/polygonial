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
  if (record.get_sides() == key) {
    for (auto &test_record : this->records) {
      if (test_record.get_right_angles() == record.get_right_angles() &&
          test_record.get_parallels_sides() == record.get_parallels_sides() &&
          test_record.get_same_length_sides() ==
              record.get_same_length_sides()) {
        record.set_label(test_record.get_label());
      }
    }
  } else if (record.get_sides() < key) {
    if (has_left()) left->fill(record);
  } else if (record.get_sides() > key) {
    if (has_right()) right->fill(record);
  }
}

void Node::order(Node *node) {
  if (node->get_key() < key) {
    if (left == nullptr)
      left = node;
    else
      left->order(node);
  } else if (node->get_key() > key) {
    if (right == nullptr)
      right = node;
    else
      right->order(node);
  } else
    records.push_back(node->get_record());
}

void Node::display(int offset, Node *node, std::fstream &buffer) {
  if (node != nullptr) {
    for (int x = 0; x < offset; x++) buffer << ".";
    buffer << " " << node->key << std::endl;
    for (auto &record : node->records) {
      for (int x = 0; x < offset; x++) buffer << " ";
      buffer << " > " << record.to_string() << std::endl;
    }
    display(offset + 1, node->left, buffer);
    display(offset + 1, node->right, buffer);
  }
}
