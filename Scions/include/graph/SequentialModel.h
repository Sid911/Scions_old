//
// Created by sid on 13/7/23.
//
#pragma once

#include "common/common.h"
#include "Node.h"

namespace sc::graph {

    class SequentialModel {
    public:
        SequentialModel(std::vector<node::Node>, std::string);
        SequentialModel(std::vector<node::Node>);
        SequentialModel() = default;

        Result<bool, std::string> Add(node::Node&);
    private:
        std::vector<node::Node> nodes;
        std::string name;
    };

} // sc
// graph


