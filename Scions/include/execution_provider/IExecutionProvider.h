//
// Created by sid on 12/7/23.
//
#pragma once

#include "common/common.h"
#include "graph/CompiledGraph.h"
#include "graph/ops/Op.h"

namespace sc::ep {
class IExecutionProvider {
  public:
    virtual ~IExecutionProvider();

    // Initialize the execution provider, e.g. load backend library, create
    // contexts, etc.
    [[nodiscard]] virtual sc::Result<bool, bool> Initialize() = 0;

    // Compile nodes
    virtual sc::Result<bool, bool>
    Compile(const graph::CompiledGraph &compiledGraph) = 0;

    // Execute nodes
    [[nodiscard]] virtual sc::Result<bool, bool> Execute() = 0;
};

} // namespace sc::ep
