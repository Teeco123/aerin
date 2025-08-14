#include "renderer/renderer_api.h"
#include "platform/metal/metal_renderer_api.h"
#include <memory>

namespace Aerin {
RendererAPI::API RendererAPI::s_rendererAPI = RendererAPI::API::NONE;

std::unique_ptr<RendererAPI> Create() {
#ifdef PLATFORM_WINDOWS
  static_assert(false, "Unsupported platform");
#elifdef PLATFORM_LINUX
  static_assert(false, "Unsupported platform");
#elifdef PLATFORM_MACOS
  RendererAPI::s_rendererAPI = RendererAPI::API::METAL;
  return std::make_unique<MetalRendererAPI>();
#else
  static_assert(false, "Unsupported platform");
#endif
}

RendererAPI::~RendererAPI() {};
}; // namespace Aerin
