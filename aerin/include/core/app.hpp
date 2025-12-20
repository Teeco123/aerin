#pragma once

#include "core/window.hpp"
#include <memory>
#include <string>

namespace Aerin {

struct AppSpecs {
  std::string name = "Aerin app";
  double fixedUpdateSeconds = 0.0166;
  WindowSpecs windowSpecs;
};

class App {
public:
  App(const AppSpecs &specs = AppSpecs());
  ~App();

  void Start(const AppSpecs &specs = AppSpecs());
  void Stop();

public:
  static App &GetApp();
  static double GetTime();
  double GetDeltaTime();
  double GetFixedDeltaTime();

private:
  AppSpecs m_specs;
  bool m_running = false;
  double m_deltaTime = 0.0f;
  double m_fixedDeltaTime = 0.0f;
  std::unique_ptr<Window> m_window;
};
} // namespace Aerin
