//
// Created by sid on 23/10/23.
//

#pragma once

#include "core/graph/sequential_graph.h"
#include "core/mem/mem_object.h"
#include "core/op/op.h"
#include "ep/common/common.h"

namespace scions::graph {
class RuntimeSequentialGraph {
  public:
    RuntimeSequentialGraph(std::span<const mem::MemObject> &mem_span,
                           std::span<const op::OpDesc> &op_span,
                           uint64_t memory_size
                           );

    template <size_t Ops, size_t Mem>
    RuntimeSequentialGraph(
        const SequentialGraph<Ops, Mem> &graph)
        :mem_objects(std::span(graph.memDescriptor.memoryObjects)),
         ops(std::span(graph.ops)),
         total_memory_size(graph.memDescriptor.getTotalBytes())
    {

    }

    std::span<const mem::MemObject> mem_objects;
    uint64_t total_memory_size;
    std::span<const op::OpDesc> ops;
};
}