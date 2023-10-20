//
// Created by sid on 17/10/23.
//
#pragma once

#include "common/common.h"
#include "core/mem/mem_desc.h"
namespace scions::op {
struct OpIOIndicesInfo {
    const std::array<const size_t, SC_OP_INPUT_MAX> inputs;
    const std::array<const size_t, SC_OP_OUTPUT_MAX> outputs;
};


struct OpIONameInfo {
    const std::array<const size_t, SC_OP_INPUT_MAX> inputs;
    const std::array<const size_t, SC_OP_OUTPUT_MAX> outputs;
};
} // namespace scions::op