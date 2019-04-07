//
// Created by tristan on 07/04/19.
//

#include "catch.hpp"

#include "../src/Record.h"

TEST_CASE("Records is created with empty label", "[record]") {
    Record record(3, 1, 0, 0);
    REQUIRE(record.get_sides() == 3);
    REQUIRE(record.get_right_angles() == 1);
    REQUIRE(record.get_parallels_sides() == 0);
    REQUIRE(record.get_same_length_sides() == 0);
    REQUIRE(record.get_label() == Label());
}

