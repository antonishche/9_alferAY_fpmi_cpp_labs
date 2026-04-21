#pragma once

#include "../Function/Function.h"

class LinearFunction : public Function {
  public:
    LinearFunction(double, double);

    LinearFunction(LinearFunction &&other) noexcept
        : Function(std::move(other)), a(other.a), b(other.b) {}

    LinearFunction &operator=(LinearFunction &&other) noexcept {
        if (this != &other) {
            Function::operator=(std::move(other));
            a = other.a;
            b = other.b;

            other.a = other.b = 0;
        }

        return *this;
    }

    double Evaluate(double) const;
    void Solve() const;
    void PrintEquation() const;

    void printFunctionToFile(ostream &) const;
    bool hasSolutions() const;

    double getA() const;
    double getB() const;

  private:
    double a;
    double b;
};