//
// Created by tristan on 04/04/19.
//

#include "RulesEngine.h"

void RulesEngine::fill(Record &record) {
    if (record.get_sides() == 3) record.set_label(TRIANGLE);
    else if (record.get_sides() == 4) record.set_label(TETRAGON);
    else if (record.get_sides() == 5) record.set_label(PENTAGON);
    else if (record.get_sides() == 6) record.set_label(HEXAGON);
    else if (record.get_sides() == 7) record.set_label(HEPTAGON);
    else if (record.get_sides() == 8) record.set_label(OCTAOGON);
    else if (record.get_sides() == 9) record.set_label(NONAGON);
    else if (record.get_sides() == 10) record.set_label(DECAGON);
}
