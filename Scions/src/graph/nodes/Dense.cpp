//
// Created by sid on 15/7/23.
//

#include "graph/nodes/Dense.h"
#include "graph/nodes/NodeTypes.h"
namespace sc::graph::node {

Dense::Dense(const char *domainName, const NodeComputeInfo &computeInfo)
    : Node(domainName, DENSE_NAME, DENSE_CODE_NAME, computeInfo) {}

Dense::Dense(const char *domainName, uint size)
    : Node(domainName, DENSE_NAME, DENSE_CODE_NAME, size) {}
} // namespace sc::graph::node
