#include "core/app.hpp"
#include <cassert>
#include <memory>
#include <print>

namespace Aerin {

static App *s_app = nullptr;

App::App(const AppSpecs &specs) : m_specs(specs) {
  std::println("App name: {}", specs.name);
  std::println("Fixed time step in seconds: {}", specs.fixedUpdateSeconds);
  std::println("Window width: {}", specs.windowSpecs.width);
  std::println("Window height: {}", specs.windowSpecs.height);
  std::println("Window title: {}", specs.windowSpecs.title);
  std::println("Vsync on: {}", specs.windowSpecs.vsync);

  s_app = this;
  m_window = Window::Create(specs.windowSpecs);
}
App::~App() { s_app = nullptr; }

void App::Start(const AppSpecs &specs) {
  m_running = true;
  double lastUpdate = GetTime();
  double lastFixedUpdate = GetTime();
  double accumulator = 0.0f;

  while (m_running) {
    if (m_window->ShouldClose()) {
      m_running = false;
    }

    double now = GetTime();
    m_deltaTime = now - lastUpdate;
    lastUpdate += m_deltaTime;
    accumulator += m_deltaTime;

    while (accumulator >= specs.fixedUpdateSeconds) {
      double now = GetTime();
      m_fixedDeltaTime = now - lastFixedUpdate;
      lastFixedUpdate += m_fixedDeltaTime;
      accumulator -= specs.fixedUpdateSeconds;
    };

    m_window->PollEvents();
    m_window->SwapBuffers();
  }
}
void App::Stop() { m_running = false; }

App &App::GetApp() {
  assert(s_app);
  return *s_app;
}

double App::GetTime() { return glfwGetTime(); };
double App::GetDeltaTime() { return m_deltaTime; };
double App::GetFixedDeltaTime() { return m_fixedDeltaTime; };

} // namespace Aerin
