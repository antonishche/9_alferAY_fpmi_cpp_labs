#pragma once

#include "../Function/Function.h"

class QuadraticFunction : public Function {
  public:
    QuadraticFunction(double, double, double);

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