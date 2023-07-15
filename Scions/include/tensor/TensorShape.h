#pragma once

#include "common/common.h"

namespace sc::tensor {
#define ShapeIndexType uint
class TensorShape {
  public:
    // Default constructor
    TensorShape() = default;

    // Initialize with a shape from std::initializer_list
    TensorShape(std::initializer_list<ShapeIndexType> init_list)
        : shape_(init_list) {}

    // Initialize with a shape from std::vector
    explicit TensorShape(const std::vector<ShapeIndexType> &shape) : shape_(shape) {}

    // Initialize with a shape from std::span
    explicit TensorShape(const std::span<ShapeIndexType> &shape)
        : shape_(shape.begin(), shape.end()) {}

    // Initialize with a shape from std::array
    template <std::size_t N>
    explicit TensorShape(const std::array<ShapeIndexType, N> &shape)
        : shape_(shape.begin(), shape.end()) {}

    // Initialize with a shape from std::list
    explicit TensorShape(const std::list<ShapeIndexType> &shape)
        : shape_(shape.begin(), shape.end()) {}

    // Represent as a string
    [[nodiscard]] std::string toString() const {
        std::ostringstream oss;
        if (!shape_.empty()) {
            copy(shape_.begin(), shape_.end() - 1,
                 std::ostream_iterator<int>(oss, ","));
            oss << shape_.back();
        }
        return oss.str();
    }

    // Get const version of shape
    [[nodiscard]] const std::vector<ShapeIndexType> &getShape() const {
        return shape_;
    }

    // Convert shape vector into a span
    std::span<ShapeIndexType> toSpan() { return {shape_.data(), shape_.size()}; }

    [[nodiscard]] std::span<const ShapeIndexType> toSpan() const {
        return {shape_.data(), shape_.size()};
    }

    // Overload of ostream operator for easy printing
    friend std::ostream &operator<<(std::ostream &os, const TensorShape &ts) {
        return os << ts.toString();
    }

  private:
    std::vector<ShapeIndexType> shape_;
};

} // namespace sc::tensor