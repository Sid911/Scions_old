//
// Created by sid on 17/10/23.
//
#pragma once

#include "common/common.h"

namespace scions::op{
struct OpIOInfo{
    std::span<const uint32_t> inputs;
    std::span<const uint32_t> outputs;
};
}