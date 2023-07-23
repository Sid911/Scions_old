#pragma once

#include "OpTypes.h"
namespace sc::graph {

struct Op {
    const char *opName;
    const char *opCode;
    const char *domain;
    const bool isUnary;

    op::OpComputeInfo computeInfo;

    Op(const char *name, const char *code, const char *domain,
       op::OpComputeInfo computeInfo, const bool isUnary = false)
        : opName(name), opCode(code), domain(domain), isUnary(isUnary),
          computeInfo(std::move(computeInfo)) {}
};

struct UnaryOp : public Op {
    const sc::tensor::TensorShape inputShape;

    UnaryOp(const char *name, const char *code, const char *domain,
            const op::OpComputeInfo &computeInfo)
        : Op(name, code, domain, computeInfo, true){}
};

} // namespace sc::graph

namespace sc::graph::op {

class MatMul : public Op {
  public:
    explicit MatMul(const OpComputeInfo &computeInfo)
        : Op(MATMUL_NAME, MATMUL_CODE_NAME, DEFAULT_DOMAIN, computeInfo) {}
};

class MatAdd : public Op {
  public:
    explicit MatAdd(const OpComputeInfo &computeInfo)
        : Op(MATADD_NAME, MATADD_CODE_NAME, DEFAULT_DOMAIN, computeInfo) {}
};

class MatReshape: public UnaryOp{
  public:
    explicit MatReshape(const OpComputeInfo &computeInfo)
        : UnaryOp(MATRESHAPE_NAME, RELU_ACT_CODE_NAME, DEFAULT_DOMAIN, computeInfo) {}
};

class Relu: public UnaryOp{
  public:
    explicit Relu(const OpComputeInfo &computeInfo)
    : UnaryOp(RELU_ACT_NAME, RELU_ACT_CODE_NAME, DEFAULT_DOMAIN, computeInfo) {}
};

} // namespace sc::graph::op