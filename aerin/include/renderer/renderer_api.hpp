#pragma once

#include <memory>

namespace Aerin {
class RendererAPI {
public:
  enum class API : uint8_t {
    NONE = 0,
    OPENGL = 1,
    METAL = 2,
    DIRECTX = 3,
    VULKAN = 4
  };

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
