//
// Created by tristan on 09/04/19.
//

#include "catch.hpp"
#include "../src/RulesEngine.cpp"

TEST_CASE("RE can recognize simple polygon from triangle to decagon.", "[RE]") {
    RulesEngine rulesEngine;

    SECTION("RE can recognize a triangle.") {
        Record record(3, 0, 0, 0);
        rulesEngine.fill(record);
        REQUIRE(record.get_label() == TRIANGLE);
    }

    SECTION("RE can recognize a tetragon.") {
        Record record(4, 0, 0, 0);
        rulesEngine.fill(record);
        REQUIRE(record.get_label() == TETRAGON);
    }

    SECTION("RE can recognize a pentagon.") {
        Record record(5, 0, 0, 0);
        rulesEngine.fill(record);
        REQUIRE(record.get_label() == PENTAGON);
    }

    SECTION("RE can recognize a hexagon.") {
        Record record(6, 0, 0, 0);
        rulesEngine.fill(record);
        REQUIRE(record.get_label() == HEXAGON);
    }

    SECTION("RE can recognize a heptagon.") {
        Record record(7, 0, 0, 0);
        rulesEngine.fill(record);
        REQUIRE(record.get_label() == HEPTAGON);
    }

    SECTION("RE can recognize a octagon.") {
        Record record(8, 0, 0, 0);
        rulesEngine.fill(record);
        REQUIRE(record.get_label() == OCTAOGON);
    }

    SECTION("RE can recognize a nonagon.") {
        Record record(9, 0, 0, 0);
        rulesEngine.fill(record);
        REQUIRE(record.get_label() == NONAGON);
    }

    SECTION("RE can recognize a decagon.") {
        Record record(10, 0, 0, 0);
        rulesEngine.fill(record);
        REQUIRE(record.get_label() == DECAGON);
    }
}
