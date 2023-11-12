//
// Created by sid on 1/11/23.
//

#pragma once
#include "ep/common/common.h"
namespace scions::ep::cpu::mem {

struct CPUMemObject {
    std::unique_ptr<char*> data;
};

} // namespace scions::ep::cpu::mem



