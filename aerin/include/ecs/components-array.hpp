#pragma once

#include "entity.hpp"
#include <cstddef>
#include <print>
#include <vector>

namespace Aerin {
  class IComponentArray {
  public:
    virtual ~IComponentArray() = default;
  };

  template <typename T> class ComponentArray : public IComponentArray {
  public:
    ComponentArray(size_t maxEntities) {
      m_sparse.resize(maxEntities);
      m_dense.resize(maxEntities);
      m_components.resize(maxEntities);
    }

    void InsertComponent(EntityID id, T component) {
      size_t newId = m_size;
      m_sparse[id] = newId;
      m_dense[newId] = id;
      m_components[newId] = component;
      m_size++;

      std::println("size: {}", m_size);

      for (int i = 0; i < 10; i++) {
        std::println("sparse at {}: {}", i, m_sparse[i]);
        std::println("dense at {}: {}", i, m_dense[i]);
      }

      for (int i = 0; i < 10; i++) {
      }
    };

  private:
    std::vector<T> m_components;
    std::vector<EntityID> m_dense;
    std::vector<size_t> m_sparse;

    size_t m_size{};
  };
} // namespace Aerin
