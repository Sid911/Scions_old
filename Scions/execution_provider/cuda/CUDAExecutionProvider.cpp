//
// Created by sid on 24/7/23.
//

#include "CUDAExecutionProvider.h"

namespace sc::ep::cuda {
using namespace sc::result;
CUDAExecutionProvider::~CUDAExecutionProvider() = default;

sc::Result<bool, bool> CUDAExecutionProvider::Initialize() {
    return sc::Result<bool, bool>(types::Ok(true));
}
sc::Result<bool, bool>
CUDAExecutionProvider::Compile(const graph::CompiledGraph &compiledGraph) {
    return sc::Result<bool, bool>(types::Ok(true));
}
sc::Result<bool, bool> CUDAExecutionProvider::Execute() {
    return sc::Result<bool, bool>(types::Ok(true));
}
} // namespace sc::ep::cuda