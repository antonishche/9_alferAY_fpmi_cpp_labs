#include "Function.h"

int Function::next_id = 1;

Function::Function() : id(next_id) {};

int Function::getId() const {
    return id;
}