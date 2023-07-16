//
// Created by sid on 10/7/23.

//
#include "algorithm"
#include "graph/nodes/Dense.h"
#include "graph/nodes/Flatten.h"
#include "graph/SequentialModel.h"
#include "vector"
using namespace std;
int main() {
    using namespace sc::graph;
    vector<node::Node> layers = {
        node::Flatten(1),
        node::Dense(2),
        node::Dense(1),
    };
    auto model = SequentialModel(layers, "Linear Model");
    return 0;
}