#include "core/app.hpp"
#include <cassert>
#include <memory>

namespace Aerin {

static App *s_app = nullptr;

App::App(const AppSpecs &specs) : m_specs(specs) {
  s_app = this;
  m_window = Window::Create(specs.windowSpecs);
}
App::~App() { s_app = nullptr; }

void App::Start() {
  m_running = true;
  while (m_running) {
    if (m_window->ShouldClose()) {
      m_running = false;
    }

    m_window->PollEvents();
    m_window->SwapBuffers();
  }
}
void App::Stop() { m_running = false; }

App &App::GetApp() {
  assert(s_app);
  return *s_app;
}

} // namespace Aerin
