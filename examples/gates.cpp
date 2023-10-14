#include "vector"
#include "core/mem/mem_desc.h"
using namespace std;

std::expected<int, std::string> getInt(std::string arg) {
    try {
        return std::stoi(arg);
    }
    catch (...) {
        return std::unexpected{std::string(arg + ": Error")};
    }
}

int main() {
    using namespace sc::graph;
    using namespace sc::memory;
    using namespace sc::graph::op;
    using namespace sc::ep;


    // device mem
    const vector<MemoryObjectPtr> mem = {
        CreateMemoryObjectPtr({1}, "input_layer"),   // 0
        CreateMemoryObjectPtr({1}, "input_reshape"), // 1
        CreateMemoryObjectPtr({1}, "weight_l1"),     // 2
        CreateMemoryObjectPtr({1}, "bias_l1"),       // 3
        CreateMemoryObjectPtr({1}, "activation_l1"), // 4
        CreateMemoryObjectPtr({1}, "weight_l2"),     // 5
        CreateMemoryObjectPtr({1}, "bias_l2"),       // 6
        CreateMemoryObjectPtr({1}, "activation_l2"), // 7
    };

    const vector<variant<node::Node, Op>> nodes = {
        // Reshape
        MatReshape(0, 1),

        // Dense Layer 1
        MatMul(1, 2, 4),
        MatAdd(4, 3, 4),
        Relu(4, 4),

        // Dense Layer 2
        MatMul(4, 5, 7),
        MatAdd(7, 6, 7),

        Relu(7, 7),
    };

    auto model = SequentialModel(nodes, mem, "Linear Model");
    const auto compiled_graph = model.compileGraph();

    cpu::CPUExecutionProvider cpuProvider = cpu::CPUExecutionProvider();
    cpuProvider.Initialize();
    cpuProvider.Compile(compiled_graph);
    return 0;
}