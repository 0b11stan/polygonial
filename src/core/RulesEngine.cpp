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
            if (record.get_right_angles() == 4) {
                if (record.get_same_length_sides() == 4) {
                    record.set_label(SQUARE);
                } else if (record.get_same_length_sides() == 2) {
                    record.set_label(RECTANGLE);
                }
            } else if (record.get_right_angles() == 0) {
                if (record.get_parallels_sides() == 2) {
                    if (record.get_same_length_sides() == 0) {
                        record.set_label(TRAPEZIUM);
                    } else if (record.get_same_length_sides() == 2) {
                        record.set_label(ISOSCELES_TRAPEZIUM);
                    }
                } else if (record.get_parallels_sides() == 4) {
                    if (record.get_same_length_sides() == 2) {
                        record.set_label(PARALLELOGRAM);
                    } else if (record.get_same_length_sides() == 4) {
                        record.set_label(RHOMBUS);
                    }
                } else {
                    record.set_label(TETRAGON);
                }
            }
            break;
        case 5:
            if (record.get_same_length_sides() == 5) {
                record.set_label(EQUILATERAL_PENTAGON);
            } else if (record.get_same_length_sides() == 666) {
                record.set_label(SATANISTIC_PENTAGON);
            } else {
                record.set_label(PENTAGON);
            }
            break;
        case 6:
            if (record.get_same_length_sides() == 6) {
                record.set_label(REGULAR_HEXAGON);
            } else {
                record.set_label(HEXAGON);
            }
            break;
        case 7:
            record.set_label(HEPTAGON);
            break;
        case 8:
            if (record.get_same_length_sides() == 8) {
                record.set_label(REGULAR_OCTAGON);
            } else {
                record.set_label(OCTAGON);
            }
            break;
        case 9:
            record.set_label(NONAGON);
            break;
        case 10:
            if (record.get_same_length_sides() == 10) {
                record.set_label(REGULAR_DECAGON);
            } else {
                record.set_label(DECAGON);
            }
            break;
    }
}
