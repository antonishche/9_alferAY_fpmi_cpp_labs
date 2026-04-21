#pragma once

#include "../Function/Function.h"
#include "../LinearFunction/LinearFunction.h"
#include "../QuadraticFunction/QuadraticFunction.h"

class FunctionFactory {
  public:
    virtual ~FunctionFactory() = default;
    virtual Function *create() const = 0;
};

class LinearFactory : public FunctionFactory {
  private:
    double a, b;

  public:
    LinearFactory(double a_coef, double b_coef) : a(a_coef), b(b_coef) {}
    Function *create() const override {
        return new LinearFunction(a, b);
    }
};

class QuadraticFactory : public FunctionFactory {
  private:
    double a, b, c;

  public:
    QuadraticFactory(double a_coef, double b_coef, double c_coef)
        : a(a_coef), b(b_coef), c(c_coef) {}
    Function *create() const override {
        return new QuadraticFunction(a, b, c);
    }
};