#pragma once

#include "ecs/components.hpp"

#include <bitset>
#include <cstdint>
#include <queue>

namespace Aerin {
  using Entity = uint32_t;
  using EntitySignature = std::bitset<32>;

  class EntityManager {
  public:
    EntityManager() {
      m_signatures.resize(32);
    };

    ~EntityManager() = default;

  public:
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

    void UpdateSignatureOnInsert(Entity id, ComponentType componentType) {
      m_signatures[id].set(componentType);
    };

    uint32_t AliveEntities() {
      return m_entities;
    };

  private:
    std::uint32_t m_entities;
    std::vector<EntitySignature> m_signatures;
    std::queue<Entity> m_available;
  };
} // namespace Aerin
