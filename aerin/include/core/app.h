#pragma once

namespace Aerin {
class App {
public:
  App();
  virtual ~App();

  void Run();

private:
  bool m_running = true;
  float m_deltaTime = 0.0f;
  float m_fixedDeltaTime = 0.0f;
};
} // namespace Aerin
