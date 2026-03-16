#pragma once

#include <exception>
#include <iostream>
#include <stdexcept>
using namespace std;

class Function {
  public:
    Function();
    virtual ~Function();

    virtual double Evaluate(double) const = 0;
    virtual void Solve() const = 0;
    virtual void PrintEquation() const = 0;

    virtual void printFunctionToFile(ostream &) const = 0;
    virtual bool hasSolutions() const = 0;

    int getId() const;

  private:
    int id;

  protected:
    static int next_id;
};