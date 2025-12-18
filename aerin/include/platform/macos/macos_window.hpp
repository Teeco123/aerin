#pragma once
#include "core/window.hpp"

namespace Aerin {
class MacosWindow : public Window {
public:
  MacosWindow(const WindowConfig &windowConfig);
  ~MacosWindow() override;

  static std::unique_ptr<Window>
  Create(WindowConfig const &windowConfig) = delete;

  void SwapBuffers() override;
  void PollEvents() override;
  bool ShouldClose() override;

  unsigned int GetWidth() const override;
  unsigned int GetHeight() const override;
  std::string GetTitle() const override;

private:
  void Init(const WindowConfig &windowConfig) override;
  void Shutdown() override;
};
}; // namespace Aerin
