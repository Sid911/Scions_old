//
// Created by sid on 15/7/23.
//

#pragma once

#include <utility>

#include "../../common/common.h"
#include "core/graph/memory/MemoryRef.h"
#include "core/tensor/TensorShape.h"

namespace sc::graph::op {
struct OpComputeInfo {
    std::vector<sc::memory::MemoryRef> inputRefs;
    std::vector<sc::memory::MemoryRef> outputRefs;

    constexpr OpComputeInfo(std::vector<memory::MemoryRef> inp,
                            std::vector<memory::MemoryRef> out)
        : inputRefs(std::move(inp)), outputRefs(std::move(out)) {}
};
} // namespace sc::graph::op