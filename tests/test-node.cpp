//
// Created by tristan on 07/04/19.
//

#include "catch.hpp"

#include "../src/Node.cpp"

TEST_CASE("Node usage.", "[node]") {

    Record filled_record(4, 4, 4, 4);
    filled_record.set_label(SQUARE);

    Node node(filled_record);

    SECTION("A node can fill a record from an existing fact.") {
        Record unfilled_record(4, 4, 4, 4);
        node.fill(unfilled_record);

        REQUIRE(unfilled_record.get_label() == SQUARE);
    }
}
