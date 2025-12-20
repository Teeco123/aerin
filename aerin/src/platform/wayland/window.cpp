#include "platform/wayland/window.hpp"
#include "GLFW/glfw3.h"

#include <cassert>
#include <iostream>
#include <print>

namespace Aerin {
WaylandWindow::WaylandWindow(const WindowSpecs &windowSpecs) {
  m_windowSpecs = windowSpecs;
  std::println("Window platform: Wayland");

  if (!glfwInit()) {
    std::cerr << "Failed to init GLFW!\n";
    assert(false);
  };

  glfwWindowHint(GLFW_PLATFORM, GLFW_PLATFORM_WAYLAND);

  m_windowHandle = glfwCreateWindow(windowSpecs.width, windowSpecs.height,
                                    windowSpecs.title.c_str(), NULL, NULL);
  if (!m_windowHandle) {
    glfwTerminate();
    std::cerr << "Failed to create GLFW window!\n";
    assert(false);
  }

  glfwMakeContextCurrent(m_windowHandle);
}

WaylandWindow::~WaylandWindow() { Shutdown(); }

void WaylandWindow::Shutdown() {
  glfwDestroyWindow(m_windowHandle);
  glfwTerminate();
}

}; // namespace Aerin
