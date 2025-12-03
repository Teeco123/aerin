#pragma once

#include <cstdint>

namespace Aerin {

using EntityID = uint64_t;

class ECSRegistry;

class Entity {
public:
  EntityID id;
  ECSRegistry *registry;

  Entity(EntityID id, ECSRegistry *reg) : id(id), registry(reg) {};
};
} // namespace Aerin
