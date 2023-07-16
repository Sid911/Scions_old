//
// Created by sid on 13/7/23.
//

#include "graph/SequentialModel.h"

#include <utility>

namespace sc::graph {
SequentialModel::SequentialModel(std::vector<node::Node> nodes, std::string name): nodes(std::move(nodes)), name(std::move(name)){};
SequentialModel::SequentialModel(std::vector<node::Node>) {}

Result<bool, std::string> SequentialModel::Add(node::Node &) {
    return Result<bool, std::string>(sc::result::types::Ok());
}
} // namespace sc::graph