#pragma once
#include "common/common.h"
#include "core/tensor/TensorShape.h"

namespace sc::memory {
using namespace sc::tensor;

class MemoryObject {
  private:
    const TensorShape shape;
    const TensorShape mask;
    const char *name;

  public:
    MemoryObject(const TensorShape &shape, const char *name = "MemObj");
    MemoryObject(TensorShape shape, TensorShape mask,
                 const char *name = "MemObjWMask");

    // Get the shape of the memory object
    [[nodiscard]] const TensorShape &getShape() const;
};

using MemoryObjectPtr = std::shared_ptr<MemoryObject>;

MemoryObjectPtr CreateMemoryObjectPtr(const TensorShape &shape,
                                      const char *name = "MemObj");

MemoryObjectPtr CreateMemoryObjectPtr(const TensorShape &shape,
                                      TensorShape &mask,
                                      const char *name = "MemObj");
} // namespace sc::memory
