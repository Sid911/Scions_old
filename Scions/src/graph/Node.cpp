//
// Created by sid on 13/7/23.
//

#include "graph/Node.h"

namespace sc::graph::node {

Node::Node(const char *domainName, const char *opName, const char *opCodeName,
           NodeComputeInfo computeInfo)
    : domainName(domainName), opName(opName), opCodeName(opCodeName),
      computeInfo(std::move(computeInfo)) {}

Node::Node(const char *domainName, const char *opName, const char *opCodeName,
           uint size)
    : domainName(domainName), opName(opName), opCodeName(opCodeName) {
    computeInfo = NodeComputeInfo{{{size}}, {{size}}};
}

} // namespace sc::graph::node