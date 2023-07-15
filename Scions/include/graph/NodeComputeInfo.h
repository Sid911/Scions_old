//
// Created by sid on 15/7/23.
//

#pragma once

#include "common/common.h"
#include "tensor/TensorShape.h"

namespace sc::graph::node {
struct NodeComputeInfo {
    std::vector<sc::tensor::TensorShape> inputShapes;
    std::vector<sc::tensor::TensorShape> outputShapes;
};
} // namespace sc::graph