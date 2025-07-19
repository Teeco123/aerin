#include "aerin.h"

class Sandbox : public Aerin::App {
public:
  Sandbox() {}
  ~Sandbox() {}
};

int main() {
  Sandbox *sandbox = new Sandbox();
  sandbox->Run();
  delete sandbox;
}
