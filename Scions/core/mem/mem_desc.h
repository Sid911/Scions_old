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
    d_type::TYPE data_type;
};

template <size_t N> class MemDescriptor {
  public:
    u_int64_t total_bytes;
    std::array<MemObject, N> memoryObjects;

    constexpr MemDescriptor(const std::array<StaticMemObject, N> &objects): memoryObjects(buildMemObjects(objects)){
        uint64_t bytes = 0;
        for (int i = 0; i< N; i++){
            bytes += objects[i].total_size;
        }
        total_bytes = bytes;
    };

    static consteval std::array<MemObject, N> buildMemObjects(const std::array<StaticMemObject, N> & obj){
        std::array<MemObject, N> temp;
        for (int i = 0; i< N; i++){
            temp[i] = MemObject(obj[i].total_size,obj[i].name, i, obj[i].data_type);
        }
        return temp;
    }

    [[nodiscard]] constexpr MemRef getRef(size_t index) const {
        return MemRef{index, memoryObjects[index].name};
    }

    [[nodiscard]] consteval MemRef getRef(std::string_view search) const {
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
