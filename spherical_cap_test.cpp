#include <catch2/catch_test_macros.hpp>  // use catch2 as a library
#include <catch2/matchers/catch_matchers_floating_point.hpp>

// when using amalgamated version of Catch2:
// #include "catch_amalgamated.hpp"

double volume(double radius, double height);  // usually in header file
double surface(double radius, double height);  // usually in header file

TEST_CASE("volume calculation is correct", "[volume]") {
  CHECK_THAT(volume(3.4, 2.1), Catch::Matchers::WithinAbs(37.407, 0.001));
}

TEST_CASE("surface calculation is correct", "[surface]") {
  CHECK_THAT(surface(3.4, 2.1), Catch::Matchers::WithinAbs(44.862, 0.001));
}

