#include "core/app.hpp"
#include "aerin.hpp"

class Sandbox : public Aerin::App {
public:
  Sandbox(Aerin::AppSpecs &specs) : Aerin::App(specs) {}
  ~Sandbox() override {}
};

int main() {
  Aerin::AppSpecs specs;
  specs.name = "Sandbox";
  Sandbox sandbox(specs);
  sandbox.Run();
}
