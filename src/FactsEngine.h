//
// Created by tristan on 04/04/19.
//

#ifndef POLYGONIAL_FACTSENGINE_H
#define POLYGONIAL_FACTSENGINE_H

#include <utility>
#include <string>
#include "Record.h"
#include "UnfilledRecordException.hpp"

class FactsEngine {

private:
    std::string file_path;

public:
    explicit FactsEngine(std::string file_path) : file_path(std::move(file_path)) {}

    /*
     * Store the record in the fact tree.
     */
    void store(Record &record);

    /*
     * Go trough the tree and fill the record if a matching record is found.
     */
    void fill(Record &record);

};


#endif //POLYGONIAL_FACTSENGINE_H
