namespace Aerin {
  struct Vec2 {
    float x, y;

    Vec2(float x, float y) : x(x), y(y) {};

    Vec2 Add(const Vec2 &other) const {
      return Vec2(x + other.x, y + other.y);
    };

    Vec2 Subtract(const Vec2 &other) const {
      return Vec2(x - other.x, y - other.y);
    };

    float Dot(const Vec2 &other) const {
      return float((x * other.x) + (y * other.y));
    };

    Vec2 Cross(const float &other) const {
      return Vec2(x * other, y * other);
    };

    bool Equals(const Vec2 &other) const {
      return x == other.x && y == other.y;
    };

    Vec2 operator+(const Vec2 &other) const {
      return Add(other);
    };

    Vec2 operator-(const Vec2 &other) const {
      return Subtract(other);
    };

    float operator*(const Vec2 &other) const {
      return Dot(other);
    };

    bool operator==(const Vec2 &other) const {
      return Equals(other);
    };
  };

} // namespace Aerin
