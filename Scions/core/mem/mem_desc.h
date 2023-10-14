//
// Created by sid on 13/10/23.
//

#pragma once
#include "common/common.h"
#include "mem_object.h"

namespace scions::mem {

    class MemDescriptor{
        u_int64_t total_bytes;
        std::vector<MemObject> memoryObjects;

        constexpr MemDescriptor(const std::initializer_list<MemObject> &objects);
    };

} // scions
// mem
