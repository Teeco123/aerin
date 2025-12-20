#include "core/app.hpp"
#include <cassert>
#include <memory>
#include <print>

namespace Aerin {

static App *s_app = nullptr;

App::App(const AppSpecs &specs) : m_specs(specs) {
  s_app = this;
  m_window->Create(specs.windowSpecs);
}
App::~App() { s_app = nullptr; }

void App::Start() {
  m_running = true;
  while (m_window->ShouldClose()) {
    std::print(".\n");
  }
}
void App::Stop() { m_running = false; }

App &App::GetApp() {
  assert(s_app);
  return *s_app;
}

} // namespace Aerin
