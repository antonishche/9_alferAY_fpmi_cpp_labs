#pragma once

#include "../Mark/mark.h"

#include <vector>

struct StudentData {
    std::string name_;        // фамилия, инициалы
    size_t index_;            // номер зачётки
    std::vector<Mark> marks_; // результаты сессии
    // TODO
    double average_mark_;

    StudentData(const std::string &name, size_t index, const std::vector<Mark> &marks);
    StudentData() = default;
};