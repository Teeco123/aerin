#pragma once

#include "math/vec3.hpp"
#include <cmath>

namespace Aerin {

  struct Mat4 {
    float m[16];

    Mat4() {
      for (int i = 0; i < 16; ++i) {
        m[i] = 0.0f;
      }
      m[0] = 1.0f;
      m[5] = 1.0f;
      m[10] = 1.0f;
      m[15] = 1.0f;
    };

    static Mat4 Identity() {
      return Mat4();
    };

    Mat4 operator*(const Mat4 &other) const {
      Mat4 res;
      for (int col = 0; col < 4; ++col) {
        for (int row = 0; row < 4; ++row) {
          res.m[col * 4 + row] = (m[0 * 4 + row] * other.m[col * 4 + 0]) +
                                 (m[1 * 4 + row] * other.m[col * 4 + 1]) +
                                 (m[2 * 4 + row] * other.m[col * 4 + 2]) +
                                 (m[3 * 4 + row] * other.m[col * 4 + 3]);
        }
      }
      return res;
    };

    Vec3 operator*(const Vec3 &v) const {
      float x = (m[0] * v.x) + (m[4] * v.y) + (m[8] * v.z) + (m[12] * 1.0f);
      float y = (m[1] * v.x) + (m[5] * v.y) + (m[9] * v.z) + (m[13] * 1.0f);
      float z = (m[2] * v.x) + (m[6] * v.y) + (m[10] * v.z) + (m[14] * 1.0f);

      return Vec3(x, y, z);
    };

    static Mat4 Translate(const Vec3 &v) {
      Mat4 res = Identity();
      res.m[12] = v.x;
      res.m[13] = v.y;
      res.m[14] = v.z;
      return res;
    };

    static Mat4 Scale(const Vec3 &v) {
      Mat4 res = Identity();
      res.m[0] = v.x;
      res.m[5] = v.y;
      res.m[10] = v.z;
      return res;
    };

    static Mat4 RotateX(float angleRadians) {
      Mat4 res = Identity();
      float c = std::cos(angleRadians);
      float s = std::sin(angleRadians);
      res.m[5] = c;
      res.m[9] = -s;
      res.m[6] = s;
      res.m[10] = c;
      return res;
    };

    static Mat4 RotateY(float angleRadians) {
      Mat4 res = Identity();
      float c = std::cos(angleRadians);
      float s = std::sin(angleRadians);
      res.m[0] = c;
      res.m[8] = s;
      res.m[2] = -s;
      res.m[10] = c;
      return res;
    };

    static Mat4 RotateZ(float angleRadians) {
      Mat4 res = Identity();
      float c = std::cos(angleRadians);
      float s = std::sin(angleRadians);
      res.m[0] = c;
      res.m[4] = -s;
      res.m[1] = s;
      res.m[5] = c;
      return res;
    };
  };

} // namespace Aerin
