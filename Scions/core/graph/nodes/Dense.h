//
// Created by sid on 15/7/23.
//

#pragma once

#include "common.h"
#include "Node.h"

namespace sc::graph::node {

class Dense : public node::Node {
  public:
    explicit Dense(uint size,
                             const char *domainName = DEFAULT_DOMAIN);
};
} // namespace sc::graph::node
