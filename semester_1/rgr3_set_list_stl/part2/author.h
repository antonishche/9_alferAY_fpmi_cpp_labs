#pragma once

#include <iostream>
#include <list>
#include <string>

class Author {
public:
    Author(const std::string &name = "",
           const std::string &surname = "",
           const std::string &fatherName = "");

    std::string getName() const;
    std::string getSurame() const;
    std::string getFatherName() const;

    void setName(const std::string &name);
    void setSurame(const std::string &surname);
    void setFatherName(const std::string &fatherName);

    bool operator==(const Author &other) const;

private:
    std::string name_;
    std::string surname_;
    std::string father_name_;
};