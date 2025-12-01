#pragma once

#include "core/window.hpp"

namespace Aerin {
class App {
public:
  App();
  virtual ~App();
  void Run();

private:
  std::unique_ptr<Window> m_window;
  bool m_running = true;
  float m_deltaTime = 0.0f;
  float m_fixedDeltaTime = 0.0f;
};
} // namespace Aerin
