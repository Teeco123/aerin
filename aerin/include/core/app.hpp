#pragma once

#include "core/window.hpp"
#include <memory>
#include <string>

namespace Aerin {

struct AppSpecs {
  std::string name = "Aerin app";
};

class App {
public:
  App(const AppSpecs &specs);
  virtual ~App();
  void Run();

private:
  std::unique_ptr<Window> m_window;
  bool m_running = true;
  float m_deltaTime = 0.0f;
  float m_fixedDeltaTime = 0.0f;
};
} // namespace Aerin
