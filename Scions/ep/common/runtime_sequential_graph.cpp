//
// Created by sid on 23/10/23.
//
#include "runtime_sequential_graph.h"

namespace scions::graph{
RuntimeSequentialGraph::RuntimeSequentialGraph(
    std::span<const mem::MemObject> &mem_span, std::span<const op::OpDesc> &op_span)
    : mem_objects(mem_span), ops(op_span) {}
}
