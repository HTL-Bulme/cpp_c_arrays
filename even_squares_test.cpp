#include "even_squares.hpp"

#include <cstdint>

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>

TEST_CASE("vector containing elements exclusive the limit", "[regular]") {
  CHECK_THAT(even_squares(25),
    Catch::Matchers::Equals(std::vector<uint32_t>{ 0, 4, 16 }));
  CHECK_THAT(even_squares(121),
    Catch::Matchers::Equals(std::vector<uint32_t>{ 0, 4, 16, 36, 64, 100 }));
}

TEST_CASE("vector containing 0", "[zero]") {
  CHECK_THAT(even_squares(0),
    Catch::Matchers::Equals(std::vector<uint32_t>{ 0 }));
}

TEST_CASE("vector containing the limit", "[limit]") {
  CHECK_THAT(even_squares(4),
    Catch::Matchers::Equals(std::vector<uint32_t>{ 0, 4 }));
  CHECK_THAT(even_squares(64),
    Catch::Matchers::Equals(std::vector<uint32_t>{ 0, 4, 16, 36, 64 }));
}
