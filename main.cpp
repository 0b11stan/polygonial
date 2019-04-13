//
// Created by tristan on 04/04/19.
//

#include <cstdio>
#include <getopt.h>
#include <cstdlib>
#include "src/core/Record.h"
#include "src/core/RulesEngine.h"
#include "src/core/FactsEngine.h"
#include "src/core/InferenceEngine.h"

std::string to_string(Label label) {
    switch (label) {
        case TRIANGLE:
            return "TRIANGLE";
        case TETRAGON:
            return "TETRAGON";
        case PENTAGON:
            return "PENTAGON";
        case HEXAGON:
            return "HEXAGON";
        case HEPTAGON:
            return "HEPTAGON";
        case OCTAGON:
            return "OCTAGON";
        case NONAGON:
            return "NONAGON";
        case DECAGON:
            return "DECAGON";
        case NONE:
        default:
            return "UNKNOWN POLYGON";
    }
}

int main(int argc, char *argv[]) {
    printf("Welcome to Polygonial, your polygon :\n");

    int count;
    int sides = 0;
    int right_angles = 0;
    int parallels_sides = 0;
    int same_length_sides = 0;

    while ((count = getopt(argc, argv, "s:r:p:l:")) != -1) {
        switch (count) {
            case 's':
                if (optarg) sides = atoi(optarg);
                break;
            case 'r':
                if (optarg) right_angles = atoi(optarg);
                break;
            case 'p':
                if (optarg) parallels_sides = atoi(optarg);
                break;
            case 'l':
                if (optarg) same_length_sides = atoi(optarg);
                break;
            default:
                printf("ERROR : no args provided.");
                return 0;
        }
    }

    printf("sides : %d\n", sides);
    printf("right angles : %d\n", right_angles);
    printf("parallels sides : %d\n", parallels_sides);
    printf("same length sides : %d\n", same_length_sides);

    Record record(sides, right_angles, parallels_sides, same_length_sides);
    RulesEngine rulesEngine;
    FactsEngine factsEngine("/tmp/polygonial");
    InferenceEngine inferenceEngine(factsEngine, rulesEngine);
    inferenceEngine.process(record);

    printf("\nYour polygon is a %s\n", to_string(record.get_label()).c_str());

    return 0;
}
