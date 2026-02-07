#pragma once

#include <iostream>
#include <string>

struct Mark {
    std::string subject_; // предмет
    size_t mark_;         // оценка
    // TODO

    Mark(std::string subject = "", size_t mark = 0);
};