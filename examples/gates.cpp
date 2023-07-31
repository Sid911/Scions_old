//
// Created by sid on 10/7/23.

//

#include "core/graph/memory/MemoryObject.h"
#include "core/graph/nodes/Node.h"
#include "core/graph/OpComputeInfo.h"
#include "core/graph/SequentialModel.h"
#include "execution_provider/cpu/CPUExecutionProvider.h"
#include "vector"
using namespace std;

int main() {
    using namespace sc::graph;
    using namespace sc::memory;
    using namespace sc::graph::op;
    using namespace sc::ep;
    vector<MemoryObjectPtr> allocations = {
        CreateMemoryObjectPtr({1}, "input_layer"),   // 0
        CreateMemoryObjectPtr({1}, "input_reshape"), // 1
        CreateMemoryObjectPtr({1}, "weight_l1"),     // 2
        CreateMemoryObjectPtr({1}, "bias_l1"),       // 3
        CreateMemoryObjectPtr({1}, "activation_l1"), // 4
        CreateMemoryObjectPtr({1}, "weight_l2"),     // 5
        CreateMemoryObjectPtr({1}, "bias_l2"),       // 6
        CreateMemoryObjectPtr({1}, "activation_l2"), // 7
    };

    vector<variant<node::Node, Op>> nodes = {
        // Reshape
        MatReshape(OpComputeInfo({allocations.at(0)}, {allocations.at(1)})),

        // Dense Layer 1
        MatMul(OpComputeInfo({allocations.at(1), allocations.at(2)},
                             {allocations.at(4)})),

        MatAdd(OpComputeInfo(
            {
                allocations.at(4),
                allocations.at(3),
            },
            {
                allocations.at(4),
            })),

        Relu(OpComputeInfo({allocations.at(4)}, {allocations.at(4)})),

        // Dense Layer 2
        MatMul(OpComputeInfo(
            {
                allocations.at(4),
                allocations.at(5),
            },
            {
                allocations.at(7),
            })),

        MatAdd(OpComputeInfo(
            {
                allocations.at(7),
                allocations.at(6),
            },
            {
                allocations.at(7),
            })),

        Relu(OpComputeInfo({allocations.at(7)}, {})),
    };

    auto model = SequentialModel(nodes, allocations, "Linear Model");
    auto compiled_graph = model.compileGraph();

    cpu::CPUExecutionProvider cpuProvider = cpu::CPUExecutionProvider();
    cpuProvider.Initialize();
    cpuProvider.Compile(compiled_graph);
    return 0;
}