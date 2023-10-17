#include "vector"
#include "core/mem/mem_desc.h"
#include "core/op/op.h"
#include "core/op/basic_op.h"

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
    // Alright here will be the example start
    using namespace scions;

    static constexpr array<mem::StaticMemObject, 3> objects = {
        mem::StaticMemObject(1020, "inp1"),
        mem::StaticMemObject(2,4,5, "inp2"),
        mem::StaticMemObject({2,3,4}, "inp3"),
    };
    // Maybe even dynamicMemObject initialized at runtime
    // Pass the objects to MemDescriptor
    static constexpr mem::MemDescriptor desc = mem::MemDescriptor(objects);

    // what are different ways an op can take reference to its input from MemObjects passed to
    // MemDescriptor. One option is using indices but that seems wierd
    static constexpr auto arr = std::array<uint32_t ,2>({2,3});
    static constexpr auto arr2 = std::array<uint32_t ,1>({4});


    static constexpr auto arr1_1 = std::array<uint32_t ,3>({5,7,1});
    static constexpr auto arr1_2 = std::array<uint32_t ,1>({8});

    static constexpr array<op::OpDesc, 2> ops = {
        op::TensorOpDesc<2,1>(arr, arr2),
        op::TensorOpDesc<3,1>(arr1_1, arr1_2),
    };

    /**
     *  This seems pretty bad if user had to put in all the indexes for each memory
     *  instance. Maybe generate reference from memDescriptor?
     */
}