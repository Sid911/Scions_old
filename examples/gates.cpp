#include "core/graph/sequential_graph.h"
#include "core/mem/mem_desc.h"
#include "core/op/basic_op.h"
#include "core/op/op.h"
#include "core/op/tensor_op.h"
#include "ep/cpu/cpu_ep.h"
#include "random"

using namespace std;

// builds the graph at compile time
[[nodiscard]] consteval auto buildGraph() {

    // Alright here will be the example start
    using namespace scions;

    static constexpr array<mem::StaticMemObject, 4> objects = {
        mem::StaticMemObject(16, "inp1"),
        mem::StaticMemObject(1, 2, 3, "inp2"),
        mem::StaticMemObject({1024*10, 1024*10}, "inp3"),
        mem::StaticMemObject({64, 64, 64}, "inp4"),
    };

    constexpr mem::MemDescriptor desc = mem::MemDescriptor(objects);

    constexpr std::array<op::OpDesc, 2> tensors = {
        op::tensor::TensorAddOpDesc(0, 1, 2),
        op::tensor::TensorMultiplyOpDesc(0, 3, 2),
    };

    constexpr graph::SequentialGraph<2, 4> graph = {tensors, desc};

    return graph;
}

int main() {
    using namespace scions;
    using namespace scions::ep;
    // Compile time graph
    static constexpr auto res = buildGraph();
    // generate Runtime Reference to the graph
    const graph::RuntimeSequentialGraph graph =
        graph::RuntimeSequentialGraph(res);
    // set CPUExecutionProvider Options
    constexpr cpu::CPUOptions options{true};
    //  set the provider
    cpu::CPUExecutionProvider provider =
        cpu::CPUExecutionProvider(graph, options);

    // Generate data for
    auto result = provider.allocateAll();

    return 0;
}
