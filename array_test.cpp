#include "array.hpp"

#include <cstddef>
#include <cstdint>

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>

TEST_CASE("empty array", "[sum]") {
  REQUIRE(sum((int32_t[0]) {}, 0) == 0);
  // callee cannot know the array is not empty
  REQUIRE(sum((int32_t[2]) {3, 2}, 0) == 0);
}

TEST_CASE("single element", "[sum]") {
  CHECK(sum((int32_t[1]) {3}, 1) == 3);
  CHECK(sum((int32_t[1]) {-1234}, 1) == -1234);
}

TEST_CASE("positive only", "[sum]") {
  CHECK(sum((int32_t[5]) {1, 2, 3, 4, 5}, 5) == 15);
  CHECK(sum((int32_t[5]) {1, 1, 1, 1, 1}, 5) == 5);
  CHECK(sum((int32_t[3]) {99, 1, 0}, 3) == 100);
  CHECK(sum((int32_t[5]) {2, 4, 6, 8, 10}, 5) == 30);
}

TEST_CASE("mixing positive and negative", "[sum]") {
  CHECK(sum((int32_t[5]) {10, 9, 0, -10, -9}, 5) == 0);
  CHECK(sum((int32_t[5]) {-1, -1, -1, -1, -1}, 5) == -5);
  CHECK(sum((int32_t[4]) {12, -1, 10, -1}, 4) == 20);
}


TEST_CASE("empty array", "[product]") {
  REQUIRE(product((int32_t[0]) {}, 0) == 1);
  // callee cannot know the array is not empty
  REQUIRE(product((int32_t[2]) {3, 2}, 0) == 1);
}

TEST_CASE("single element", "[product]") {
  CHECK(product((int32_t[1]) {3}, 1) == 3);
  CHECK(product((int32_t[1]) {-1234}, 1) == -1234);
}

TEST_CASE("positive only", "[product]") {
  CHECK(product((int32_t[5]) {1, 2, 3, 4, 5}, 5) == 120);
  CHECK(product((int32_t[5]) {1, 1, 1, 1, 1}, 5) == 1);
  CHECK(product((int32_t[3]) {99, 1, 0}, 3) == 99);
  CHECK(product((int32_t[5]) {2, 4, 6, 8, 10}, 5) == 3840);
}

TEST_CASE("mixing positive and negative", "[product]") {
  CHECK(product((int32_t[5]) {10, 9, 0, -10, -9}, 5) == 0);
  CHECK(product((int32_t[5]) {-1, -1, -1, -1, -1}, 5) == -1);
  CHECK(product((int32_t[4]) {12, -1, 10, -1}, 4) == 120);
}


TEST_CASE("single element", "[min]") {
  CHECK(min((int32_t[1]) {3}, 1) == 3);
  CHECK(min((int32_t[1]) {-1234}, 1) == -1234);
}

TEST_CASE("positive only", "[min]") {
  CHECK(min((int32_t[5]) {1, 2, 3, 4, 5}, 5) == 1);
  CHECK(min((int32_t[5]) {1, 1, 1, 1, 1}, 5) == 1);
  CHECK(min((int32_t[3]) {99, 1, 0}, 3) == 0);
  CHECK(min((int32_t[5]) {2, 4, 6, 8, 10}, 5) == 2);
}

TEST_CASE("mixing positive and negative", "[min]") {
  CHECK(min((int32_t[5]) {10, 9, 0, -10, -9}, 5) == -10);
  CHECK(min((int32_t[5]) {-1, -1, -1, -1, -1}, 5) == -1);
  CHECK(min((int32_t[4]) {12, -5, 10, -1}, 4) == -5);
}


TEST_CASE("single element", "[max]") {
  CHECK(max((int32_t[1]) {3}, 1) == 3);
  CHECK(max((int32_t[1]) {-1234}, 1) == -1234);
}

TEST_CASE("positive only", "[max]") {
  CHECK(max((int32_t[5]) {1, 2, 3, 4, 5}, 5) == 5);
  CHECK(max((int32_t[5]) {1, 1, 1, 1, 1}, 5) == 1);
  CHECK(max((int32_t[3]) {99, 1, 0}, 3) == 99);
  CHECK(max((int32_t[5]) {2, 4, 6, 8, 10}, 5) == 10);
}

