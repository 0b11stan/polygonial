//
// Created by tristan on 04/04/19.
//

#include "FactsEngine.h"

void FactsEngine::fill(Record &record) {
  if (root_node != nullptr) root_node.get()->fill(record);
}

void FactsEngine::store(Record &record) {
  if (not record.is_filled()) throw UnfilledRecordException();
  if (root_node == nullptr) root_node.reset(new Node(record));
}

std::string FactsEngine::to_string() { return "NOT IMPLEMENTED"; }
