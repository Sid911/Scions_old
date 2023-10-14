//
// Created by sid on 13/10/23.
//

#include "op.h"


namespace scions::op {

    constexpr OpDesc::OpDesc(int32_t id, int32_t input_length, int32_t output_len, const char *desc) :
            op_id(id),
            input_len(input_length),
            output_len(output_len) {}

    constexpr std::string_view OpDesc::getDesc() {
        return std::string_view(op_desc);
    }
} // scions
// op