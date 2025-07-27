#include "core/window.h"
#include "platform/macos/macos_window.h"
#include <memory>

namespace Aerin {
std::unique_ptr<Window> Window::Create(const WindowConfig &windowConfig) {
#ifdef PLATFORM_WINDOW
  static_assert(false, "Unsupported platform");
#elifdef PLATFORM_LINUX
  static_assert(false, "Unsupported platform");
#elifdef PLATFORM_MACOS
  return std::make_unique<MacOSWindow>(windowConfig);
#else
  static_assert(false, "Unsupported platform");
#endif
}
Window::~Window() {}

} // namespace Aerin
