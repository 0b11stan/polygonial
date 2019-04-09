//
// Created by tristan on 04/04/19.
//

#include "RulesEngine.h"

void RulesEngine::fill(Record &record) {
    if (record.get_sides() == 3) record.set_label(TRIANGLE);
}
