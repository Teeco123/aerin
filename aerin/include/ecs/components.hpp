#pragma once

#include <cstdint>

namespace Aerin {
  using ComponentType = std::uint8_t;
  const ComponentType MAX_COMPONENTS = 32;

  struct Position {
    float x;
    float y;
    float z;
  };
} // namespace Aerin
