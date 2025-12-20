#pragma once

#include <string>

int main();

namespace Aerin {

struct AppSpecs {
  std::string name = "Aerin app";
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
};
} // namespace Aerin
