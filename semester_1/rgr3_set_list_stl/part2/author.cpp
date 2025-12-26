#include "author.h"

Author::Author(const std::string &name, const std::string &surname, const std::string &fatherName) {
    name_ = name;
    surname_ = surname;
    father_name_ = fatherName;
}

std::string Author::getName() const {
    return name_;
}

std::string Author::getSurame() const {
    return surname_;
}

std::string Author::getFatherName() const {
    return father_name_;
}

void Author::setName(const std::string &name) {
    name_ = name;
}

void Author::setSurame(const std::string &surname) {
    surname_ = surname;
}

void Author::setFatherName(const std::string &fatherName) {
    father_name_ = fatherName;
}