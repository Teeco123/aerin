#pragma once

#include "entity-manager.hpp"

#include <cstddef>
#include <vector>

namespace Aerin {
  class IComponentArray {};

  template <typename T> class ComponentArray : public IComponentArray {
  public:
    ComponentArray(size_t maxEntities) {
      m_sparse.resize(maxEntities);
      m_dense.resize(maxEntities);
      m_components.resize(maxEntities);
    }

    void InsertComponent(Entity id, T component) {
      size_t newId = m_size;
      m_sparse[id] = newId;
      m_dense[newId] = id;
      m_components[newId] = component;
      m_size++;
    };

    void InsertComponent(Entity id) {
      InsertComponent(id, T{});
    };

    bool HasComponent(Entity id) {
      size_t sparse = m_sparse[id];
      if (m_dense[sparse] == id) {
        return true;
      };
      return false;
    };

  private:
    std::vector<T> m_components;
    std::vector<Entity> m_dense;
    std::vector<size_t> m_sparse;

    size_t m_size{};
  };
} // namespace Aerin
