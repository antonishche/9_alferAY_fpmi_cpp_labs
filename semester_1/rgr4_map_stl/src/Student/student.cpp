#include "student.h"

StudentData::StudentData(const std::string &name, size_t index, const std::vector<Mark> &marks)
    : name_(name),
      index_(index),
      marks_(marks) {

    double sum = 0;
    for (const Mark &m : marks) {
        sum += m.mark_;
    }

    average_mark_ = sum / marks.size();
}