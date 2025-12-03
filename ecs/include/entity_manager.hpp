#pragma once

#include "entity.hpp"
#include <print>
#include <queue>

namespace Aerin {

class EntityManager {
public:
  EntityManager() = default;
  ~EntityManager() = default;

  Entity CreateEntity() {
    // Re-use recycled entity id
    if (!m_availableEntityID.empty()) {
      EntityID id = m_availableEntityID.front();
      m_availableEntityID.pop();
      return Entity(id, this);
    }

    // If no recycled entity id create new one
    EntityID id = aliveEntities;
    aliveEntities++;
    std::println("{}", aliveEntities);
    return Entity(id, this);
  };

  void DestroyEntity(Entity entity) { m_availableEntityID.push(entity.id); };

private:
  std::queue<EntityID> m_availableEntityID;
  EntityID aliveEntities = 0;
};
} // namespace Aerin
