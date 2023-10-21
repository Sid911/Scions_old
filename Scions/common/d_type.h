//
// Created by sid on 20/10/23.
//
#pragma once
#include <cstdint>
namespace scions::d_type {
enum TYPE {
    INT8,
    INT16,
    INT32,
    INT64,
    F16,
    F32,
    F64,
};

constexpr uint8_t getDTypeSize(const TYPE t){
    switch (t) {
    case INT8:
        return 8;
    case INT16:
        return 16;
    case INT32:
        return 32;
    case INT64:
        return 64;
    case F16:
        return 16;
    case F32:
        return 32;
    case F64:
        return 64;
    }
}

} // namespace scions::d_type