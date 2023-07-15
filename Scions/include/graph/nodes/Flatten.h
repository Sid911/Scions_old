//
// Created by sid on 15/7/23.
//

#pragma once

#include "graph/Node.h"

namespace sc::graph::node {

class Flatten : public Node {
  public:
    Flatten(const char *domainName, const NodeComputeInfo &computeInfo);

    Flatten(const char *domainName, uint size);
};

} // namespace sc::graph::node
