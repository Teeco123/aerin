#pragma once
#include "core/window.hpp"

namespace Aerin {
class WaylandWindow : public Window {
public:
  WaylandWindow(const WindowSpecs &windowSpecs);
  ~WaylandWindow() override;

  static std::unique_ptr<Window>
  Create(WindowSpecs const &windowSpecs) = delete;

  bool ShouldClose() const override;

private:
  void Shutdown() override;
};
}; // namespace Aerin
