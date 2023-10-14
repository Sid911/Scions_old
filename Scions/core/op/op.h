//
// Created by sid on 13/10/23.
//

#pragma once

#include "common/common.h"

namespace scions::op {

    class OpDesc {
    public:
        int32_t op_id;
        int32_t input_len;
        int32_t output_len;

        constexpr OpDesc(int32_t id, int32_t input_length, int32_t output_len, const char *desc);

        constexpr std::string_view getDesc();

    private:
        const std::string op_desc;
    };

} // scions
// op
