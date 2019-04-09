//
// Created by tristan on 09/04/19.
//

#include "catch.hpp"
#include "../src/FactsEngine.cpp"


TEST_CASE("The fact engine can fill a record from it's fact database.", "[FE]") {
    FactsEngine factsEngine("/tmp/polygonial.tree");

    SECTION("A record stay unfilled if it do not already exist in the fact database.") {
        Record unfilled_record = Record(3,0,0,3);
        factsEngine.fill(unfilled_record);
        REQUIRE(not unfilled_record.is_filled());
    }
}
