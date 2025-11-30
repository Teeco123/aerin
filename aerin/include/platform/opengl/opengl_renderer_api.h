#pragma once

#include "renderer/renderer_api.h"
#include <memory>

namespace Aerin {
class OpenGLRendererAPI : public RendererAPI {
public:
  OpenGLRendererAPI();
  ~OpenGLRendererAPI() override;

  static std::unique_ptr<RendererAPI> Create() = delete;
  static RendererAPI::API GetAPI() = delete;

private:
  void Init() override;
  void Shutdown() override;
};
}; // namespace Aerin
