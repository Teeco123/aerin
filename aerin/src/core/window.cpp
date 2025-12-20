#include "core/window.hpp"
#include "platform/macos/window.hpp"
#include "platform/wayland/window.hpp"
#include <iostream>

namespace Aerin {

static void GLFWErrorCallback(int error, const char *description) {
  std::cerr << "[GLFW Error]: " << description << std::endl;
}

std::unique_ptr<Window> Window::Create(const WindowSpecs &windowSpecs) {
  glfwSetErrorCallback(GLFWErrorCallback);

#ifdef PLATFORM_WINDOWS
  static_assert(false, "Unsupported platform");
#elifdef PLATFORM_MACOS
  return std::make_unique<MacOSWindow>(windowSpecs);
#elifdef PLATFORM_LINUX
  const char *sessionType = std::getenv("XDG_SESSION_TYPE");
  if (sessionType != nullptr) {
    std::string session(sessionType);
    if (session == "wayland") {
      return std::make_unique<WaylandWindow>(windowSpecs);
    }
    if (session == "x11") {
      throw std::runtime_error("X11 is not supported");
    };
  };
  throw std::runtime_error("Unsupported or unknown linux session");
#else
  static_assert(false, "Unsupported platform");
#endif
}

Window::~Window() {}

bool Window::ShouldClose() const {
  if (glfwWindowShouldClose(m_windowHandle)) {
    return true;
  }
  return false;
}
void Window::SwapBuffers() { glfwSwapBuffers(m_windowHandle); };
void Window::PoolEvents() { glfwWaitEvents(); };

} // namespace Aerin
