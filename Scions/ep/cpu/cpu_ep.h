//
// Created by sid on 23/10/23.
//

#pragma once
#include "cpu_execution_stats.h"
#include "ep/common/common.h"
#include "ep/common/runtime_sequential_graph.h"
namespace scions::ep::cpu {
struct CPUOptions {
    bool is_debug;
};

class CPUExecutionProvider {
  public:
    [[nodiscard("Message: Returning object of CPUExecutionProvider.")]]
    CPUExecutionProvider(graph::RuntimeSequentialGraph &graph_,
                         CPUOptions &options_);
    [[nodiscard("Message: Returning object of CPUExecutionProvider.")]]
    CPUExecutionProvider(const graph::RuntimeSequentialGraph &graph_,
                         const CPUOptions &options_);

    std::expected<bool, std::string> allocateAll();

    std::expected<bool, std::string>
    allocateAll(std::unordered_map<size_t, uint8_t *> &&memory_map);

    std::expected<bool, std::string>
    allocateAll(std::unordered_map<std::string_view, uint8_t *> &&memory_map);

  private:
    graph::RuntimeSequentialGraph graph;
    const CPUOptions options;

    std::vector<std::unique_ptr<uint8_t[]>> static_memory;
};
} // namespace scions::ep::cpu