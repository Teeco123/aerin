#pragma once

#include <cstdint>

namespace Aerin {

using EntityID = uint32_t;

class EntityManager;

class Entity {
public:
  EntityID id;
  EntityManager *manager;

  Entity(EntityID id, EntityManager *manager) : id(id), manager(manager) {};
};
} // namespace Aerin
