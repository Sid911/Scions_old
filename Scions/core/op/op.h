//
// Created by sid on 13/10/23.
//

#pragma once

#include <utility>

#include "common/common.h"
#include "op_io.h"

namespace scions::op {

class OpDesc {
  public:
    int32_t op_id;
    OpIOInfo info;

    constexpr OpDesc(int32_t id, OpIOInfo info, const std::string_view &desc)
        : op_id(id), op_desc(desc), info(info) {}

    constexpr OpDesc(int32_t id, const std::span<const uint32_t> &inp,
                     const std::span<const uint32_t> &out,
                     const std::string_view &desc)
        : op_id(id), op_desc(desc), info({inp, out}) {}

    constexpr std::string_view getDesc() { return op_desc; }

  private:
    const std::string_view op_desc;
};

} // namespace scions::op
// op
