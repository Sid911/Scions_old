//
// Created by sid on 13/10/23.
//

#pragma once
#include "common/common.h"
#include "mem_object.h"

namespace scions::mem {
struct MemRef {
    size_t index;
    std::string_view name;
};

template <size_t N> class MemDescriptor {
  public:
    u_int64_t total_bytes;
    std::array<StaticMemObject, N> memoryObjects;

    constexpr MemDescriptor(const std::array<StaticMemObject, N> &objects)
        : memoryObjects(objects) {
        uint64_t bytes = 0;
        for (auto a : memoryObjects)
            bytes += a.total_size;
        total_bytes = bytes;
    };

    constexpr auto getRef(size_t index) -> MemRef {
        return MemRef{index, memoryObjects[index].name};
    }

    consteval MemRef getRef(std::string_view search) {
        auto index = -1;
        for (int i = 0; i < N; ++i) {
            if (memoryObjects[i].name == search) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            throw std::runtime_error(std::string(
                "memory object named " + std::string(search) + "not found"));
        }

        return MemRef{index, memoryObjects[index].name};
    }
};

} // namespace scions::mem
// mem
