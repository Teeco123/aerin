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

  virtual unsigned int GetWidth() const = 0;
  virtual unsigned int GetHeight() const = 0;
  virtual std::string GetTitle() const = 0;

  GLFWwindow *m_glfwWindow = nullptr;
  WindowConfig m_windowConfig;
};

class MacOSWindow : public Window {
public:
  MacOSWindow(const WindowConfig &windowConfig);
  ~MacOSWindow() override;

  static std::unique_ptr<Window>
  Create(WindowConfig const &windowConfig) = delete;

  unsigned int GetWidth() const override;
  unsigned int GetHeight() const override;
  std::string GetTitle() const override;
};

} // namespace Aerin
