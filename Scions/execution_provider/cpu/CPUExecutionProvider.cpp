//
// Created by sid on 23/7/23.
//

#include "CPUExecutionProvider.h"


namespace sc::ep::cpu {
using namespace sc::result;
sc::ep::cpu::CPUExecutionProvider::~CPUExecutionProvider() = default;

sc::Result<bool, bool> CPUExecutionProvider::Initialize() {
    return sc::Result<bool, bool>(types::Ok(true));
}

sc::Result<bool, bool> CPUExecutionProvider::Compile(
    const sc::graph::CompiledGraph &compiledGraph) {
    return sc::Result<bool, bool>(types::Ok(true));
}

sc::Result<bool, bool> CPUExecutionProvider::Execute() {
    return sc::Result<bool, bool>(types::Ok(true));
}
}