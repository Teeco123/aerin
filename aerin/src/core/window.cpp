#include "core/window.hpp"
#include "platform/macos/window.hpp"
namespace Aerin {

std::unique_ptr<Window> Window::Create(const WindowSpecs &windowSpecs) {
#ifdef PLATFORM_WINDOWS
  static_assert(false, "Unsupported platform");
#elifdef PLATFORM_MACOS
  return std::make_unique<MacOSWindow>(windowSpecs);
#elifdef PLATFORM_LINUX
  const char *sessionType = std::getenv("XDG_SESSION_TYPE");
  if (sessionType != nullptr) {
    std::string session(sessionType);
    if (session == "wayland") {
      return std::make_unique<WaylandWindow>(windowSpecs);
    }
    if (session == "x11") {
      throw std::runtime_error("X11 is not supported");
    };
  };
  throw std::runtime_error("Unsupported or unknown linux session");
#else
  static_assert(false, "Unsupported platform");
#endif
}
Window::~Window() {}
} // namespace Aerin
