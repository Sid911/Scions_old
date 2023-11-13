//
// Created by sid on 13/11/23.
//
#pragma once

#include "core/op/op.h"

namespace scions::ep::cpu::_internal{
void tensorAdd(scions::op::OpDesc& desc, std::span<uint8_t *>& span);
void tensorMul(scions::op::OpDesc& desc, std::span<uint8_t *>& span);
}