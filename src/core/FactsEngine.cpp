//
// Created by tristan on 04/04/19.
//

#include "FactsEngine.h"

FactsEngine::FactsEngine(std::string file_path)
: file_path(file_path) { fact_buffer.open(file_path); }

FactsEngine::~FactsEngine() {
    std::cout << "closing" << std::endl;
// TODO : créer une fonction display et une save
    display();
    fact_buffer.close();
}

void FactsEngine::fill(Record &record) {
  if (root_node != nullptr) root_node.get()->fill(record);
}

void FactsEngine::store(Record &record) {
  if (not record.is_filled()) throw UnfilledRecordException();
  if (root_node == nullptr)
    root_node.reset(new Node(record));
  else
    root_node.get()->order(new Node(record));
}

void FactsEngine::display() {
  Node::display(0, root_node.get(), fact_buffer);
    fact_buffer.flush();
}

