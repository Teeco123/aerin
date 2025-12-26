#include "math/vec3.hpp"
#include "glm/glm.hpp"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators_adapters.hpp>
#include <catch2/generators/catch_generators_random.hpp>
#include <glm/geometric.hpp>

TEST_CASE("Vec3 Operations", "[Vec3]") {
  auto data = GENERATE(take(10, chunk(7, random<float>(-100.0f, 100.0f))));

  const float x1 = data[0], y1 = data[1], z1 = data[2];
  const float x2 = data[3], y2 = data[4], z2 = data[5];
  const float s = data[6];

  const Aerin::Vec3 a(x1, y1, z1);
  const Aerin::Vec3 b(x2, y2, z2);
  const glm::vec3 ga(x1, y1, z1);
  const glm::vec3 gb(x2, y2, z2);

  SECTION("Addition") {
    Aerin::Vec3 res = a + b;
    glm::vec3 gRes = ga + gb;
    CAPTURE(a.x, a.y, a.z, b.x, b.y, b.z, s);

    CHECK(res.x == Catch::Approx(gRes.x));
    CHECK(res.y == Catch::Approx(gRes.y));
    CHECK(res.z == Catch::Approx(gRes.z));
  }

  SECTION("Subtraction") {
    Aerin::Vec3 res = a - b;
    glm::vec3 gRes = ga - gb;
    CAPTURE(a.x, a.y, a.z, b.x, b.y, b.z, s);

    CHECK(res.x == Catch::Approx(gRes.x));
    CHECK(res.y == Catch::Approx(gRes.y));
    CHECK(res.z == Catch::Approx(gRes.z));
  }

  SECTION("Multiplication") {
    Aerin::Vec3 res = a * s;
    glm::vec3 gRes = ga * s;
    CAPTURE(a.x, a.y, a.z, b.x, b.y, b.z, s);

    CHECK(res.x == Catch::Approx(gRes.x));
    CHECK(res.y == Catch::Approx(gRes.y));
    CHECK(res.z == Catch::Approx(gRes.z));
  }

  SECTION("Division") {
    if (std::abs(s) > 0.0001f) {
      Aerin::Vec3 res = a / s;
      glm::vec3 gRes = ga / s;
      CAPTURE(a.x, a.y, a.z, b.x, b.y, b.z, s);

      CHECK(res.x == Catch::Approx(gRes.x));
      CHECK(res.y == Catch::Approx(gRes.y));
      CHECK(res.z == Catch::Approx(gRes.z));
    }
  }

  SECTION("Dot") {
    float res = a.Dot(b);
    float gRes = glm::dot(ga, gb);
    CAPTURE(a.x, a.y, a.z, b.x, b.y, b.z, s);

    CHECK(res == Catch::Approx(gRes));
  }

  SECTION("Cross") {
    Aerin::Vec3 res = a.Cross(b);
    glm::vec3 gRes = glm::cross(ga, gb);
    CAPTURE(a.x, a.y, a.z, b.x, b.y, b.z, s);

    CHECK(res.x == Catch::Approx(gRes.x));
    CHECK(res.y == Catch::Approx(gRes.y));
    CHECK(res.z == Catch::Approx(gRes.z));
  }

  SECTION("Magnitude") {
    float res = a.Magnitude();
    float gRes = glm::length(ga);
    CAPTURE(a.x, a.y, a.z, b.x, b.y, b.z, s);

    CHECK(res == Catch::Approx(gRes));
  }

  SECTION("Normalize") {
    Aerin::Vec3 res = a.Normalize();
    glm::vec3 gRes = glm::normalize(ga);
    CAPTURE(a.x, a.y, a.z, b.x, b.y, b.z, s);

    CHECK(res.x == Catch::Approx(gRes.x));
    CHECK(res.y == Catch::Approx(gRes.y));
    CHECK(res.z == Catch::Approx(gRes.z));
  }

  SECTION("Distance To") {
    float res = a.DistanceTo(b);
    float gRes = glm::distance(ga, gb);
    CAPTURE(a.x, a.y, a.z, b.x, b.y, b.z, s);

    CHECK(res == Catch::Approx(gRes));
  }

  SECTION("Direction To") {
    Aerin::Vec3 res = a.DirectionTo(b);
    glm::vec3 gRes = glm::normalize(gb - ga);
    CAPTURE(a.x, a.y, a.z, b.x, b.y, b.z, s);

    CHECK(res.x == Catch::Approx(gRes.x));
    CHECK(res.y == Catch::Approx(gRes.y));
    CHECK(res.z == Catch::Approx(gRes.z));
  }
}
