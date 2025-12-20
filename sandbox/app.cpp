#include "core/app.hpp"

int main() {
  Aerin::AppSpecs specs;
  specs.name = "Sandbox";
  specs.windowSpecs.title = "Sandbox window";
  specs.windowSpecs.width = 1920;
  specs.windowSpecs.height = 1080;

  Aerin::App app(specs);
  app.Start();
};
