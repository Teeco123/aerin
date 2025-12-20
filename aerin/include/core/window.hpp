#pragma once

#include <GLFW/glfw3.h>
#include <memory>
#include <string>

namespace Aerin {

struct WindowSpecs {
  std::string title;
  uint32_t width;
  uint32_t height;
};

class Window {
public:
  virtual ~Window();

  static std::unique_ptr<Window> Create(const WindowSpecs &windowSpecs);

  bool ShouldClose() const;
  void SwapBuffers();
  void PoolEvents();

private:
  virtual void Shutdown() = 0;

public:
  WindowSpecs m_windowSpecs;
  GLFWwindow *m_windowHandle = nullptr;
};
} // namespace Aerin
