// С клавиатуры вводится натуральное число n. Удалить из десятичной
// записи этого числа все цифры, совпадающие с минимальной цифрой.

#include "task1.h"
// #include <iostream>
#include <cmath>
#include <exception>
#include <stdexcept>

int find_min_digit(int temp) {
    if (temp == 0) return 0;

    int min_digit = 9;
    while (temp != 0) {
        int digit = temp % 10;
        if (digit < min_digit) min_digit = digit;
        temp /= 10;
    }
    return min_digit;
}

int remove_min_digits(int num) {
    if (num <= 0) {
        throw std::invalid_argument("Input must be natural number (>0)");
    }

    int min_digit = find_min_digit(num);
    int result = 0;
    int multiplier = 1;

    while (num != 0) {
        int digit = num % 10;
        if (digit != min_digit) {
            result += digit * multiplier;
            multiplier *= 10;
        }
        num /= 10;
    }

    return result;
}