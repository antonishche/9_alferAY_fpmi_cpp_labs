#include "LinearFunction.h"

LinearFunction::LinearFunction(double k1, double k2)
    : Function(), a(k1), b(k2) {};

double LinearFunction::Evaluate(double x) const {
    double result = a * x + b;
    return result;
}

void LinearFunction::Solve() const {
    if (a == 0 && b != 0) {
        cout << "No solutions";
    } else if (a == 0 && b == 0) {
        cout << "x belongs to R";
    } else {
        cout << "x = " << -b / a;
    }
    cout << endl;
}
void LinearFunction::PrintEquation() const {
    if (a == 0) {
        cout << b;
    }

    if (a != 0) {
        cout << a << "x";

        if (b < 0) {
            cout << b;
        } else if (b > 0) {
            cout << "+" << b;
        }
    }
}

void LinearFunction::printFunctionToFile(ostream &out) const {
    out << a << "x";
    if (b < 0) {
        out << b;
    } else {
        out << "+" << b;
    }
    out << "=0, ";

    if (a == 0 && b != 0) {
        out << "No solutions";
    } else if (a == 0 && b == 0) {
        out << "x belongs to R";
    } else {
        out << "x = " << -b / a;
    }
    out << endl;
}

bool LinearFunction::hasSolutions() const {
    if (a == 0 && b != 0) {
        return false;
    }
    return true;
}

double LinearFunction::getA() const {
    return a;
}

double LinearFunction::getB() const {
    return b;
}
