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
  void InsertComponent(EntityID id, T component) {
    size_t newId = m_size;
    m_sparse[id] = newId;
    m_dense[newId] = id;
    m_components[newId] = component;
    m_size++;

    std::println("{} {} {} {}", m_components, m_dense, m_sparse, m_size);
  };

private:
  std::vector<T> m_components;
  std::vector<T> m_dense;
  std::vector<size_t> m_sparse;

  size_t m_size{};
};
} // namespace Aerin
