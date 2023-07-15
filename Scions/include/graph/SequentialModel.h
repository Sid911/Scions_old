//
// Created by sid on 13/7/23.
//
#pragma once

#include "common/common.h"
#include "Node.h"

namespace sc::graph {

    class SequentialModel {
    public:
        SequentialModel(std::vector<Node>, std::string);
        SequentialModel(std::vector<Node>);
        SequentialModel() = default;

        Result<bool, std::string> Add(Node&);
    private:
        std::vector<Node> nodes;
        std::string name;
    };

} // sc
// graph


