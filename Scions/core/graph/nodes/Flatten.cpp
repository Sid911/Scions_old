//
// Created by sid on 15/7/23.
//

#include "Flatten.h"
#include "NodeTypes.h"
namespace sc::graph::node {

Flatten::Flatten(uint size, const char *domainName)
    : Node(domainName, FLATTEN_NAME, FLATTEN_CODE_NAME, size) {}

} // namespace sc::graph::node