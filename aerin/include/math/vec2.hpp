#include <cmath>

namespace Aerin {
  struct Vec2 {
    float x, y;

    Vec2(float x, float y) : x(x), y(y) {};

    Vec2 Zero() const {
      return Vec2(0.0f, 0.0f);
    };

    float Dot(const Vec2 &other) const {
      return (x * other.x) + (y * other.y);
    };

    float Magnitude() const {
      return std::sqrt(MagnitudeSquared());
    };

    float MagnitudeSquared() const {
      return (x * x) + (y * y);
    };

    Vec2 Normalize() const {
      return Vec2(x / Magnitude(), y / Magnitude());
    };

    float DistanceTo(const Vec2 &other) const {
      return std::sqrt(((x - other.x) * (x - other.x)) +
                       ((y - other.y) * (y - other.y)));
    };

    Vec2 DirectionTo(const Vec2 &other) const {
      return (other - *this).Normalize();
    };

    Vec2 operator+(const Vec2 &other) const {
      return Vec2(x + other.x, y + other.y);
    };

    Vec2 operator-(const Vec2 &other) const {
      return Vec2(x - other.x, y - other.y);
    };

    Vec2 operator*(const float &other) const {
      return Vec2(other * x, other * y);
    };

    Vec2 operator/(const float &other) const {
      return Vec2(x / other, y / other);
    };

    bool operator==(const Vec2 &other) const {
      return x == other.x && y == other.y;
    };
  };

} // namespace Aerin
