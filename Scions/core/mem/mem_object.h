//
// Created by sid on 13/10/23.
//

#pragma once
#include "common/common.h"
#include "common/d_type.h"

namespace scions::mem {

class StaticMemObject {
  public:
    uint64_t total_size;
    const std::string_view name;
    const uint32_t dimension;
    const d_type::TYPE data_type;
    std::array<uint32_t, SC_MAX_DIMS> shape;

    constexpr StaticMemObject(uint32_t size, std::string_view name,
                              d_type::TYPE type = d_type::F16)
        : total_size(size), name(name), dimension(1), data_type(type),
          shape({size, 0, 0, 0, 0}) {}

    constexpr StaticMemObject(uint32_t x, uint32_t y, std::string_view name,
                              d_type::TYPE type = d_type::F16)
        : total_size(x * y * sizeof(uint64_t)), name(name), dimension(2),
          data_type(type), shape({x, y}) {}

    constexpr StaticMemObject(uint32_t x, uint32_t y, uint32_t z,
                              std::string_view name,
                              d_type::TYPE type = d_type::F16)
        : total_size(x * y * z * sizeof(uint64_t)), name(name), dimension(3),
          data_type(type), shape({x, y, z}) {}

    consteval StaticMemObject(std::initializer_list<uint32_t> list,
                              std::string_view name,
                              d_type::TYPE type = d_type::F16)
        : name(name),
          dimension(SC_MAX_DIMS > list.size() ? list.size() : SC_MAX_DIMS),
          data_type(type),shape() {

        total_size = 1;
        uint16_t i = 0;
        for (uint32_t val : list) {
            if (i>=dimension)
                break;
            total_size *= val;
            shape[i] = val;
            i++;
        }
        total_size *= sizeof(uint64_t);
    }
};

class MemObject {
  public:
    uint64_t total_size;
    uint64_t id;
    std::string_view name;
    d_type::TYPE type;

    constexpr MemObject()
        : total_size(0), id(-1), name("bruh"), type(d_type::TYPE::F16){};

    constexpr MemObject(uint64_t size, std::string_view name, uint64_t id,
                        d_type::TYPE type = d_type::F16)
        : name(name), total_size(size), id(id), type(type) {}

    constexpr MemObject(StaticMemObject object, uint64_t id)
        : name(object.name), total_size(object.total_size), id(id),
          type(object.data_type) {}
};
} // namespace scions::mem