//
// Created by tristan on 09/04/19.
//

#include "catch.hpp"
#include "../src/RulesEngine.cpp"

TEST_CASE("RE can recognize simple polygon from triangle to decagon.", "[RE]") {
    RulesEngine rulesEngine;

    SECTION("RE can recognize a triangle.") {
        Record triangle(3,0,0,0);
        rulesEngine.fill(triangle);
        REQUIRE(triangle.get_label() == TRIANGLE);
    }
}
