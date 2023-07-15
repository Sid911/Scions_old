//
// Created by sid on 13/7/23.
//

#include "graph/SequentialModel.h"

namespace sc::graph {
SequentialModel::SequentialModel(std::vector<Node>, std::string){};
SequentialModel::SequentialModel(std::vector<Node>) {}

Result<bool, std::string> SequentialModel::Add(Node &) {
    return Result<bool, std::string>(sc::result::types::Ok());
}
} // namespace sc::graph