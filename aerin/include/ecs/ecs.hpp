#include "ecs/entity-manager.hpp"
#include "ecs/entity.hpp"
#include <memory>

namespace Aerin {
  class ECS {
  public:
    static std::unique_ptr<ECS> Init() {
      auto ecs = std::make_unique<ECS>();
      ecs->m_entityManager = EntityManager();

      return ecs;
    };

    Entity CreateEntity() {
      return m_entityManager.CreateEntity();
    };

    void DestroyEntity(EntityID id) {
      return m_entityManager.DestroyEntity(id);
    };

    EntityManager &GetEntityManager() {
      return m_entityManager;
    };

  private:
    EntityManager m_entityManager;
  };
}; // namespace Aerin
