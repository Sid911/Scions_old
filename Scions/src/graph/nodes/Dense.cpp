//
// Created by sid on 15/7/23.
//

#include "graph/nodes/Dense.h"
#include "graph/nodes/NodeTypes.h"
namespace sc::graph::node {
using namespace std;
Dense::Dense(const uint size, const char *domainName)
    : Node(domainName, DENSE_NAME, DENSE_CODE_NAME, op::OpComputeInfo({}, {}),
           size,
           {
               make_shared<memory::MemoryObject>(
                   memory::MemoryObject(tensor::TensorShape({UINT16_MAX, size}),
                                        tensor::TensorShape({1, 0}))),
               make_shared<memory::MemoryObject>(
                   memory::MemoryObject(tensor::TensorShape({size}))),
           }) {
    AddOp(op::MatMul(op::OpComputeInfo({}, {nodeObjs.at(0)})));
    AddOp(op::MatAdd(op::OpComputeInfo({nodeObjs.at(0)}, {nodeObjs.at(1)})));
}

} // namespace sc::graph::node
