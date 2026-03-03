#include "ecs/components-array.hpp"
#include <memory>

namespace Aerin {
  class ComponentManager {
  public:
    template <typename T> void RegisterComponent() {};

  private:
    template <typename T>
    std::shared_ptr<ComponentArray<T>> GetComponentArray() {
    }
  };

}; // namespace Aerin
