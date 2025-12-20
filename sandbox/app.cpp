#include "core/app.hpp"

int main() {
  Aerin::AppSpecs specs;
  specs.name = "Sandbox";
  specs.fixedUpdateSeconds = 0.032;
  specs.windowSpecs.title = "Sandbox window";
  specs.windowSpecs.width = 1920;
  specs.windowSpecs.height = 1080;
  specs.windowSpecs.vsync = false;

  Aerin::App app(specs);
  app.Start();
};
