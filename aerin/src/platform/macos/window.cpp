#include "platform/macos/window.hpp"
#include "GLFW/glfw3.h"
#include <print>

namespace Aerin {
MacOSWindow::MacOSWindow(const WindowSpecs &windowSpecs) {
  m_windowSpecs = windowSpecs;
  std::println("Window platform: MacOS");
  glfwInit();
  glfwWindowHint(GLFW_PLATFORM, GLFW_PLATFORM_COCOA);

  m_windowHandle = glfwCreateWindow(windowSpecs.width, windowSpecs.height,
                                    windowSpecs.title.c_str(), NULL, NULL);
  if (!m_windowHandle) {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  glfwMakeContextCurrent(m_windowHandle);
}

MacOSWindow::~MacOSWindow() { Shutdown(); }

void MacOSWindow::Shutdown() {
  glfwDestroyWindow(m_windowHandle);
  glfwTerminate();
}

bool MacOSWindow::ShouldClose() const {
  if (glfwWindowShouldClose(m_windowHandle)) {
    return true;
  }
  return false;
}

}; // namespace Aerin
