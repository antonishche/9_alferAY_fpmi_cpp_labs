#pragma once

#include <initializer_list>
#include <ostream>

class Vector {
    // your code goes here
private:
    int* data_;
    size_t size_;
    size_t capacity_;

public:
    Vector();
    Vector(size_t size);
    Vector (std::initializer_list<int> list);
    Vector (const Vector& other);
    Vector& operator=(const Vector& other);

    ~Vector();

    void Swap(Vector& other);

    const int& operator[] (size_t index) const;
    int& operator[] (size_t index);

    const int& At(size_t index) const;
    int& At(size_t index);

    size_t Size() const;
    size_t Capacity() const;

    void PushBack(int value);
    void PopBack();
    void Clear();

    void Reserve(size_t new_capacity);
};

std::ostream& operator<<(std::ostream& os, const Vector& v);