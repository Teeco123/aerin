#include "math/vec2.hpp"
#include "glm/glm.hpp"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators_adapters.hpp>
#include <catch2/generators/catch_generators_random.hpp>
#include <glm/geometric.hpp>

TEST_CASE("Vec2 Operations", "[Vec2]") {
  auto data = GENERATE(take(10, chunk(5, random<float>(-100.0f, 100.0f))));

  const float x1 = data[0], y1 = data[1];
  const float x2 = data[2], y2 = data[3];
  const float s = data[4];

  const Aerin::Vec2 a(x1, y1);
  const Aerin::Vec2 b(x2, y2);
  const glm::vec2 ga(x1, y1);
  const glm::vec2 gb(x2, y2);

  SECTION("Addition") {
    Aerin::Vec2 res = a + b;
    glm::vec2 gRes = ga + gb;
    CAPTURE(a.x, a.y, b.x, b.y, s);

    CHECK(res.x == Catch::Approx(gRes.x));
    CHECK(res.y == Catch::Approx(gRes.y));
  }

  SECTION("Subtraction") {
    Aerin::Vec2 res = a - b;
    glm::vec2 gRes = ga - gb;
    CAPTURE(a.x, a.y, b.x, b.y, s);

    CHECK(res.x == Catch::Approx(gRes.x));
    CHECK(res.y == Catch::Approx(gRes.y));
  }

  SECTION("Multiplication") {
    Aerin::Vec2 res = a * s;
    glm::vec2 gRes = ga * s;
    CAPTURE(a.x, a.y, b.x, b.y, s);

    CHECK(res.x == Catch::Approx(gRes.x));
    CHECK(res.y == Catch::Approx(gRes.y));
  }

  SECTION("Division") {
    if (std::abs(s) > 0.0001f) {
      Aerin::Vec2 res = a / s;
      glm::vec2 gRes = ga / s;
      CAPTURE(a.x, a.y, b.x, b.y, s);

      CHECK(res.x == Catch::Approx(gRes.x));
      CHECK(res.y == Catch::Approx(gRes.y));
    }
  }

  SECTION("Dot") {
    float res = a.Dot(b);
    float gRes = glm::dot(ga, gb);
    CAPTURE(a.x, a.y, b.x, b.y, s);

    CHECK(res == Catch::Approx(gRes));
  }

  SECTION("Magnitude") {
    float res = a.Magnitude();
    float gRes = glm::length(ga);
    CAPTURE(a.x, a.y, b.x, b.y, s);

    CHECK(res == Catch::Approx(gRes));
  }

  SECTION("Normalize") {
    Aerin::Vec2 res = a.Normalize();
    glm::vec2 gRes = glm::normalize(ga);
    CAPTURE(a.x, a.y, b.x, b.y, s);

    CHECK(res.x == Catch::Approx(gRes.x));
    CHECK(res.y == Catch::Approx(gRes.y));
  }

  SECTION("Distance To") {
    float res = a.DistanceTo(b);
    float gRes = glm::distance(ga, gb);
    CAPTURE(a.x, a.y, b.x, b.y, s);

    CHECK(res == Catch::Approx(gRes));
    CHECK(res == Catch::Approx(gRes));
  }

  SECTION("Direction To") {
    Aerin::Vec2 res = a.DirectionTo(b);
    glm::vec2 gRes = glm::normalize(gb - ga);
    CAPTURE(a.x, a.y, b.x, b.y, s);

    CHECK(res.x == Catch::Approx(gRes.x));
    CHECK(res.y == Catch::Approx(gRes.y));
  }
}
