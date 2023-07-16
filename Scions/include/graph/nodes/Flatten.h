//
// Created by sid on 15/7/23.
//

#pragma once

#include "graph/Node.h"

namespace sc::graph::node {

class Flatten : public Node {
  public:
    Flatten(const NodeComputeInfo &computeInfo, const char *domainName = DEFAULT_DOMAIN);

    Flatten(uint size, const char *domainName = DEFAULT_DOMAIN);
};

} // namespace sc::graph::node
