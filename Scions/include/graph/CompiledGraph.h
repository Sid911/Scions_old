//
// Created by sid on 23/7/23.
//
#pragma

#include "common/common.h"
#include "memory/MemoryObject.h"
#include "nodes/Node.h"

using namespace std;

namespace sc::graph {
struct CompiledGraph {
    vector<memory::MemoryObjectPtr> memoryObjs;
    shared_ptr<vector<Op>> ops;
};
} // namespace sc::graph