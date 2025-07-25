#include "core/window.h"
#include <memory>
#include <print>
#include <string>

namespace Aerin {
std::unique_ptr<Window> Window::Create(const WindowConfig &windowConfig) {
#ifdef PLATFORM_WINDOW
#elifdef PLATFORM_LINUX
#elifdef PLATFORM_MACOS
  return std::make_unique<MacOSWindow>(windowConfig);
#else
  static_assert(false, "Unsupported platform");
#endif
}
Window::~Window() {}

MacOSWindow::MacOSWindow(const WindowConfig &windowConfig) {
  m_windowConfig = windowConfig;
  std::println("MacOS window config: height - {}, width - {}, title - {}",
               windowConfig.height, windowConfig.width, windowConfig.title);
}
MacOSWindow::~MacOSWindow() {}

unsigned int MacOSWindow::GetWidth() const { return m_windowConfig.width; }
unsigned int MacOSWindow::GetHeight() const { return m_windowConfig.height; }
std::string MacOSWindow::GetTitle() const { return m_windowConfig.title; }

} // namespace Aerin
