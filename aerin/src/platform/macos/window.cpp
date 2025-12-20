#include "platform/macos/window.hpp"
#include "GLFW/glfw3.h"

#include <cassert>
#include <iostream>
#include <print>

namespace Aerin {
MacOSWindow::MacOSWindow(const WindowSpecs &windowSpecs) {
  m_windowSpecs = windowSpecs;
  std::println("Window platform: MacOS");

  glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_COCOA);

  if (!glfwInit()) {
    std::cerr << "Failed to init GLFW!\n";
    assert(false);
  };

  m_windowHandle = glfwCreateWindow(windowSpecs.width, windowSpecs.height,
                                    windowSpecs.title.c_str(), NULL, NULL);
  if (!m_windowHandle) {
    glfwTerminate();
    std::cerr << "Failed to create GLFW window!\n";
    assert(false);
  }

  glfwMakeContextCurrent(m_windowHandle);
  glfwSwapInterval(windowSpecs.vsync ? 1 : 0);
}

MacOSWindow::~MacOSWindow() { Shutdown(); }

void MacOSWindow::Shutdown() {
  glfwDestroyWindow(m_windowHandle);
  glfwTerminate();
}

}; // namespace Aerin
