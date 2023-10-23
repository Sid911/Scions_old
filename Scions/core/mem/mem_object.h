//
// Created by sid on 13/10/23.
//

#pragma once
#include "common/common.h"
#include "common/d_type.h"

namespace scions::mem {

/**
 * @class StaticMemObject
 * @brief Represents a static memory object with a fixed size and shape.
 *
 * The StaticMemObject class provides a convenient way to define and manage static memory objects.
 * It supports objects of different dimensions (1D, 2D, 3D, etc.) and provides information about the object's
 * total size and data type.
 */
class StaticMemObject {
  public:
    // total size in bytes
    uint64_t total_size;
    const std::string_view name;
    const uint32_t dimension;
    const d_type::TYPE data_type;
    std::array<uint32_t, SC_MAX_DIMS> shape;

    /**
     * @brief Constructs a StaticMemObject with the given size, name, and data type.
     * @param size The total size of the memory object in bytes.
     * @param name The name of the memory object.
     * @param type The data type of the memory object (default: d_type::F16).
     * @throws std::logic_error If the shape of input (bytes) is not divisible by the size of the data type.
     *
     * This consteval constructor initializes a StaticMemObject with the specified size, name, and data type.
     * It also determines the dimension and shape of the memory object based on the size.
     * If the total size is not divisible by the size of the data type, a std::logic_error is thrown.
     */
    consteval StaticMemObject(const uint32_t size, std::string_view name,
                              const d_type::TYPE type = d_type::F16)
        : total_size(size), name(name), dimension(1), data_type(type),
          shape({size}) {
        if (total_size % d_type::getDTypeSize(data_type) != 0){
            throw std::logic_error("Shape of input (bytes) is not divisible by size of data type. Please correct.");
        }
    }

    /**
     * @brief A class representing a static memory object.
     *
     * This class represents a static memory object with a given size, name, type, and shape.
     * The size is calculated as the product of the given dimensions and the size of the data type.
     *
     */
    constexpr StaticMemObject(uint32_t x, uint32_t y, std::string_view name,
                              d_type::TYPE type = d_type::F16)
        : total_size(x * y * d_type::getDTypeSize(type)), name(name), dimension(2),
          data_type(type), shape({x, y}) {
    }

    /**
     * @class StaticMemObject
     * @brief Represents a static memory object with a fixed size and shape.
     *
     * The StaticMemObject class provides a convenient way to define and manage static memory objects.
     * It supports objects of different dimensions (1D, 2D, 3D, etc.) and provides information about the object's
     * total size and data type.
     */
    constexpr StaticMemObject(uint32_t x, uint32_t y, uint32_t z,
                              std::string_view name,
                              d_type::TYPE type = d_type::F16)
        : total_size(x * y * z * d_type::getDTypeSize(type)), name(name), dimension(3),
          data_type(type), shape({x, y, z}) {
    }

    /**
     * @consteval StaticMemObject
     * @brief Constructs a StaticMemObject with the given initializer list, name, and data type.
     * @param list An initializer list containing the dimensions of the memory object.
     * @param name The name of the memory object.
     * @param type The data type of the memory object (default: d_type::F16).
     *
     * This consteval constructor initializes a StaticMemObject with the specified dimensions, name, and data type.
     * It calculates the total size of the memory object based on the dimensions and data type.
     * The dimensions are stored in the shape array, up to a maximum of SC_MAX_DIMS.
     * If the total size is not divisible by the size of the data type, a std::logic_error is thrown.
     * The total size is stored in the total_size variable.
     */
    consteval StaticMemObject(std::initializer_list<uint32_t> list,
                              std::string_view name,
                              d_type::TYPE type = d_type::F16)
        : name(name),
          dimension(SC_MAX_DIMS > list.size() ? list.size() : SC_MAX_DIMS),
          data_type(type), shape() {

        total_size = 1;
        uint16_t i = 0;
        for (uint32_t val : list) {
            if (i >= dimension)
                break;
            total_size *= val;
            shape[i] = val;
            i++;
        }
        total_size *= d_type::getDTypeSize(type);
    }
};

class MemObject {
  public:
    uint64_t total_size;
    uint64_t id;
    std::string_view name;
    d_type::TYPE type;

    constexpr MemObject()
        : total_size(0), id(-1), name("bruh"), type(d_type::TYPE::F16){};

    constexpr MemObject(uint64_t size, std::string_view name, uint64_t id,
                        d_type::TYPE type = d_type::F16)
        : name(name), total_size(size), id(id), type(type) {
      if (total_size % d_type::getDTypeSize(type) != 0){
          throw std::logic_error("Size of input (bytes) is not divisible by size of data type. Please correct.");
      }
    }

    constexpr MemObject(StaticMemObject object, uint64_t id)
        : name(object.name), total_size(object.total_size), id(id),
          type(object.data_type) {
      if (total_size % d_type::getDTypeSize(type) != 0){
          throw std::logic_error("Size of input (bytes) is not divisible by size of data type. Please correct.");
      }
    }
};
} // namespace scions::mem