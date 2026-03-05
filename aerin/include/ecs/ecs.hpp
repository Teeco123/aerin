#pragma once

#include "ecs/components-manager.hpp"
#include "ecs/components.hpp"
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

    ComponentManager &GetComponentManager() {
      return *m_componentManager;
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

    template <typename T> void RegisterComponent() {
      m_componentManager->RegisterComponent<T>();
    };

    template <typename T> void InsertComponent(Entity id, T component) {
      ComponentType componentType = m_componentManager->GetComponentType<T>();
      m_componentManager->InsertComponent(id, component);
      m_entityManager->UpdateSignatureOnInsert(id, componentType);
    };

    template <typename T> void InsertComponent(Entity id) {
      ComponentType componentType = m_componentManager->GetComponentType<T>();
      m_componentManager->InsertComponent<T>(id);
      m_entityManager->UpdateSignatureOnInsert(id, componentType);
    };

    template <typename T> bool HasComponent(Entity id) {
      return m_componentManager->HasComponent<T>(id);
    };

  private:
    std::unique_ptr<EntityManager> m_entityManager;
    std::unique_ptr<ComponentManager> m_componentManager;
  };
}; // namespace Aerin
