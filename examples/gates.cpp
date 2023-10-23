#include "core/graph/sequential_graph.h"
#include "core/mem/mem_desc.h"
#include "core/op/basic_op.h"
#include "core/op/op.h"
#include "core/op/tensor_op.h"
#include "ep/cpu/CPUExecutionProvider.h"
#include "vector"

using namespace std;

// builds the graph at compile time
[[nodiscard]] consteval auto buildGraph() {

    // Alright here will be the example start
    using namespace scions;

    static constexpr array<mem::StaticMemObject, 4> objects = {
        mem::StaticMemObject(16, "inp1"),
        mem::StaticMemObject(1, 2, 3, "inp2"),
        mem::StaticMemObject({32, 32, 32}, "inp3"),
        mem::StaticMemObject({64, 64, 64}, "inp4"),
    };

    constexpr mem::MemDescriptor desc = mem::MemDescriptor(objects);

    constexpr std::array<op::OpDesc, 2> tensors = {
        op::tensor::TensorAddOpDesc(0, 1, 2),
        op::tensor::TensorMultiplyOpDesc(0, 3, 2),
    };

    static constexpr graph::SequentialGraph<2, 4> graph = {tensors, desc};

    return graph;
}

int main() {
    using namespace scions;
    using namespace scions::ep;
    // Compile time graph
    static constexpr auto res = buildGraph();
    // Runtime reference to the graph
    // create view to the generated graph
    std::span<const mem::MemObject> mem_span =
        std::span(res.memDescriptor.memoryObjects);
    std::span<const op::OpDesc> op_span = std::span(res.ops);
    // generate Runtime Reference to the graph
    const graph::RuntimeSequentialGraph graph =
        graph::RuntimeSequentialGraph(mem_span, op_span);
    // set CPUExecutionProvider Options
    const cpu::CPUOptions options{true};
    //  set the provider
    const cpu::CPUExecutionProvider provider =
        cpu::CPUExecutionProvider(graph, options);

    return 0;
}
