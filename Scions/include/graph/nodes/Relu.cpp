//
// Created by sid on 16/7/23.
//

#include "Relu.h"
#include "NodeTypes.h"

namespace sc::graph::node {

Relu::Relu(const OpComputeInfo &computeInfo, const char *domainName)
    : Node(domainName, RELU_NAME, RELU_CODE_NAME, computeInfo) {}

Relu::Relu(uint size, const char *domainName)
    : Node(domainName, RELU_NAME, RELU_CODE_NAME, size) {}

} // namespace sc::graph::node

