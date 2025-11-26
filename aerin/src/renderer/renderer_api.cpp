#include "renderer/renderer_api.h"
#include <memory>

namespace Aerin {
RendererAPI::API RendererAPI::s_rendererAPI = RendererAPI::API::NONE;

std::unique_ptr<RendererAPI> Create() {
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

RendererAPI::~RendererAPI() {};
}; // namespace Aerin
