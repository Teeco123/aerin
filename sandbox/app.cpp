#include "core/app.hpp"
#include "ecs/components-array.hpp"
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
  Aerin::ComponentArray<Aerin::Position> positionArray(1024);

  ecs.CreateEntity();
  ecs.DestroyEntity(0);

  ecs.CreateEntity();
  ecs.CreateEntity();
  ecs.CreateEntity();

  positionArray.InsertComponent(0, Aerin::Position());
  positionArray.InsertComponent(2, Aerin::Position());

  app.Start();
};
