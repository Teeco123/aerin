#include <cmath>

namespace Aerin {
  struct Vec3 {
    float x, y, z;

    Vec3(float x, float y, float z) : x(x), y(y), z(z) {};

    Vec3 Zero() const {
      return Vec3(0.0f, 0.0f, 0.0f);
    };

    float Dot(const Vec3 &other) const {
      return (x * other.x) + (y * other.y) + (z * other.z);
    };

    Vec3 Cross(const Vec3 &other) const {
      return Vec3((y * other.z) - (z * other.y), (z * other.x) - (x * other.z),
                  (x * other.y) - (y * other.x));
    };

    float Magnitude() const {
      return std::sqrt(MagnitudeSquared());
    };

    float MagnitudeSquared() const {
      return (x * x) + (y * y) + (z * z);
    };

    Vec3 Normalize() const {
      return Vec3(x / Magnitude(), y / Magnitude(), z / Magnitude());
    };

    float DistanceTo(const Vec3 &other) const {
      return std::sqrt(((x - other.x) * (x - other.x)) +
                       ((y - other.y) * (y - other.y)) +
                       ((z - other.z) * (z - other.z)));
    };

    Vec3 DirectionTo(const Vec3 &other) const {
      return (other - *this).Normalize();
    };

    Vec3 operator+(const Vec3 &other) const {
      return Vec3(x + other.x, y + other.y, z + other.z);
    };

    Vec3 operator-(const Vec3 &other) const {
      return Vec3(x - other.x, y - other.y, z - other.z);
    };

    Vec3 operator*(const float &other) const {
      return Vec3(other * x, other * y, other * z);
    };

    Vec3 operator/(const float &other) const {
      return Vec3(x / other, y / other, z / other);
    };

    bool operator==(const Vec3 &other) const {
      return x == other.x && y == other.y && z == other.z;
    };
  };

} // namespace Aerin