TEST_CASE("mixing positive and negative", "[max]") {
  CHECK(max((int32_t[5]) {10, 9, 0, -10, -9}, 5) == 10);
  CHECK(max((int32_t[5]) {-1, -1, -1, -1, -1}, 5) == -1);
  CHECK(max((int32_t[4]) {12, -5, 10, -1}, 4) == 12);
}


TEST_CASE("empty array", "[count]") {
  REQUIRE(count((int32_t[0]) {}, 0, 10) == 0);
  // callee cannot know the array is not empty
  REQUIRE(count((int32_t[2]) {3, 2}, 0, 3) == 0);
}

TEST_CASE("single element", "[count]") {
  CHECK(count((int32_t[1]) {3}, 1, 3) == 1);
  CHECK(count((int32_t[1]) {3}, 1, 2) == 0);
  CHECK(count((int32_t[1]) {-1234}, 1, 1234) == 0);
  CHECK(count((int32_t[1]) {-1234}, 1, -1234) == 1);
}

TEST_CASE("positive only", "[count]") {
  CHECK(count((int32_t[5]) {1, 2, 3, 4, 5}, 5, 1) == 1);
  CHECK(count((int32_t[5]) {1, 1, 1, 1, 1}, 5, 1) == 5);
  CHECK(count((int32_t[3]) {99, 1, 0}, 3, 99) == 1);
  CHECK(count((int32_t[5]) {2, 4, 6, 8, 10}, 5, 5) == 0);
}

TEST_CASE("mixing positive and negative", "[count]") {
  CHECK(count((int32_t[5]) {10, 9, 0, -10, -9}, 5, 10) == 1);
  CHECK(count((int32_t[5]) {-1, -1, -1, -1, -1}, 5, -1) == 5);
  CHECK(count((int32_t[4]) {12, -1, 10, -1}, 4, -1) == 2);
}


TEST_CASE("single element", "[mean]") {
  CHECK_THAT(mean((int32_t[1]) {3}, 1),
    Catch::Matchers::WithinAbs(3.0, 0.000001));
  CHECK_THAT(mean((int32_t[1]) {-1234}, 1),
    Catch::Matchers::WithinAbs(-1234.0, 0.000001));
}

TEST_CASE("positive only", "[mean]") {
  CHECK_THAT(mean((int32_t[5]) {1, 2, 3, 4, 5}, 5),
    Catch::Matchers::WithinAbs(3.0, 0.000001));
  CHECK_THAT(mean((int32_t[5]) {1, 1, 1, 1, 1}, 5),
    Catch::Matchers::WithinAbs(1.0, 0.000001));
  CHECK_THAT(mean((int32_t[3]) {99, 1, 0}, 3),
    Catch::Matchers::WithinAbs(33.333, 0.001));
  CHECK_THAT(mean((int32_t[5]) {2, 4, 6, 8, 10}, 5),
    Catch::Matchers::WithinAbs(6.0, 0.000001));
}

TEST_CASE("mixing positive and negative", "[mean]") {
  CHECK_THAT(mean((int32_t[5]) {10, 9, 0, -10, -9}, 5),
    Catch::Matchers::WithinAbs(0.0, 0.000001));
  CHECK_THAT(mean((int32_t[5]) {-1, -1, -1, -1, -1}, 5),
    Catch::Matchers::WithinAbs(-1.0, 0.000001));
  CHECK_THAT(mean((int32_t[4]) {12, -5, 10, -1}, 4),
    Catch::Matchers::WithinAbs(4.0, 0.000001));
}


