//
// Created by sid on 15/7/23.
//

#include "graph/nodes/Flatten.h"
#include "graph/nodes/NodeTypes.h"
namespace sc::graph::node {

Flatten::Flatten(const char *domainName, const NodeComputeInfo &computeInfo)
    : Node(domainName, FLATTEN_NAME, FLATTEN_CODE_NAME, computeInfo) {}

Flatten::Flatten(const char *domainName, uint size)
    : Node(domainName, FLATTEN_NAME, FLATTEN_CODE_NAME, size) {}

} // namespace sc::graph::node