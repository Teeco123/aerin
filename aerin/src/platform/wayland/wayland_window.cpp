#include "platform/wayland/wayland_window.hpp"
#include "GLFW/glfw3.h"
#include <print>

namespace Aerin {
WaylandWindow::WaylandWindow(const WindowConfig &windowConfig) {
  Init(windowConfig);
}

WaylandWindow::~WaylandWindow() { Shutdown(); }

void WaylandWindow::Init(const WindowConfig &windowConfig) {
  m_windowConfig = windowConfig;
  std::println("Window platform: wayland");
  glfwInit();
  glfwWindowHint(GLFW_PLATFORM, GLFW_PLATFORM_WAYLAND);

  m_glfwWindow = glfwCreateWindow(windowConfig.width, windowConfig.height,
                                  windowConfig.title.c_str(), NULL, NULL);
  if (!m_glfwWindow) {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  glfwMakeContextCurrent(m_glfwWindow);
}

void WaylandWindow::Shutdown() {
  glfwDestroyWindow(m_glfwWindow);
  glfwTerminate();
}

void WaylandWindow::SwapBuffers() { glfwSwapBuffers(m_glfwWindow); }
void WaylandWindow::PollEvents() { glfwWaitEvents(); }
bool WaylandWindow::ShouldClose() {
  if (glfwWindowShouldClose(m_glfwWindow)) {
    return true;
  }
  return false;
}

unsigned int WaylandWindow::GetWidth() const { return m_windowConfig.width; }
unsigned int WaylandWindow::GetHeight() const { return m_windowConfig.height; }
std::string WaylandWindow::GetTitle() const { return m_windowConfig.title; }
}; // namespace Aerin
