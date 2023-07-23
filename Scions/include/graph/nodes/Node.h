//
// Created by sid on 13/7/23.
//
#pragma once

#include "common/common.h"
#include "graph/memory/MemoryObject.h"
#include "graph/OpComputeInfo.h"
#include "graph/ops/Op.h"

namespace sc::graph::node {

class Node : public Op {
  public:
    Node(const char *domainName, const char *opName, const char *opCodeName,
         const op::OpComputeInfo &, uint size,
         std::vector<std::shared_ptr<memory::MemoryObject>> &&memObjects,
         std::vector<Op> &&ops);

    Node(const char *domainName, const char *opName, const char *opCodeName,
         const op::OpComputeInfo &, uint size,
         std::vector<std::shared_ptr<memory::MemoryObject>> &&memObjects);

    const std::vector<std::shared_ptr<sc::memory::MemoryObject>> nodeObjs;
    std::vector<Op> sequential_ops;

    void AddOp(const Op& op);

  private:
    uint nodeSize;
};

} // namespace sc::graph::node