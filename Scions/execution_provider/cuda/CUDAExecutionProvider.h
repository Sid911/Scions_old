//
// Created by sid on 24/7/23.
//

#pragma once

#include "../../common/common.h"
#include "../../include/graph/CompiledGraph.h"
#include "../IExecutionProvider.h"

namespace sc::ep::cuda {

class CUDAExecutionProvider : IExecutionProvider {
    ~CUDAExecutionProvider() override;
    Result<bool, bool> Initialize() override;
    Result<bool, bool>
    Compile(const graph::CompiledGraph &compiledGraph) override;
    Result<bool, bool> Execute() override;
};
} // namespace sc::ep::cuda
