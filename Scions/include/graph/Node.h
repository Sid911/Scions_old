//
// Created by sid on 13/7/23.
//
#pragma once

#include "common/common.h"
#include "NodeComputeInfo.h"

namespace sc::graph::node {

class Node {
    const char *domainName;
    const char *opName;
    const char *opCodeName;

  public:
     Node(const char *domainName, const char *opName, const char *opCodeName,
         NodeComputeInfo computeInfo);

    Node(const char *domainName, const char *opName, const char *opCodeName, uint size);

    NodeComputeInfo computeInfo;
};

} // namespace sc::graph