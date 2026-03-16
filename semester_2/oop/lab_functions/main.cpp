#include "src/Function/Function.h"
#include "src/LinearFunction/LinearFunction.h"
#include "src/QuadraticFunction/QuadraticFunction.h"

#include <fstream>
#include <sstream>
#include <vector>

void clearVec(vector<Function *> &functions) {
    for (auto &f : functions) {
        delete f;
    }
}

void addLinear(vector<Function *> &functions, double a, double b) {
    functions.push_back(new LinearFunction(a, b));
}

void addQuadratic(vector<Function *> &functions, double a, double b, double c) {
    try {
        functions.push_back(new QuadraticFunction(a, b, c));
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void fillVec(vector<Function *> &functions) {
    cout << "\n===filling functions...\n";
    addLinear(functions, 1, 2);
    addLinear(functions, 2, 3);
    addLinear(functions, 0, 9);
    addQuadratic(functions, 1, 2, 1);
    addQuadratic(functions, 3, -6, -5);
    addQuadratic(functions, 0, 0, 0);
    addQuadratic(functions, 5, 1, 1);
    cout << "===added in total: " << functions.size() << "\n";
}

void countFunctions(const vector<Function *> &functions) {
    int numLin = 0, numQuadr = 0;

    for (const auto &f : functions) {
        if (typeid(*f) == typeid(LinearFunction)) {
            numLin++;
        } else if (typeid(*f) == typeid(QuadraticFunction)) {
            numQuadr++;
        }
    }

    cout << "Linear: " << numLin << ", Quadratic: " << numQuadr << ".\n";
}

void printVec(const vector<Function *> &functions) {
    cout << "\n===All functions===\n";
    for (const auto &f : functions) {
        f->PrintEquation();
    }
}

void printToFile(const vector<Function *> &functions) {
    ofstream out("functions.txt");

    if (!out.is_open()) {
        throw std::runtime_error("could not open file \"functions.txt\"");
    }

    for (const Function *f : functions) {
        out << "f" << f->getId() << "(x)" << ": ";
        f->printFunctionToFile(out);
    }
}

void printIf(const string &str, const vector<Function *> &vec,
             function<bool(const Function *f)> cond) {
    cout << str << endl;

    int counter = 0;

    for (const Function *f : vec) {
        if (cond(f)) {
            counter++;
            cout << f->getId() << ": f" << "(x) = ";
            f->PrintEquation();
            cout << "\n";
        }
    }

    if (counter == 0) {
        cout << "No such functions\n";
    } else {
        cout << "in total: " << counter << '\n';
    }
}

void printNoSolutions(const vector<Function *> &functions) {
    printIf("Equations which have no solutions in f(x) = 0", functions,
            [](const Function *f) { return !f->hasSolutions(); });
}

bool checkInput(double &num) {
    if (!(cin >> num)) {
        cout << "Invalid input.\nTeleport back to menu\n";
        cin.clear();
        cin.ignore(1000, '\n');
        return false;
    }
    return true;
}

void printHasAPoint(const vector<Function *> &functions) {
    double x, y;

    cout << "x = ";
    checkInput(x);
    cout << "y = ";
    checkInput(y);

    stringstream ss;
    ss << "Functions, where f(" << x << ") = " << y;

    printIf(ss.str(), functions, [x, y](const Function *f) {
        return abs((f->Evaluate(x) - y)) < 0.01;
    });
}

void printLinearSorted(vector<Function *> &functions) {
    vector<Function *> vec;

    for (Function *f : functions) {
        LinearFunction *lin = dynamic_cast<LinearFunction *>(f);

        if (lin != nullptr) {
            if (lin->getB() > lin->getA()) {
                vec.push_back(f);
            }
        }
    }

    sort(vec.begin(), vec.end(), [](const Function *f1, const Function *f2) {
        const LinearFunction *lin1 = static_cast<const LinearFunction *>(f1);
        const LinearFunction *lin2 = static_cast<const LinearFunction *>(f2);

        return lin1->getB() > lin2->getB();
    });

    printIf("Linear functions, where b > a (sorted)", vec,
            [](const Function *f) { return true; });
}

void printQuadroQuadroSorted(vector<Function *> &functions) {
    vector<Function *> vec;

    for (Function *f : functions) {
        QuadraticFunction *quadr = dynamic_cast<QuadraticFunction *>(f);

        if (quadr != nullptr) {
            if (quadr->calcDiscr() == 0) {
                vec.push_back(f);
            }
        }
    }

    sort(vec.begin(), vec.end(), [](const Function *f1, const Function *f2) {
        const QuadraticFunction *q1 =
            dynamic_cast<const QuadraticFunction *>(f1);
        const QuadraticFunction *q2 =
            dynamic_cast<const QuadraticFunction *>(f2);

        return q1->getA() < q2->getA();
    });

    printIf("Quadratic functions with full square (sorted)", vec,
            [](const Function *f) { return true; });
}

void menu() {
    cout << "\n===MENU===\n"
         << "1. Count linear/quadratic functions\n"
         << "2. Find f(x) = 0 with no solutions\n"
         << "3. Find f(x) = y (user select)\n"
         << "4. Find linear functions (b > a)\n"
         << "5. Find quadratic functions (full square)\n"
         << "0. Exit\n"
         << "===Choen option: ";
}

int main() {

    try {

        vector<Function *> functions;
        fillVec(functions);
        printToFile(functions);

        int option;
        do {
            menu();
            if (!(cin >> option)) {
                cout << endl;
                cout << "Invalid input\n";
                cin.clear();
                cin.ignore(1000, '\n');
                option = -1;
                continue;
            }

            cout << endl;

            switch (option) {
            case 0:
                cout << "Good bye!\n";
                break;
            case 1:
                countFunctions(functions);
                break;
            case 2:
                printNoSolutions(functions);
                break;
            case 3:
                printHasAPoint(functions);
                break;
            case 4:
                printLinearSorted(functions);
                break;
            case 5:
                printQuadroQuadroSorted(functions);
                break;
            default:
                cout << "Incorrect option\n";
                break;
            }
        } while (option != 0);

        clearVec(functions);

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}