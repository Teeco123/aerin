#pragma once

#include "core/ecs/entity.hpp"
#include <queue>

namespace Aerin {

class ECSRegistry {
public:
  ECSRegistry() = default;
  ~ECSRegistry() = default;

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
    return Entity(id, this);
  };

  void DestroyEntity(Entity entity) { m_availableEntityID.push(entity.id); };

private:
  std::queue<EntityID> m_availableEntityID;
  EntityID aliveEntities = 0;
};
} // namespace Aerin
