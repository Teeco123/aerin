#pragma once

#include "core/window.hpp"
#include <memory>
#include <string>

namespace Aerin {

struct AppSpecs {
  std::string name = "Aerin app";
  WindowSpecs windowSpecs;
};

class App {
public:
  App(const AppSpecs &specs = AppSpecs());
  ~App();

  void Start();
  void Stop();

public:
  static App &GetApp();

private:
  AppSpecs m_specs;
  bool m_running = false;
  std::unique_ptr<Window> m_window;
};
} // namespace Aerin
