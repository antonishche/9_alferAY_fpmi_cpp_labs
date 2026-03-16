#pragma once

#include "../Function/Function.h"

class LinearFunction : public Function {
  public:
    LinearFunction(double, double);

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