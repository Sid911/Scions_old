//
// Created by sid on 13/7/23.
//

#include "Node.h"
namespace sc::graph::node {
 Node::Node(const char *domainName, const char *opName,
                     const char *opCodeName,
                     const op::OpComputeInfo &opComputeInfo, uint size,
                     std::vector<std::shared_ptr<memory::MemoryObject>> &&memObjs,
                     std::vector<Op>&& ops)
    : Op(opName, opCodeName, domainName, opComputeInfo), nodeSize(size),
      sequential_ops(ops), nodeObjs(memObjs) {}


Node::Node(const char *domainName, const char *opName,
           const char *opCodeName,
           const op::OpComputeInfo &opComputeInfo, uint size,
           std::vector<std::shared_ptr<memory::MemoryObject>> &&memObjs)
    : Op(opName, opCodeName, domainName, opComputeInfo), nodeSize(size),nodeObjs(memObjs) {}

void Node::AddOp(const Op& op){
    sequential_ops.push_back(op);
}
} // namespace sc::graph::node