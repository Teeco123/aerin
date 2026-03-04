#include "core/app.hpp"
#include "ecs/components.hpp"
#include <print>

int main() {
  Aerin::AppSpecs specs;
  specs.name = "Sandbox";
  specs.fixedUpdateSeconds = 0.032;
  specs.windowSpecs.title = "Sandbox window";
  specs.windowSpecs.width = 1920;
  specs.windowSpecs.height = 1080;
  specs.windowSpecs.vsync = false;

  Aerin::App app(specs);
  Aerin::ECS &ecs = app.GetECS();

  ecs.RegisterComponent<Aerin::Position>();

  ecs.CreateEntity();
  ecs.CreateEntity();
  ecs.CreateEntity();

  ecs.DestroyEntity(1);

  ecs.CreateEntity();
  ecs.CreateEntity();
  ecs.CreateEntity();

  ecs.InsertComponent<Aerin::Position>(3);

  if (ecs.HasComponent<Aerin::Position>(3)) {
    std::print("HasComponent id 3");
  };

  if (ecs.HasComponent<Aerin::Position>(2)) {
    std::print("HasComponent id 2");
  };

  app.Start();
};
