//
// Created by tristan on 07/04/19.
//

#include "catch.hpp"

#include "../src/Record.h"

TEST_CASE("Records can be created", "[record]") {
    Record record(3, 1, 0, 0);
    REQUIRE(record.get_sides() == 3);
}

