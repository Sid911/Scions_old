//
// Created by sid on 13/7/23.
//

#include "SequentialModel.h"
namespace sc::graph {
SequentialModel::SequentialModel(
    vector<variant<node::Node, Op>> nodes,
    vector<shared_ptr<memory::MemoryObject>> memoryGraph, std::string name)
    : nodes(std::move(nodes)), name(std::move(name)),
      memoryGraph(std::move(memoryGraph)) {}

[[maybe_unused]] SequentialModel::SequentialModel(
    std::vector<std::variant<node::Node, Op>> nodes)
    : nodes(std::move(nodes)), name("Sequential Model") {}

Result<bool, std::string>
SequentialModel::Add(std::variant<node::Node, Op> &node) {
    nodes.push_back(node);
}

CompiledGraph SequentialModel::compileGraph() {

    std::shared_ptr<std::vector<Op>> graph;
    for (auto &&node : nodes) {
        if (std::holds_alternative<Op>(node)) [[likely]] {
            graph->push_back(std::get<Op>(node));
        }
        // Todo: This test compilation does absolutely nothing
    }

    return CompiledGraph{memoryGraph, graph};
}

} // namespace sc::graph