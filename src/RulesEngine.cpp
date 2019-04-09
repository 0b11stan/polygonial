//
// Created by tristan on 04/04/19.
//

#include <backtrace.h>
#include "RulesEngine.h"

void RulesEngine::fill(Record &record) {
    switch (record.get_sides()) {
        case 3:
            record.set_label(TRIANGLE);
            break;
        case 4:
            record.set_label(TETRAGON);
            break;
        case 5:
            record.set_label(PENTAGON);
            break;
        case 6:
            record.set_label(HEXAGON);
            break;
        case 7:
            record.set_label(HEPTAGON);
            break;
        case 8:
            record.set_label(OCTAOGON);
            break;
        case 9:
            record.set_label(NONAGON);
            break;
        case 10:
            record.set_label(DECAGON);
            break;
    }
}
