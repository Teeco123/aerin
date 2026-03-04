#pragma once

#include "ecs/components-manager.hpp"
#include "ecs/entity-manager.hpp"

#include <cstdint>
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

  public:
    EntityManager &GetEntityManager() {
      return *m_entityManager;
    };

    Entity CreateEntity() {
      return m_entityManager->CreateEntity();
    };

    void DestroyEntity(Entity id) {
      m_entityManager->DestroyEntity(id);
    };

    uint32_t AliveEntities() {
      return m_entityManager->AliveEntities();
    };

  public:
    ComponentManager &GetComponentManager() {
      return *m_componentManager;
    };

    template <typename T> void RegisterComponent() {
      m_componentManager->RegisterComponent<T>();
    };

    template <typename T> void InsertComponent(Entity id, T component) {
      m_componentManager->InsertComponent(id, component);
    };

    template <typename T> void InsertComponent(Entity id) {
      m_componentManager->InsertComponent<T>(id);
    };

    template <typename T> bool HasComponent(Entity id) {
      return m_componentManager->HasComponent<T>(id);
    };

  private:
    std::unique_ptr<EntityManager> m_entityManager;
    std::unique_ptr<ComponentManager> m_componentManager;
  };
}; // namespace Aerin
