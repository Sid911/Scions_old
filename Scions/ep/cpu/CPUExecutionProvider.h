//
// Created by sid on 23/10/23.
//

#pragma once
#include "ep/common/common.h"
#include "ep/common/runtime_sequential_graph.h"
namespace scions::ep::cpu {
struct CPUOptions{
    bool is_debug;
};

class CPUExecutionProvider {
  public:
    [[nodiscard("Message: Returning object of CPUExecutionProvider.")]]
    CPUExecutionProvider(graph::RuntimeSequentialGraph& graph, CPUOptions& options);
    CPUExecutionProvider(const graph::RuntimeSequentialGraph& graph, const CPUOptions& options);
  private:
    graph::RuntimeSequentialGraph graph;
    const CPUOptions options;
};
}