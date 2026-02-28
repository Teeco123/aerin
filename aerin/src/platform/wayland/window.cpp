#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "platform/wayland/window.hpp"

#include <cassert>
#include <iostream>
#include <print>

namespace Aerin {
  WaylandWindow::WaylandWindow(const WindowSpecs &windowSpecs) {
    m_windowSpecs = windowSpecs;
    std::println("Window platform: Wayland");

    glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_WAYLAND);

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

    GLenum err = glewInit();

    if (GLEW_OK != err) {
      std::cerr << "Failed to init GLEW!\n";
      fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
    };
  }

  WaylandWindow::~WaylandWindow() {
    Shutdown();
  }

  void WaylandWindow::Shutdown() {
    glfwDestroyWindow(m_windowHandle);
    glfwTerminate();
  }

}; // namespace Aerin
