//
// Created by tristan on 04/04/19.
//

#include <backtrace.h>
#include "RulesEngine.h"

void RulesEngine::fill(Record &record) {
    switch (record.get_sides()) {
        case 3:
            if (record.get_same_length_sides() == 3) {
                record.set_label(EQUILATERAL_TRIANGLE);
            } else if (record.get_right_angles() == 1) {
                if (record.get_same_length_sides() == 2) {
                    record.set_label(RIGHT_ISOSCELES_TRIANGLE);
                } else {
                    record.set_label(RIGHT_TRIANGLE);
                }
            } else if (record.get_same_length_sides() == 2) {
                record.set_label(ISOSCELES_TRIANGLE);

            } else {
                record.set_label(TRIANGLE);
            }
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
            record.set_label(OCTAGON);
            break;
        case 9:
            record.set_label(NONAGON);
            break;
        case 10:
            record.set_label(DECAGON);
            break;
    }
}
