#include "platform/macos/macos_window.hpp"
#include "GLFW/glfw3.h"
#include <print>

namespace Aerin {
MacosWindow::MacosWindow(const WindowConfig &windowConfig) {
  Init(windowConfig);
}

MacosWindow::~MacosWindow() { Shutdown(); }

void MacosWindow::Init(const WindowConfig &windowConfig) {
  m_windowConfig = windowConfig;
  std::println("Window platform: macos");
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

void MacosWindow::Shutdown() {
  glfwDestroyWindow(m_glfwWindow);
  glfwTerminate();
}

void MacosWindow::SwapBuffers() { glfwSwapBuffers(m_glfwWindow); }
void MacosWindow::PollEvents() { glfwWaitEvents(); }
bool MacosWindow::ShouldClose() {
  if (glfwWindowShouldClose(m_glfwWindow)) {
    return true;
  }
  return false;
}

unsigned int MacosWindow::GetWidth() const { return m_windowConfig.width; }
unsigned int MacosWindow::GetHeight() const { return m_windowConfig.height; }
std::string MacosWindow::GetTitle() const { return m_windowConfig.title; }
}; // namespace Aerin
