//
// Created by sid on 23/10/23.
//

#pragma once

#include "core/mem/mem_object.h"
#include "core/op/op.h"
#include "ep/common/common.h"

namespace scions::graph {
class RuntimeSequentialGraph {
  public:
    RuntimeSequentialGraph(std::span<const mem::MemObject> &mem_span,
                           std::span<const op::OpDesc> &op_span);

  private:
    std::span<const mem::MemObject> mem_objects;
    std::span<const op::OpDesc> ops;
};
}