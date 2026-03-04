#pragma once

#include <cstdint>
#include <queue>

namespace Aerin {
  using Entity = uint32_t;

  class EntityManager {
  public:
    EntityManager() = default;
    ~EntityManager() = default;

    Entity CreateEntity() {
      // Re-use recycled entity id
      if (!m_available.empty()) {
        Entity id = m_available.front();
        m_available.pop();
        return id;
      }

      // If no recycled entity id create new one
      m_entities++;
      Entity id = m_entities;
      return id;
    };

    void DestroyEntity(Entity id) {
      m_available.push(id);
    };

    uint32_t AliveEntities() {
      return m_entities;
    };

  private:
    std::uint32_t m_entities;
    std::queue<Entity> m_available;
  };
} // namespace Aerin
