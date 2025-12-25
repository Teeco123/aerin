#include "math/vec2.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Vector 2 math", "[math][vector2]") {
  Aerin::Vec2 vector1(10.0f, 10.0f);
  Aerin::Vec2 vector2(10.0f, 10.0f);

  REQUIRE(vector1 + vector2 == Aerin::Vec2(20.0f, 20.0f));
};
