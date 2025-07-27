#include "platform/macos/macos_window.h"
#include <print>

namespace Aerin {
MacOSWindow::MacOSWindow(const WindowConfig &windowConfig) {
  m_windowConfig = windowConfig;
  std::println("MacOS window config: height - {}, width - {}, title - {}",
               windowConfig.height, windowConfig.width, windowConfig.title);
}
MacOSWindow::~MacOSWindow() {}

unsigned int MacOSWindow::GetWidth() const { return m_windowConfig.width; }
unsigned int MacOSWindow::GetHeight() const { return m_windowConfig.height; }
std::string MacOSWindow::GetTitle() const { return m_windowConfig.title; }
}; // namespace Aerin
