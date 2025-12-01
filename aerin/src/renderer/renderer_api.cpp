#include "renderer/renderer_api.hpp"
#include "platform/opengl/opengl_renderer_api.hpp"

namespace Aerin {
RendererAPI::API RendererAPI::s_rendererAPI = RendererAPI::API::NONE;

std::unique_ptr<RendererAPI> Create() {
#ifdef PLATFORM_WINDOWS
  static_assert(false, "Unsupported platform");
#elifdef PLATFORM_LINUX
  RendererAPI::s_rendererAPI = RendererAPI::API::OPENGL;
  return std::make_unique<OpenGLRendererAPI>();
#elifdef PLATFORM_MACOS
  static_assert(false, "Unsupported platform");
#else
  static_assert(false, "Unsupported platform");
#endif
}

RendererAPI::~RendererAPI() {};
}; // namespace Aerin
