//
// Created by tristan on 09/04/19.
//

#include "catch.hpp"
#include "../src/RulesEngine.cpp"

TEST_CASE("RE can recognize simple polygon from triangle to decagon.", "[RE]") {
    RulesEngine rulesEngine;
    Label labels[] = {TRIANGLE, TETRAGON, PENTAGON, HEXAGON, HEPTAGON, OCTAGON, NONAGON, DECAGON};

    for (int x = 0; x < (sizeof(labels)/ sizeof(*labels)); x++) {
        Record record(x + 3, 0, 0, 0);
        rulesEngine.fill(record);
        REQUIRE(record.get_label() == labels[x]);
    }
}
