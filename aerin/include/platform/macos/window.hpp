#pragma once
#include "core/window.hpp"

namespace Aerin {
class MacOSWindow : public Window {
public:
  MacOSWindow(const WindowSpecs &windowSpecs);
  ~MacOSWindow() override;

  static std::unique_ptr<Window>
  Create(WindowSpecs const &windowSpecs) = delete;

private:
  void Shutdown() override;
};
}; // namespace Aerin
