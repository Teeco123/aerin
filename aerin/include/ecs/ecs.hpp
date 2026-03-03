#include "ecs/components-manager.hpp"
#include "ecs/entity-manager.hpp"
#include "ecs/entity.hpp"
#include <memory>

namespace Aerin {
  class ECS {
  public:
    static std::unique_ptr<ECS> Init() {
      auto ecs = std::make_unique<ECS>();
      ecs->m_entityManager = std::make_unique<EntityManager>();
      ecs->m_componentManager = std::make_unique<ComponentManager>();

      return ecs;
    };

    Entity CreateEntity() {
      return m_entityManager->CreateEntity();
    };

    void DestroyEntity(EntityID id) {
      return m_entityManager->DestroyEntity(id);
    };

    EntityManager &GetEntityManager() {
      return *m_entityManager;
    };

    template <typename T> void RegisterComponent() {
      return m_componentManager->RegisterComponent<T>();
    };

    template <typename T> void AddComponent(EntityID id, T component) {
      return m_componentManager->AddComponent(id, component);
    };

    ComponentManager &GetComponentManager() {
      return *m_componentManager;
    };

  private:
    std::unique_ptr<EntityManager> m_entityManager;
    std::unique_ptr<ComponentManager> m_componentManager;
  };
}; // namespace Aerin
