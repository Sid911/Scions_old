//
// Created by sid on 13/10/23.
//

#pragma once
#include "common/common.h"
namespace scions::mem {
    class MemObject {
    public:
        uint64_t size;
        constexpr MemObject(uint64_t size);
    };
}