#include "QuadraticFunction.h"

#include <cmath>

QuadraticFunction::QuadraticFunction(double k1, double k2, double k3)
    : Function(), a(k1), b(k2), c(k3) {
    if (a == 0) {
        throw std::runtime_error("\'a\' cant be 0 in quadratic functions.");
    }
};

double QuadraticFunction::Evaluate(double x) const {
    double result = a * x * x + b * x + c;
    return result;
}

double QuadraticFunction::calcDiscr() const {
    return b * b - 4 * a * c;
}

void QuadraticFunction::Solve() const {
    double discr = calcDiscr();
    if (discr < 0) {
        cout << "No solutions";
    } else if (discr == 0) {
        double x = -b / (2 * a);
        cout << "x = " << round(x * 100) / 100;
    } else {
        double x1 = (-b - sqrt(discr)) / (2 * a);
        double x2 = (-b + sqrt(discr)) / (2 * a);
        cout << "x1 = " << round(x1 * 100) / 100 << "\n";
        cout << "x2 = " << round(x2 * 100) / 100;
    }
    cout << endl;
}

void QuadraticFunction::PrintEquation() const {
    cout << a << "x^2";

    if (b > 0) {
        cout << "+" << b << "x";
    } else if (b < 0) {
        cout << b << "x";
    }

    if (c > 0) {
        cout << "+" << c;
    } else if (c < 0) {
        cout << c;
    }
}

void QuadraticFunction::printFunctionToFile(ostream &out) const {
    out << a << "x^2";

    if (b > 0) {
        out << "+" << b << "x";
    } else if (b < 0) {
        out << b << "x";
    }

    if (c > 0) {
        out << "+" << c;
    } else if (c < 0) {
        out << c;
    }

    out << "=0, ";

    double discr = calcDiscr();
    if (discr < 0) {
        out << "No solutions";
    } else if (discr == 0) {
        double x = -b / (2 * a);
        out << "x = " << round(x * 100) / 100;
    } else {
        double x1 = (-b - sqrt(discr)) / (2 * a);
        double x2 = (-b + sqrt(discr)) / (2 * a);
        out << "x1 = " << round(x1 * 100) / 100 << ", ";
        out << "x2 = " << round(x2 * 100) / 100;
    }
    out << endl;
}

bool QuadraticFunction::hasSolutions() const {
    if (calcDiscr() < 0) {
        return false;
    }
    return true;
}

double QuadraticFunction::getA() const {
    return a;
}