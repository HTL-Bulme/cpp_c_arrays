#include <cstdint>
#include <catch2/catch_test_macros.hpp>  // use catch2 as a library
// when using amalgamated version of Catch2:
// #include "catch_amalgamated.hpp"
uint64_t sum_to(unsigned n);  // usually in header file

TEST_CASE("sum_to must calculate correctly", "[sum_to]") {
  // setup code that runs before each section is written here

  SECTION("regular use cases") {
    // if REQUIRE fails, TEST fails immediately
    REQUIRE(sum_to(25) == 325);
    // if CHECK fails, TEST will fail, but continue
    CHECK(sum_to(26) == 351);
    REQUIRE(sum_to(500000000) == 125000000250000000);
  }

  SECTION("corner cases") { REQUIRE(sum_to(0) == 0); }
}

TEST_CASE("sum_to must work for max uint32", "[sum_to_slow]") {
  REQUIRE(sum_to(UINT32_MAX) == 9223372034707292160);
}
