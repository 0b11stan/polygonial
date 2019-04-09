//
// Created by tristan on 04/04/19.
//

#include "FactsEngine.h"

void FactsEngine::fill(Record &record) {

}

void FactsEngine::store(Record &record) {
    if (not record.is_filled()) throw UnfilledRecordException();
}
