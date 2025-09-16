// Вычислите сумму цифр целого неотрицательного числа. Число вводит-
// ся с клавиатуры.
// Лабораторная работа No1 3 Знакомство с C++

#include <iostream>

int main() {
    int num, sum = 0;

    std::cout << "Enter positive integer" << std::endl;
    if (!(std::cin >> num) || num < 0)
    {
        std::cout << "Invalid input" << std::endl;
        exit(1);
    }

    while (num != 0)
    {
        sum += num % 10;
        num /= 10;
    }
    
    std::cout << "Sum = " << sum;

    return 0;
}