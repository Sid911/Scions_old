//
// Created by sid on 15/7/23.
//

#pragma once

#include "common/common.h"
#include "graph/Node.h"

namespace sc::graph::node {

class Dense : public node::Node {
  public:
    Dense(const char *domainName, const NodeComputeInfo &computeInfo);

    Dense(const char *domainName, uint size);
};
} // namespace sc::graph::node
