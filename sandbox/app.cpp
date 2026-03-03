#include "core/app.hpp"
#include "ecs/components.hpp"

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
  ecs.DestroyEntity(0);

  ecs.CreateEntity();
  ecs.CreateEntity();
  ecs.CreateEntity();
  ecs.CreateEntity();
  ecs.CreateEntity();
  ecs.CreateEntity();
  ecs.CreateEntity();
  ecs.CreateEntity();
  ecs.CreateEntity();

  ecs.AddComponent(0, Aerin::Position());
  ecs.AddComponent(2, Aerin::Position());
  ecs.AddComponent(4, Aerin::Position());
  ecs.AddComponent(8, Aerin::Position());

  app.Start();
};
