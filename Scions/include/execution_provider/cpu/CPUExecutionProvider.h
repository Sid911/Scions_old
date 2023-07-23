#pragma once

#include "execution_provider/IExecutionProvider.h"
namespace sc::ep::cpu {
class CPUExecutionProvider : IExecutionProvider {
  public:
    ~CPUExecutionProvider() override;
    sc::Result<bool, bool> Initialize() override;

    sc::Result<bool, bool>
    Compile(const graph::CompiledGraph &compiledGraph) override;

    sc::Result<bool, bool> Execute() override;
  private:
};
} // namespace sc::ep::cpu
