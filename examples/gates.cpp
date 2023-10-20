#define SC_OP_INPUT_MAX 5

#include "core/mem/mem_desc.h"
#include "core/op/basic_op.h"
#include "core/op/op.h"
#include "core/op/tensor_op.h"
#include "vector"
#include <utility>
using namespace std;

// Node struct representing a node in the graph
struct Node {
    int value;
    std::array<const Node *, 2>
        children; // Use std::array to represent child nodes
};

// Function to build a sequence of nodes at consteval time
consteval std::array<Node, 3> buildNodeSequence() {
    return {
        Node{1, {nullptr, nullptr}},
        Node{2, {nullptr, nullptr}},
        Node{3, {nullptr, nullptr}},
    };
}

// Function to create a graph structure from a sequence of nodes
constexpr Node createGraph(const std::array<Node, 3> &nodeSequence) {
    Node root = nodeSequence[0];
    root.children[0] = &nodeSequence[1];
    root.children[1] = &nodeSequence[2];
    return root;
}

// Function to print the graph starting from a given node
void printGraph(const Node &node, int depth = 0) {
    for (int i = 0; i < depth; ++i) {
        std::cout << "  ";
    }
    std::cout << node.value << "\n";
    for (const Node *child : node.children) {
        if (child != nullptr) {
            printGraph(*child, depth + 1);
        }
    }
}

[[nodiscard]] consteval scions::mem::MemDescriptor<4> buildGraph() {

    // Alright here will be the example start
    using namespace scions;

    static constexpr array<mem::StaticMemObject, 4> objects = {
        mem::StaticMemObject(1020, "inp1"),
        mem::StaticMemObject(2, 4, 5, "inp2"),
        mem::StaticMemObject({2, 3, 4}, "inp3"),
        mem::StaticMemObject({2, 3, 4}, "inp4"),
    };

    constexpr mem::MemDescriptor desc = mem::MemDescriptor(objects);

    constexpr std::array<op::OpDesc, 2> tensors = {
        op::tensor::TensorAddOpDesc(0, 1, 2),
        op::tensor::TensorMultiplyOpDesc(0, 3, 2),
    };

    return desc;
}

int main() {
    static constexpr auto res = buildGraph();

    static constexpr std::array<Node, 3> nodeSequence = buildNodeSequence();
    constexpr Node graph = createGraph(nodeSequence);

    std::cout << "Graph created at runtime from a sequence of nodes:\n";
    printGraph(graph);
}