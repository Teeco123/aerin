#define GLFW_INCLUDE_NONE
#define GLFW_EXPOSE_NATIVE_COCOA
#include "platform/macos/macos_window.h"
#include "GLFW/glfw3.h"
#include <print>

namespace Aerin {
MacOSWindow::MacOSWindow(const WindowConfig &windowConfig) {
  Init(windowConfig);
}

MacOSWindow::~MacOSWindow() { Shutdown(); }

void MacOSWindow::Init(const WindowConfig &windowConfig) {
  m_windowConfig = windowConfig;
  std::println("Window config: height - {}, width - {}, title - {}",
               windowConfig.height, windowConfig.width, windowConfig.title);
  glfwInit();
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

  m_glfwWindow = glfwCreateWindow(windowConfig.width, windowConfig.height,
                                  windowConfig.title.c_str(), NULL, NULL);
  if (!m_glfwWindow) {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }
}

void MacOSWindow::Shutdown() {
  glfwDestroyWindow(m_glfwWindow);
  glfwTerminate();
}

void MacOSWindow::SwapBuffers() { glfwSwapBuffers(m_glfwWindow); }
void MacOSWindow::PollEvents() { glfwWaitEvents(); }
bool MacOSWindow::ShouldClose() {
  if (glfwWindowShouldClose(m_glfwWindow)) {
    return true;
  }
  return false;
}

unsigned int MacOSWindow::GetWidth() const { return m_windowConfig.width; }
unsigned int MacOSWindow::GetHeight() const { return m_windowConfig.height; }
std::string MacOSWindow::GetTitle() const { return m_windowConfig.title; }
}; // namespace Aerin
