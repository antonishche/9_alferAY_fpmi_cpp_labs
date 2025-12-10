// С клавиатуры вводится натуральное число n. Удалить из десятичной
// записи этого числа все цифры, совпадающие с минимальной цифрой.

#include "task1.h"
#include <iostream>
#include <climits>

int find_min_digit(int num) {
    int min_digit = 9;
    
    if (num == 0) return 0;
    
    while (num != 0) {
        int digit = num % 10;
        if (digit < min_digit) min_digit = digit;
        num /= 10;
    }
    return min_digit;
}

int remove_min_digits(int num) {
    if (num <= 0) return 0;
    
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