//
// Created by sid on 16/7/23.
//

#pragma once
#include "../../../common/common.h"
#include "Node.h"
namespace sc::graph::node {

class Relu : public Node {

    Relu(const op::OpComputeInfo &computeInfo, const char *domainName = DEFAULT_DOMAIN);

    Relu(uint size, const char *domainName = DEFAULT_DOMAIN);
};

} // namespace sc::graph::node


