#pragma once

#include "functions.h"

#include <map>

class Rating {
public:
    void readDataFromFile(const std::string &fileName);
    void printIf(const std::string &str, std::function<bool(const StudentData &)> condition);
    void printInOrder();
    void printByDiaposons();
    void printBySubject();
    void printStudentsPerSubject();
    void printAveragePerSubject();

private:
    std::map<size_t, StudentData> students_; // ключ - номер зачётки
};