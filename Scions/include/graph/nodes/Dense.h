//
// Created by sid on 15/7/23.
//

#pragma once

#include "common/common.h"
#include "graph/Node.h"

namespace sc::graph::node {

class Dense : public node::Node {
  public:
    Dense(const NodeComputeInfo &computeInfo, const char *domainName = DEFAULT_DOMAIN);

    Dense(uint size, const char *domainName = DEFAULT_DOMAIN);
};
} // namespace sc::graph::node
