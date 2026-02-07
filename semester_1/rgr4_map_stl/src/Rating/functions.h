#pragma once

#include "../Student/student.h"

#include <fstream>

void checkFile(std::ifstream &file, const std::string &fileName);
StudentData writeNewStudent(const std::string &str);
void getAverageMarkDiaposons(double &a, double &b);
void printVec(const std::vector<const StudentData *> &vec);
double accumulateAverage(const std::vector<double> &marks);