#include "core/app.hpp"
#include "ecs/entity-manager.hpp"
#include "ecs/entity.hpp"

int main() {
  Aerin::AppSpecs specs;
  specs.name = "Sandbox";
  specs.fixedUpdateSeconds = 0.032;
  specs.windowSpecs.title = "Sandbox window";
  specs.windowSpecs.width = 1920;
  specs.windowSpecs.height = 1080;
  specs.windowSpecs.vsync = false;

  Aerin::App app(specs);
  Aerin::EntityManager entityManager;
  Aerin::Entity id1 = entityManager.CreateEntity();
  Aerin::Entity id2 = entityManager.CreateEntity();
  Aerin::Entity id3 = entityManager.CreateEntity();
  Aerin::Entity id4 = entityManager.CreateEntity();
  Aerin::Entity id5 = entityManager.CreateEntity();
  entityManager.DestroyEntity(id3);

  Aerin::Entity id6 = entityManager.CreateEntity();
  app.Start();
};
