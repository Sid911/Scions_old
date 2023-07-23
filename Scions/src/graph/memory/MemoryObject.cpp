//
// Created by sid on 18/7/23.
//

#include "graph/memory/MemoryObject.h"

namespace sc::memory {
MemoryObject::MemoryObject(const TensorShape &shape, const char *name)
    : shape(shape), name(name), mask(shape.copyWithValues({})) {}

MemoryObject::MemoryObject(TensorShape shape, TensorShape mask,
                           const char *name)
    : shape(std::move(shape)), name(name), mask(std::move(mask)) {}
const TensorShape &MemoryObject::getShape() const { return shape; }

MemoryObjectPtr CreateMemoryObjectPtr(const TensorShape &shape,
                                      const char *name) {
    return std::make_shared<MemoryObject>(MemoryObject(shape, name));
}
MemoryObjectPtr CreateMemoryObjectPtr(const TensorShape &shape,
                                      TensorShape &mask, const char *name) {
    return std::make_shared<MemoryObject>(MemoryObject(shape, mask, name));
}
} // namespace sc::memory
