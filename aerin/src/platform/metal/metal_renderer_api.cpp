#include "platform/metal/metal_renderer_api.h"

#define NS_PRIVATE_IMPLEMENTATION
#define CA_PRIVATE_IMPLEMENTATION
#define MTL_PRIVATE_IMPLEMENTATION

#include <Metal/metal.hpp>

namespace Aerin {

MetalRendererAPI::MetalRendererAPI() { Init(); }

MetalRendererAPI::~MetalRendererAPI() { Shutdown(); }

void MetalRendererAPI::Init() {
  MTL::Device *device = MTL::CreateSystemDefaultDevice();
}

void MetalRendererAPI::Shutdown() {}

} // namespace Aerin
