#include "math/mat4.hpp"
#include "math/vec3.hpp"
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators_adapters.hpp>
#include <catch2/generators/catch_generators_random.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#define CHECK_MAT4_APPROX(myMat, gMat)                                         \
  for (int col = 0; col < 4; ++col) {                                          \
    for (int row = 0; row < 4; ++row) {                                        \
      CHECK(myMat.m[col * 4 + row] ==                                          \
            Catch::Approx(gMat[col][row]).margin(0.0001f));                    \
    }                                                                          \
  }

TEST_CASE("Mat4 Operations", "[Mat4]") {
  auto data = GENERATE(take(10, chunk(7, random<float>(-10.0f, 10.0f))));

  const float x1 = data[0], y1 = data[1], z1 = data[2];
  const float x2 = data[3], y2 = data[4], z2 = data[5];
  const float angleRadians = data[6];

  const Aerin::Vec3 v1(x1, y1, z1);
  const Aerin::Vec3 v2(x2, y2, z2);
  const glm::vec3 gv1(x1, y1, z1);
  const glm::vec3 gv2(x2, y2, z2);

  SECTION("Identity") {
    Aerin::Mat4 res = Aerin::Mat4::Identity();
    glm::mat4 gRes = glm::mat4(1.0f);

    CHECK_MAT4_APPROX(res, gRes);
  }

  SECTION("Translate") {
    Aerin::Mat4 res = Aerin::Mat4::Translate(v1);
    glm::mat4 gRes = glm::translate(glm::mat4(1.0f), gv1);

    CHECK_MAT4_APPROX(res, gRes);
  }

  SECTION("Scale") {
    Aerin::Mat4 res = Aerin::Mat4::Scale(v1);
    glm::mat4 gRes = glm::scale(glm::mat4(1.0f), gv1);

    CHECK_MAT4_APPROX(res, gRes);
  }

  SECTION("Rotate X") {
    Aerin::Mat4 res = Aerin::Mat4::RotateX(angleRadians);
    glm::mat4 gRes =
        glm::rotate(glm::mat4(1.0f), angleRadians, glm::vec3(1.0f, 0.0f, 0.0f));

    CHECK_MAT4_APPROX(res, gRes);
  }

  SECTION("Rotate Y") {
    Aerin::Mat4 res = Aerin::Mat4::RotateY(angleRadians);
    glm::mat4 gRes =
        glm::rotate(glm::mat4(1.0f), angleRadians, glm::vec3(0.0f, 1.0f, 0.0f));

    CHECK_MAT4_APPROX(res, gRes);
  }

  SECTION("Rotate Z") {
    Aerin::Mat4 res = Aerin::Mat4::RotateZ(angleRadians);
    glm::mat4 gRes =
        glm::rotate(glm::mat4(1.0f), angleRadians, glm::vec3(0.0f, 0.0f, 1.0f));

    CHECK_MAT4_APPROX(res, gRes);
  }

  SECTION("Matrix Multiplication") {
    Aerin::Mat4 t = Aerin::Mat4::Translate(v1);
    Aerin::Mat4 r = Aerin::Mat4::RotateY(angleRadians);
    Aerin::Mat4 s = Aerin::Mat4::Scale(v2);
    Aerin::Mat4 res = t * r * s;

    glm::mat4 gt = glm::translate(glm::mat4(1.0f), gv1);
    glm::mat4 gr =
        glm::rotate(glm::mat4(1.0f), angleRadians, glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 gs = glm::scale(glm::mat4(1.0f), gv2);
    glm::mat4 gRes = gt * gr * gs;

    CHECK_MAT4_APPROX(res, gRes);
  }

  SECTION("Matrix * Vector3 Multiplication") {
    Aerin::Mat4 transform = Aerin::Mat4::Translate(v1) *
                            Aerin::Mat4::RotateZ(angleRadians) *
                            Aerin::Mat4::Scale(v2);
    glm::mat4 gTransform = glm::translate(glm::mat4(1.0f), gv1) *
                           glm::rotate(glm::mat4(1.0f), angleRadians,
                                       glm::vec3(0.0f, 0.0f, 1.0f)) *
                           glm::scale(glm::mat4(1.0f), gv2);

    Aerin::Vec3 res = transform * v1;

    glm::vec4 gRes4 = gTransform * glm::vec4(gv1, 1.0f);

    CHECK(res.x == Catch::Approx(gRes4.x).margin(0.0001f));
    CHECK(res.y == Catch::Approx(gRes4.y).margin(0.0001f));
    CHECK(res.z == Catch::Approx(gRes4.z).margin(0.0001f));
  }
}

TEST_CASE("Mat4 Benchmark", "[benchmark]") {
  auto data = GENERATE(take(1, chunk(7, random<float>(-10.0f, 10.0f))));

  const Aerin::Vec3 v1(data[0], data[1], data[2]);
  const Aerin::Vec3 v2(data[3], data[4], data[5]);
  const float angleRadians = data[6];

  const Aerin::Mat4 m1 =
      Aerin::Mat4::Translate(v1) * Aerin::Mat4::RotateX(angleRadians);
  const Aerin::Mat4 m2 =
      Aerin::Mat4::Scale(v2) * Aerin::Mat4::RotateY(angleRadians);

  BENCHMARK("Identity") {
    return Aerin::Mat4::Identity();
  };

  BENCHMARK("Translate") {
    return Aerin::Mat4::Translate(v1);
  };

  BENCHMARK("Scale") {
    return Aerin::Mat4::Scale(v2);
  };

  BENCHMARK("RotateX") {
    return Aerin::Mat4::RotateX(angleRadians);
  };

  BENCHMARK("Matrix * Matrix") {
    return m1 * m2;
  };

  BENCHMARK("Matrix * Vector3") {
    return m1 * v1;
  };
};
