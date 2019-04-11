//
// Created by tristan on 09/04/19.
//

#include "catch.hpp"
#include "../src/InferenceEngine.cpp"

TEST_CASE("IE is always filling a record when possible.", "[IE]") {
    FactsEngine factsEngine("/tmp/polygonial");
    RulesEngine rulesEngine;
    InferenceEngine inferenceEngine(factsEngine, rulesEngine);

    Record first_record(3, 0, 0, 0);
    factsEngine.fill(first_record);
    REQUIRE(not first_record.is_filled());

    inferenceEngine.process(first_record);
    REQUIRE(first_record.is_filled());

    Record second_record(3, 0, 0, 0);
    factsEngine.fill(second_record);
    REQUIRE(second_record.is_filled());
}
