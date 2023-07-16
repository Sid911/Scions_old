//
// Created by sid on 15/7/23.
//

#include "graph/nodes/Dense.h"
#include "graph/nodes/NodeTypes.h"
namespace sc::graph::node {

Dense::Dense(const NodeComputeInfo &computeInfo, const char *domainName)
    : Node(domainName, DENSE_NAME, DENSE_CODE_NAME, computeInfo) {}

Dense::Dense(uint size, const char *domainName)
    : Node(domainName, DENSE_NAME, DENSE_CODE_NAME, size) {}


} // namespace sc::graph::node
