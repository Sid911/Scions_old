//
// Created by sid on 13/7/23.
//
#pragma once

#include "common/common.h"
#include "CompiledGraph.h"
#include "graph/nodes/Node.h"

namespace sc::graph {
using namespace std;
    class SequentialModel {
    public:
        SequentialModel(vector<variant<node::Node, Op>>,vector<shared_ptr<memory::MemoryObject>>, string);
        [[maybe_unused]] explicit SequentialModel(std::vector<std::variant<node::Node, Op>>);
        SequentialModel() = delete;

        Result<bool, std::string> Add(std::variant<node::Node, Op>&);

        sc::graph::CompiledGraph compileGraph();

    private:
        std::vector<std::variant<node::Node, Op>> nodes;
        vector<shared_ptr<memory::MemoryObject>> memoryGraph;
        std::string name;
    };

} // sc
// graph


