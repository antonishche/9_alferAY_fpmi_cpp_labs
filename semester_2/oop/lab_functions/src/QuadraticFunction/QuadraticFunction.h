#pragma once

#include "../Function/Function.h"

class QuadraticFunction : public Function {
  public:
    QuadraticFunction(double, double, double);

    QuadraticFunction(QuadraticFunction &&other) noexcept
        : Function(std::move(other)), a(other.a), b(other.b), c(other.c) {};

    QuadraticFunction &operator=(QuadraticFunction &&other) noexcept {
        if (this != &other) {
            Function::operator=(std::move(other));
            a = other.a;
            b = other.b;
            c = other.c;

            other.a = other.b = other.c = 0;
        }

        return *this;
    }

    double Evaluate(double) const;
    void Solve() const;
    void PrintEquation() const;

    void printFunctionToFile(ostream &) const;
    bool hasSolutions() const;

    double calcDiscr() const;

    double getA() const;

  private:
    double a;
    double b;
    double c;
};