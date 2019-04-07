//
// Created by tristan on 07/04/19.
//

#include "catch.hpp"
#include <exception>

#include "../src/Node.cpp"

TEST_CASE("Record filling.", "[node]") {

    Record filled_record(4, 4, 4, 4);
    filled_record.set_label(SQUARE);

    Node node(filled_record);

    SECTION("A node can fill a record from an existing fact.") {
        Record unfilled_record(4, 4, 4, 4);
        node.fill(unfilled_record);

        REQUIRE(unfilled_record.get_label() == Label::SQUARE);
    }

    SECTION("A leaf node can't fill a record if no fact match.") {
        Record unfilled_record(3, 0, 0, 3);
        node.fill(unfilled_record);

        REQUIRE(unfilled_record.get_label() == Label::NONE);
    }
}

TEST_CASE("Node ordering.", "[node]") {

    Record parent_record(4, 4, 4, 4);
    parent_record.set_label(SQUARE);

    Node parent_node(parent_record);

    SECTION("A record with no label can't be ordered.") {
        Record child_record(3, 0, 0, 3);
        bool excepted = false;
        try {
            parent_node.order(child_record);
        } catch (std::exception& exception) {
            excepted = true;
        }
        REQUIRE(excepted == true);
    }

    SECTION("A record with less sides become left children.") {
        Record children_record(3, 0, 0, 3);
        children_record.set_label(EQUILATERAL_TRIANGLE);

        parent_node.order(children_record);

        REQUIRE(parent_node.has_left());
        REQUIRE(!parent_node.has_right());
    }

    SECTION("A record with more sides become right children.") {
        Record children_record(6, 0, 6, 6);
        children_record.set_label(HEXAGON);

        parent_node.order(children_record);

        REQUIRE(!parent_node.has_left());
        REQUIRE(parent_node.has_right());
    }

    SECTION("A record with same number of sides but is added to this node facts.") {
        unsigned size = parent_node.get_size();

        Record child_record(4, 4, 4, 2);
        child_record.set_label(RECTANGLE);

        parent_node.order(child_record);

        REQUIRE(!parent_node.has_left());
        REQUIRE(!parent_node.has_right());
        REQUIRE(parent_node.get_size() == size + 1);
    }

}