TEST_CASE("positive only", "[variance]") {
  CHECK_THAT(variance((int32_t[5]) {1, 2, 3, 4, 5}, 5),
    Catch::Matchers::WithinAbs(2.5, 0.000001));
  CHECK_THAT(variance((int32_t[5]) {1, 1, 1, 1, 1}, 5),
    Catch::Matchers::WithinAbs(0.0, 0.000001));
  CHECK_THAT(variance((int32_t[3]) {99, 1, 0}, 3),
    Catch::Matchers::WithinAbs(3234.333333333333, 0.001));
  CHECK_THAT(variance((int32_t[5]) {2, 4, 6, 8, 10}, 5),
    Catch::Matchers::WithinAbs(10.0, 0.000001));
}

TEST_CASE("mixing positive and negative", "[variance]") {
  CHECK_THAT(variance((int32_t[5]) {10, 9, 0, -10, -9}, 5),
    Catch::Matchers::WithinAbs(90.5, 0.000001));
  CHECK_THAT(variance((int32_t[5]) {-1, -1, -1, -1, -1}, 5),
    Catch::Matchers::WithinAbs(-0.0, 0.000001));
  CHECK_THAT(variance((int32_t[4]) {12, -5, 10, -1}, 4),
    Catch::Matchers::WithinAbs(68.6666666666666, 0.000001));
}


bool array_equal(const int32_t first[], const int32_t second[], size_t count) {
  for (size_t i = 0; i < count; ++i) {
    if (first[i] != second[i]) return false;
  }
  return true;
}

TEST_CASE("empty base array", "[subarray]") {

  int32_t actual[] = {-1, -1, -1, -1, -1};
  std::vector<int32_t> expected{-1, -1, -1, -1, -1};
  subarray((int32_t[0]) {}, 0, 0, actual);
  std::vector<int32_t> actual_v(actual, actual + sizeof(actual) / sizeof(int32_t));
  CHECK_THAT(actual_v,
    Catch::Matchers::Equals(expected));
}

TEST_CASE("single element", "[subarray]") {
  int32_t actual[] = {0, 0, 0, 0, 0};

    CHECK_THAT(array_equal(subarray((int32_t[1]) {3}, 0, 0, actual),
      (int32_t[5]) {0, 0, 0, 0, 0}, 5));
    CHECK_THAT(array_equal(subarray((int32_t[1]) {3}, 0, 1, actual),
      (int32_t[5]) {3, 0, 0, 0, 0}, 5));
}

TEST_CASE("regular array", "[subarray]") {
  int32_t actual[] = {0, 0, 0, 0, 0};

  SECTION("copy empty selection of elements") {
    CHECK_THAT(array_equal(subarray((int32_t[5]) {1, 2, 3, 4, 5}, 0, 0, actual),
      (int32_t[5]) {0, 0, 0, 0, 0}, 5));
    CHECK_THAT(array_equal(subarray((int32_t[5]) {1, 2, 3, 4, 5}, 3, 3, actual),
      (int32_t[5]) {0, 0, 0, 0, 0}, 5));
  }

  SECTION("copy single element") {
    CHECK_THAT(array_equal(subarray((int32_t[5]) {1, 2, 3, 4, 5}, 0, 1, actual),
      (int32_t[5]) {1, 0, 0, 0, 0}, 5));
    CHECK_THAT(array_equal(subarray((int32_t[5]) {1, 2, 3, 4, 5}, 3, 4, actual),
      (int32_t[5]) {4, 0, 0, 0, 0}, 5));
    CHECK_THAT(array_equal(subarray((int32_t[5]) {1, 2, 3, 4, 5}, 4, 5, actual),
      (int32_t[5]) {5, 0, 0, 0, 0}, 5));
  }

  SECTION("copy proper slice") {
    CHECK_THAT(array_equal(subarray((int32_t[5]) {1, 2, 3, 4, 5}, 2, 5, actual),
      (int32_t[5]) {3, 4, 5, 0, 0}, 5));
    CHECK_THAT(array_equal(subarray((int32_t[5]) {1, 2, 3, 4, 5}, 1, 3, actual),
      (int32_t[5]) {2, 3, 0, 0, 0}, 5));
    CHECK_THAT(array_equal(subarray((int32_t[5]) {-5, -4, -3}, 0, 3, actual),
      (int32_t[5]) {-5, -4, -3, 0, 0}, 5));
  }
}

