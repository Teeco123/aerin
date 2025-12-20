#include "platform/wayland/window.hpp"
#include "GLFW/glfw3.h"
#include <print>

namespace Aerin {
WaylandWindow::WaylandWindow(const WindowSpecs &windowSpecs) {
  m_windowSpecs = windowSpecs;
  std::println("Window platform: Wayland");
  glfwInit();
  glfwWindowHint(GLFW_PLATFORM, GLFW_PLATFORM_WAYLAND);

  m_windowHandle = glfwCreateWindow(windowSpecs.width, windowSpecs.height,
                                    windowSpecs.title.c_str(), NULL, NULL);
  if (!m_windowHandle) {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  glfwMakeContextCurrent(m_windowHandle);
}

WaylandWindow::~WaylandWindow() { Shutdown(); }

void WaylandWindow::Shutdown() {
  glfwDestroyWindow(m_windowHandle);
  glfwTerminate();
}

bool WaylandWindow::ShouldClose() const {
  if (glfwWindowShouldClose(m_windowHandle)) {
    return true;
  }
  return false;
}

}; // namespace Aerin
