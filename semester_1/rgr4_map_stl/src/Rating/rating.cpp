#include "rating.h"

#include <iomanip>
#include <set>

void Rating::readDataFromFile(const std::string &fileName) {
    std::ifstream inputFile(fileName);
    checkFile(inputFile, fileName);

    std::string str;
    while (getline(inputFile, str)) {
        try {
            StudentData newStudent = writeNewStudent(str);
            students_[newStudent.index_] = newStudent;
        } catch (const std::exception &e) {
            std::cerr << "Ошибка: " << e.what() << std::endl;
        } catch (...) {
            throw std::runtime_error("Ошибка: не удалось добавить студента по строке \"" + str + "\".");
        }
    }
}

void Rating::printIf(const std::string &str, std::function<bool(const StudentData &)> condition) {
    std::cout << "=========================\n"
              << str << "\n";

    bool hasStudents = false;

    for (const std::pair<const size_t, StudentData> &key_value : students_) {
        const StudentData &student = key_value.second;

        if (condition(student)) {
            hasStudents = true;

            std::cout << "-------------------------\n"
                      << student.index_ << ": " << student.name_
                      << "\nСредний балл: " << std::fixed
                      << std::setprecision(2) << student.average_mark_
                      << "\n-\n";
            for (const Mark &m : student.marks_) {
                std::cout << m.subject_ << ": " << m.mark_ << "\n";
            }
        }
    }

    if (!hasStudents) {
        std::cout << "Отсутствуют\n";
    }

    std::cout << "=========================\n";
}

void Rating::printInOrder() {
    std::vector<const StudentData *> vec;
    vec.reserve(students_.size());

    for (const std::pair<const size_t, StudentData> &key_value : students_) {
        vec.push_back(&key_value.second);
    }

    std::sort(vec.begin(), vec.end(), [](const StudentData *a, const StudentData *b) {
        return (a->name_ < b->name_) ||
               (a->name_ == b->name_ && a->average_mark_ > b->average_mark_);
    });

    std::cout << "=========================\n"
              << "Студенты порядку:" << "\n";

    printVec(vec);

    std::cout << "=========================\n";
}

void Rating::printByDiaposons() {
    double a, b;
    getAverageMarkDiaposons(a, b);
    std::string strA = std::to_string(a);
    std::string strB = std::to_string(b);

    std::vector<const StudentData *> vec;
    vec.reserve(students_.size());

    for (const std::pair<const size_t, StudentData> &key_value : students_) {
        double average = key_value.second.average_mark_;
        if (average >= a && average <= b) {
            vec.push_back(&key_value.second);
        }
    }

    std::sort(vec.begin(), vec.end(), [](const StudentData *a, const StudentData *b) {
        return a->average_mark_ > b->average_mark_;
    });

    std::cout << "=========================\n"
              << "Студенты со средним баллом от " << strA << " до " << strB << ":" << "\n";

    printVec(vec);

    std::cout << "=========================\n";
}

void Rating::printBySubject() {
    std::set<std::string> subjects;
    for (std::pair<const size_t, StudentData> &student : students_) {
        for (const Mark &markData : student.second.marks_) {
            subjects.insert(markData.subject_);
        }
    }

    std::cout << "Введите предмет для поиска: ";

    std::string subject;
    if (!(std::cin >> subject) || !subjects.count(subject)) {
        throw std::runtime_error("Не найден предмет для поиска.");
    }

    std::string str = "Студенты, сдававшие предмет \"" + subject + "\":";

    printIf(str, [&](const StudentData &student) {
        for (const Mark &markData : student.marks_) {
            if (markData.subject_ == subject) {
                return true;
            }
        }

        return false;
    });
}

void Rating::printStudentsPerSubject() {
    std::map<std::string, size_t> subjects;

    for (std::pair<const size_t, StudentData> &student : students_) {
        for (const Mark &markData : student.second.marks_) {
            subjects[markData.subject_]++;
        }
    }

    std::cout << "=========================\n";
    std::cout << "Сколько студентов сдавало каждый предмет:\n";

    if (subjects.empty()) {
        std::cout << "Нисколько\n";
    } else {
        for (std::pair<const std::string, size_t> &subjectData : subjects) {
            std::cout << subjectData.first << ": " << subjectData.second << "\n";
        }
    }

    std::cout << "=========================\n";
}

void Rating::printAveragePerSubject() {
    std::map<std::string, std::vector<double>> subjects;

    for (std::pair<const size_t, StudentData> &student : students_) {
        for (const Mark &markData : student.second.marks_) {
            subjects[markData.subject_].push_back(markData.mark_);
        }
    }

    std::vector<std::pair<std::string, double>> averageSubj;

    for (std::pair<const std::string, std::vector<double>> &subjectData : subjects) {
        double averrage = accumulateAverage(subjectData.second);
        averageSubj.push_back({subjectData.first, averrage});
    }

    std::sort(averageSubj.begin(), averageSubj.end(), [](const std::pair<std::string, double> &a, const std::pair<std::string, double> &b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }

        return a.second > b.second;
    });

    std::cout << "=========================\n";
    std::cout << "Средний балл по предметам:\n";

    if (subjects.empty()) {
        std::cout << "Нету предметов...\n";
    } else {
        for (const std::pair<std::string, double> &subjectData : averageSubj) {
            std::cout << subjectData.first << ": " << subjectData.second << "\n";
        }
    }

    std::cout << "=========================\n";
}
