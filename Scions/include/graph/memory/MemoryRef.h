//
// Created by sid on 18/7/23.
//

#pragma once

#include "common/common.h"
#include "MemoryObject.h"

namespace sc::memory {

class MemoryRef {
  public:
    MemoryRef(const std::shared_ptr<MemoryObject> &ptr) : objPtr(ptr){};

  private:
    const std::shared_ptr<MemoryObject> objPtr;
};
} // namespace sc::memory
