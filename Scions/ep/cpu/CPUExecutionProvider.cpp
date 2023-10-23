//
// Created by sid on 23/10/23.
//

#include "CPUExecutionProvider.h"

namespace scions::ep::cpu {
CPUExecutionProvider::CPUExecutionProvider(graph::RuntimeSequentialGraph &graph,
                                           CPUOptions &options)
    : graph(graph), options(options) {}

CPUExecutionProvider::CPUExecutionProvider(
    const graph::RuntimeSequentialGraph &graph, const CPUOptions &options)
    : graph(graph), options(options) {}
} // namespace scions::ep::cpu
