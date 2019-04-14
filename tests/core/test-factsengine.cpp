//
// Created by tristan on 09/04/19.
//

#include "../catch.hpp"
#include "../../src/core/FactsEngine.cpp"

TEST_CASE("The fact engine can't store an unfilled record to it's fact database.", "[FE]") {
    FactsEngine factsEngine("/tmp/polygonial.tree");
    Record unfilled_record = Record(3, 0, 0, 3);
    std::string message;

    try {
        factsEngine.store(unfilled_record);
    } catch (std::exception &exception) {
        message = exception.what();
    }
    REQUIRE(message == "Un unfilled record was provided where a filled one was expected.");
}

TEST_CASE("A record stay unfilled if it do not already exist in the fact database.", "[FE]") {
    FactsEngine factsEngine("/tmp/polygonial.tree");
    Record unfilled_record = Record(3, 0, 0, 3);

    factsEngine.fill(unfilled_record);
    REQUIRE(not unfilled_record.is_filled());
}

TEST_CASE("A record is filled by the fact engine if it exists in the fact database.", "[FE]") {
    FactsEngine factsEngine("/tmp/polygonial.tree");
    Record filled_record = Record(3, 0, 0, 3);
    filled_record.set_label(EQUILATERAL_TRIANGLE);
    Record unfilled_record = Record(3, 0, 0, 3);

    factsEngine.store(filled_record);
    REQUIRE(not unfilled_record.is_filled());
    factsEngine.fill(unfilled_record);
    REQUIRE(unfilled_record.is_filled());
}
