#include "ecs/components-array.hpp"
#include "ecs/components.hpp"
#include <cassert>
#include <memory>
#include <unordered_map>

namespace Aerin {
  class ComponentManager {
  public:
    ComponentManager() = default;
    ~ComponentManager() = default;

    template <typename T> void RegisterComponent() {
      const char *typeName = typeid(T).name();
      assert(m_componentTypes.find(typeName) == m_componentTypes.end() &&
             "Registering component type more than once.");

      m_componentTypes.insert({typeName, m_nextComponentType});
      m_componentArrays.insert(
          {typeName, std::make_shared<ComponentArray<T>>(32)});

      m_nextComponentType++;
    };

    template <typename T> void AddComponent(EntityID id, T component) {
      GetComponentArray<T>()->InsertComponent(id, component);
    };

  private:
    std::unordered_map<const char *, ComponentType> m_componentTypes{};
    std::unordered_map<const char *, std::shared_ptr<IComponentArray>>
        m_componentArrays{};

    ComponentType m_nextComponentType{};

    template <typename T>
    std::shared_ptr<ComponentArray<T>> GetComponentArray() {
      const char *typeName = typeid(T).name();

      assert(m_componentTypes.find(typeName) != m_componentTypes.end() &&
             "Component not registered before use.");

      return std::static_pointer_cast<ComponentArray<T>>(
          m_componentArrays[typeName]);
    }
  };

}; // namespace Aerin
