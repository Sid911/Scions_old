//
// Created by sid on 13/7/23.
//

#include "graph/Node.h"

namespace sc::graph::node {

Node::Node(const char *domainName, const char *opName, const char *opCodeName,
           NodeComputeInfo computeInfo)
    : domainName(domainName), opName(opName), opCodeName(opCodeName),
      computeInfo(std::move(computeInfo)), sequential_ops({}) {}

Node::Node(const char *domainName, const char *opName, const char *opCodeName,
           uint size)
    : domainName(domainName), opName(opName), opCodeName(opCodeName),
      sequential_ops({}) {
    computeInfo = NodeComputeInfo{{{size}}, {{size}}};
}

} // namespace sc::graph::node