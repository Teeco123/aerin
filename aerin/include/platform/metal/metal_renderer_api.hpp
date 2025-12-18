#pragma once

#include "renderer/renderer_api.hpp"
#include <memory>

namespace Aerin {
class MetalRendererAPI : public RendererAPI {
public:
  MetalRendererAPI();
  ~MetalRendererAPI() override;

  static std::unique_ptr<RendererAPI> Create() = delete;
  static RendererAPI::API GetAPI() = delete;

private:
  void Init() override;
  void Shutdown() override;
};
}; // namespace Aerin
