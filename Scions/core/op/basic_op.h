//
// Created by sid on 17/10/23.
//
#pragma once
#include "common/common.h"
#include "op.h"

namespace scions::op {

template <size_t I, size_t O> class TensorOpDesc : public OpDesc {
  public:
    constexpr TensorOpDesc(const std::array<uint32_t, I> &input,
                           const std::array<uint32_t, O> &output)
        : input_vec(input), output_vec(output),
          OpDesc(1, input, output, "Tensor Op") {}

    constexpr TensorOpDesc(const )

  private:
    const std::array<uint32_t, I> input_vec;
    const std::array<uint32_t, O> output_vec;
};
} // namespace scions::op
