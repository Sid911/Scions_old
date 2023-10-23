//
// Created by sid on 21/10/23.
//

#pragma once

#include "common/common.h"
#include "core/op/op.h"
#include "core/mem/mem_desc.h"

namespace scions::graph {
template <size_t Ops, size_t Mem>
struct SequentialGraph {
    std::array<op::OpDesc, Ops>  ops;
    mem::MemDescriptor<Mem> memDescriptor;
};
}