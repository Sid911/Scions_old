//
// Created by sid on 13/10/23.
//

#include "mem_desc.h"


namespace scions::mem {
    constexpr MemDescriptor::MemDescriptor(const std::initializer_list<MemObject> &objects) : memoryObjects(objects) {
        uint64_t bytes = 0;
        for (auto a: objects) bytes += a.size;
        total_bytes = bytes;
    }
} // scions
// mem