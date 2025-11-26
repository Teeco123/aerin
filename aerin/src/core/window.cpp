#include "core/window.h"
#include <memory>

namespace Aerin {
std::unique_ptr<Window> Window::Create(const WindowConfig &windowConfig) {
#ifdef PLATFORM_WINDOWS
  static_assert(false, "Unsupported platform");
#elifdef PLATFORM_LINUX
  return true;
#elifdef PLATFORM_MACOS
  static_assert(false, "Unsupported platform");
#else
  static_assert(false, "Unsupported platform");
#endif
}
Window::~Window() {}

} // namespace Aerin
