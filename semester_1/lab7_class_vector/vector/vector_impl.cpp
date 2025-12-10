#include "vector_impl.h"

// your code goes here

#include <iostream>
#include <exception>
#include <stdexcept>

Vector::Vector() : data_(nullptr), size_(0), capacity_(0) {}

Vector::Vector(size_t size) 
    : data_(new int[size]), size_(size), capacity_(size) {
    for (size_t i = 0; i < size_; i++)
    {
        data_[i] = 0;
    }
}

Vector::Vector(std::initializer_list<int> list)
    : data_(new int[list.size()]),
      size_(list.size()),
      capacity_(list.size()) {
    size_t index = 0;
    for (int num : list)
    {
        data_[index++] = num;
    }
}

Vector::Vector(const Vector& other)
    : data_(new int[other.capacity_]),
      size_(other.size_),
      capacity_(other.capacity_) {
        for (size_t i = 0; i < size_; i++)
        {
            data_[i] = other.data_[i];
        }   
}

Vector& Vector::operator=(const Vector& other) {
    if (this != &other)
    {
        Vector temp(other);
        Swap(temp);
    }
    return *this;
}

Vector::~Vector() {
    delete[] data_;
}

void Vector::Swap(Vector& other) {
    int* temp_data = other.data_;
    other.data_ = data_;
    data_ = temp_data;

    size_t temp_size = other.size_;
    other.size_ = size_;
    size_ = temp_size;

    size_t temp_capacity = other.capacity_;
    other.capacity_ = capacity_;
    capacity_ = temp_capacity;
}

const int& Vector::operator[](size_t index) const {
    return data_[index];
}

int& Vector::operator[](size_t index) {
    return data_[index];
}

const int& Vector::At(size_t index) const {
    if (index >= size_)
    {
        throw std::out_of_range("Error: index is out of range.");
    }
    return data_[index];
}

int& Vector::At(size_t index) {
    if (index >= size_)
    {
        throw std::out_of_range("Error: index is out of range.");
    }
    return data_[index];
}

size_t Vector::Size() const {
    return size_;
}

size_t Vector::Capacity() const {
    return capacity_;
}

void Vector::PushBack(int elem) {
    if (size_ == capacity_)
    {
        capacity_ = capacity_ == 0 ? 1 : capacity_ * 2;
        int* new_data = new int[capacity_];
        for (size_t i = 0; i < size_; i++)
        {
            new_data[i] = data_[i];
        }

        delete[] data_;
        data_ = new_data;
    }

    data_[size_++] = elem; 
}

void Vector::PopBack() {
    if (size_ > 0)
    {
        size_--;
    }  
}

void Vector::Clear() {
    size_ = 0;
}

void Vector::Reserve(size_t new_capacity) {
    if (capacity_ < new_capacity)
    {
        capacity_ = new_capacity;
        int* new_data = new int[new_capacity];
        for (size_t i = 0; i < size_; i++)
        {
            new_data[i] = data_[i];
        }

        delete[] data_;
        data_ = new_data;
    }   
}

std::ostream& operator<<(std::ostream& os, const Vector& v) {
    os << "[";

    for (size_t i = 0; i < v.Size(); i++)
    {
        if (i == v.Size() - 1)
        {
            os << v[i];
        } else {
            os << v[i] << ", ";
        }
    }

    os << "]";
    return os;
}

// int main() {
//     Vector v1{1,2,3};
//     Vector v2{4,5,6};

//     Vector copy(v1);

//     copy = v2;

//     return 0;
// }