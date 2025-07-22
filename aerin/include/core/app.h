#pragma once

namespace Aerin {
class App {
public:
  App();
  virtual ~App();

  void Run();

private:
  bool m_running = false;
  float m_deltaTime;
};
} // namespace Aerin
