#include "core/app.hpp"
#include <cstdio> // 1. Fixes non-standard C header
#include <memory> // 2. Required for std::unique_ptr

class Editor : public Aerin::App {
public:
  Editor() {}
  ~Editor() override {} // 3. Fixes 'override' warning
};

int main() {
  // 4. Fixes raw pointer/ownership warning (cppcoreguidelines)
  std::unique_ptr<Editor> editor = std::make_unique<Editor>();
  editor->Run();
}
