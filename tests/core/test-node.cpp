//
// Created by tristan on 07/04/19.
//

#include <exception>
#include "../../src/core/Node.cpp"
#include "../catch.hpp"

TEST_CASE("The facts tree can fill a record if it already knows it.",
          "[node]") {
  Record filled_record(4, 4, 4, 4);
  filled_record.set_label(SQUARE);

  Node parent_node(filled_record);

  SECTION("A parent_node can fill a record from an existing fact.") {
    Record unfilled_record(4, 4, 4, 4);
    parent_node.fill(unfilled_record);

    REQUIRE(unfilled_record.get_label() == Label::SQUARE);
  }

  SECTION("A leaf parent_node can't fill a record if no fact match.") {
    Record unfilled_record(3, 0, 0, 3);
    parent_node.fill(unfilled_record);

    REQUIRE(unfilled_record.get_label() == Label::NONE);
  }

  SECTION("A record can be filled by the left child parent_node.") {
    Record triangle_record(3, 0, 0, 3);
    triangle_record.set_label(EQUILATERAL_TRIANGLE);
    parent_node.order(new Node(triangle_record));

    Record unfilled_record(3, 0, 0, 3);
    parent_node.fill(unfilled_record);
    REQUIRE(unfilled_record.get_label() == Label::EQUILATERAL_TRIANGLE);
  }

  SECTION(
      "A record with more sides is filled by the right child parent_node.") {
    Record children_record(6, 0, 6, 6);
    children_record.set_label(HEXAGON);
    parent_node.order(new Node(children_record));

    Record unfilled_record(6, 0, 6, 6);
    parent_node.fill(unfilled_record);
    REQUIRE(unfilled_record.get_label() == Label::HEXAGON);
  }
}

TEST_CASE("The tree can store a record in an effective way.", "[node]") {
  Record parent_record(4, 4, 4, 4);
  parent_record.set_label(SQUARE);

  Node parent_node(parent_record);

  SECTION("A node can't be created if record is unfilled.") {
    Record child_record(3, 0, 0, 3);
    std::string message;
    try {
      Node node(child_record);
    } catch (std::exception &exception) {
      message = exception.what();
    }
    REQUIRE(message ==
            "Un unfilled record was provided where a filled one was expected.");
  }

  SECTION("A record with less sides become left children.") {
    Record children_record(3, 0, 0, 3);
    children_record.set_label(EQUILATERAL_TRIANGLE);

    parent_node.order(new Node(children_record));

    REQUIRE(parent_node.has_left());
    REQUIRE(!parent_node.has_right());
  }

  SECTION("A record with more sides become right children.") {
    Record children_record(6, 0, 6, 6);
    children_record.set_label(HEXAGON);

    parent_node.order(new Node(children_record));

    REQUIRE(!parent_node.has_left());
    REQUIRE(parent_node.has_right());
  }

  SECTION(
      "A record with same number of sides but is added to this node facts.") {
    unsigned size = parent_node.get_size();

    Record child_record(4, 4, 4, 2);
    child_record.set_label(RECTANGLE);

    parent_node.order(new Node(child_record));

    REQUIRE(!parent_node.has_left());
    REQUIRE(!parent_node.has_right());
    REQUIRE(parent_node.get_size() == size + 1);
  }
}

