#include "functions.h"

#include <sstream>

bool fileOpened(std::ifstream &file) {
    return file.is_open();
}

bool fileEmpty(std::ifstream &file) {
    return file.peek() == std::fstream::traits_type::eof();
}

void checkFile(std::ifstream &file, const std::string &fileName) {
    if (!fileOpened(file)) {
        throw std::runtime_error("не удалось открыть файл \"" + fileName + "\".");
    } else if (fileEmpty(file)) {
        throw std::runtime_error("файл \"" + fileName + "\" пуст.");
    }
}

void checkPositive(long long num, const std::string &str) {
    if (num <= 0) {
        throw std::invalid_argument("найдено ненатуральное число на месте: \"" + str + "\".");
    }
}

void writeMark(const std::string &subject, long long mark, std::vector<Mark> &marks) {
    Mark newMark(subject, static_cast<size_t>(mark));
    marks.push_back(newMark);
}

StudentData writeNewStudent(const std::string &str) {
    std::string surname, initials, subject;
    long long index, mark;

    std::stringstream ss(str);
    try {
        ss >> surname >> initials >> index;
        checkPositive(index, "номер зачётки");

        std::vector<Mark> marks;
        while (ss >> subject >> mark) {
            checkPositive(mark, "оценка по предмету " + subject);
            writeMark(subject, mark, marks);
        }

        if (marks.empty()) {
            throw std::runtime_error("у студента \"" + surname + " " + initials + "\" нет оценок.");
        }

        StudentData newStudent(surname + " " + initials, index, marks);
        return newStudent;

    } catch (const std::exception &e) {
        throw std::runtime_error("строка \"" + str + "\" не распознана.\nПричина: " + e.what());
    } catch (...) {
        throw std::runtime_error("не удалось распознать студента по строке \"" + str + "\".");
    }
}

void checkAverage(double &num) {
    if (!(std::cin >> num) || num < 1 || num > 10) {
        throw std::runtime_error("Введено неверное значение для границы поиска по среднему баллу.");
    }

    num = std::round(num * 100) / 100;
}

void getAverageMarkDiaposons(double &a, double &b) {
    std::cout << "Введите нижнюю границу диапазона поиска по среднему баллу: ";
    checkAverage(a);

    std::cout << "Введите врхнюю границу диапазона поиска по среднему баллу: ";
    checkAverage(b);

    if (a > b) {
        std::swap(a, b);
    }
}

void printVec(const std::vector<const StudentData *> &vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        const StudentData &student = *vec[i];
        std::cout << i + 1 << ". " << student.name_ << ", " << student.index_ << ", " << student.average_mark_ << '\n';
    }

    if (vec.empty()) {
        std::cout << "Отсутствуют\n";
    }
}

double accumulateAverage(const std::vector<double> &marks) {
    if (marks.empty()) {
        return 0.0;
    }

    double sum = 0.0;
    for (double mark : marks) {
        sum += mark;
    }

    double average = sum / marks.size();
    return std::round(average * 100) / 100;
}