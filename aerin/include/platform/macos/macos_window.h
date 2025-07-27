#pragma once
#include "core/window.h"

namespace Aerin {
class MacOSWindow : public Window {
public:
  MacOSWindow(const WindowConfig &windowConfig);
  ~MacOSWindow() override;

  static std::unique_ptr<Window>
  Create(WindowConfig const &windowConfig) = delete;

  unsigned int GetWidth() const override;
  unsigned int GetHeight() const override;
  std::string GetTitle() const override;
};
}; // namespace Aerin
