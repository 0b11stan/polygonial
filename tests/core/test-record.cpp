//
// Created by tristan on 07/04/19.
//

#include "../catch.hpp"

#include "../../src/core/Record.hpp"

TEST_CASE("Records usage.", "[record]") {
  Record record(3, 1, 0, 0);
  REQUIRE(record.get_sides() == 3);
  REQUIRE(record.get_right_angles() == 1);
  REQUIRE(record.get_parallels_sides() == 0);
  REQUIRE(record.get_same_length_sides() == 0);
  REQUIRE(record.get_label() == Label::NONE);
  REQUIRE(not record.is_filled());

  SECTION("Label can be set later.") {
    record.set_label(SQUARE);
    REQUIRE(record.get_label() == Label::SQUARE);
    REQUIRE(record.is_filled());
  }
}

