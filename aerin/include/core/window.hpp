#pragma once

#include "GLFW/glfw3.h"
#include <memory>
#include <string>

struct WindowConfig {
  int width;
  int height;
  std::string title;
};

namespace Aerin {
class Window {
public:
  virtual ~Window();

  static std::unique_ptr<Window> Create(WindowConfig const &windowConfig);

  virtual void SwapBuffers() = 0;
  virtual void PollEvents() = 0;
  virtual bool ShouldClose() = 0;

  virtual unsigned int GetWidth() const = 0;
  virtual unsigned int GetHeight() const = 0;
  virtual std::string GetTitle() const = 0;

private:
  virtual void Init(const WindowConfig &windowConfig) = 0;
  virtual void Shutdown() = 0;

public:
  GLFWwindow *m_glfwWindow = nullptr;
  WindowConfig m_windowConfig;
};

} // namespace Aerin
