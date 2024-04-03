#include "rot13.hpp"

#include <cstdint>

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>

TEST_CASE("rot13 encryption", "[encrypt]") {
  CHECK_THAT(rot13::encrypt("apt-get moo"),
    Catch::Matchers::Equals("ncg-trg zbb"));
  CHECK_THAT(rot13::encrypt("apt-build moo"),
    Catch::Matchers::Equals("ncg-ohvyq zbb"));
  CHECK_THAT(rot13::encrypt("ncg-trg zbb"),
    Catch::Matchers::Equals("apt-get moo"));
  CHECK_THAT(rot13::encrypt("ncg-ohvyq zbb"),
    Catch::Matchers::Equals("apt-build moo"));
}

TEST_CASE("rot13 'decryption'", "[decrypt]") {
  CHECK_THAT(rot13::encrypt("apt-get moo"),
    Catch::Matchers::Equals("ncg-trg zbb"));
  CHECK_THAT(rot13::encrypt("apt-build moo"),
    Catch::Matchers::Equals("ncg-ohvyq zbb"));
  CHECK_THAT(rot13::encrypt("ncg-trg zbb"),
    Catch::Matchers::Equals("apt-get moo"));
  CHECK_THAT(rot13::encrypt("ncg-ohvyq zbb"),
    Catch::Matchers::Equals("apt-build moo"));
}

