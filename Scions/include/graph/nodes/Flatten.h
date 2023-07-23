//
// Created by sid on 15/7/23.
//

#pragma once

#include "Node.h"

namespace sc::graph::node {

class Flatten : public Node {
  public:
    explicit Flatten(uint size, const char *domainName = DEFAULT_DOMAIN);
};

} // namespace sc::graph::node
