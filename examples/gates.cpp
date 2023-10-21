#include "core/mem/mem_desc.h"
#include "core/op/basic_op.h"
#include "core/op/op.h"
#include "core/op/tensor_op.h"
#include "vector"

using namespace std;


[[nodiscard]] consteval scions::mem::MemDescriptor<4> buildGraph() {

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

    return desc;
}

int main() {
    static constexpr auto res = buildGraph();
}