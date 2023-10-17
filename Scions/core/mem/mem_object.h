//
// Created by sid on 13/10/23.
//

#pragma once
#include "common/common.h"

namespace scions::mem {

class StaticMemObject {
  public:
    uint64_t total_size;
    const std::string_view name;

    constexpr explicit StaticMemObject(uint64_t size, std::string_view name): total_size(size), name(name) {}
    constexpr StaticMemObject(uint32_t x, uint_fast32_t y, std::string_view name)
        : total_size(x * y * sizeof(uint64_t)), name(name) {}

    constexpr StaticMemObject(uint_fast32_t x, uint_fast32_t y, uint_fast32_t z, std::string_view name)
        : total_size(x * y * z * sizeof(uint64_t)),name(name) {}

    consteval StaticMemObject(std::initializer_list<uint_fast32_t> list, std::string_view name) :
    name(name)
    {
        total_size = 1;
        for (uint_fast32_t val : list) {
            total_size *= val;
        }
        total_size *= sizeof(uint_fast32_t);
    }
};
} // namespace scions::mem