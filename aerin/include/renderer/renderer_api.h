#pragma once

#include <memory>

namespace Aerin {
class RendererAPI {
public:
  enum class API : uint8_t { NONE = 0, METAL = 1, DIRECTX = 2, VULKAN = 3 };

public:
  virtual ~RendererAPI();

  static std::unique_ptr<RendererAPI> Create();
  static API GetAPI();

private:
  virtual void Init() = 0;
  virtual void Shutdown() = 0;

public:
  static API s_rendererAPI;
};

} // namespace Aerin
