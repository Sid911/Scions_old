//
// Created by sid on 16/7/23.
//

#pragma once

#include "graph/nodes/NodeTypes.h"
namespace sc::graph {

struct Op {
    const char *name;
    const char *code;
    const char *domain;

    Op(const char *name, const char *code, const char *domain)
        : name(name), code(code), domain(domain) {}
};

struct ReluOp : public Op {
    ReluOp() : Op(node::RELU_NAME, node::RELU_CODE_NAME, DEFAULT_DOMAIN) {}
};

} // namespace sc::graph
