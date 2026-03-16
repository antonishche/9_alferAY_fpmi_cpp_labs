#include "Function.h"

int Function::next_id = 1;

Function::Function() : id(next_id) {};

Function::~Function() {};

int Function::getId() const {
    return id;
}