// Вычислить первые n чисел Фибоначчи. Число n вводится с клавиатуры.
// Числа Фибоначчи вычисляются по формуле: Fn= Fn−1 + Fn−2, где
// F0 = 0, F1 = 1.

#include <iostream>

int main() {
    int n;

    std::cout << "Enter positive number" << std::endl;
    if (!(std::cin >> n) || n < 0)
    {
        std::cout << "Invalid input" << std::endl;
        exit(1);
    }

    if (n >= 0)
    {
        std::cout << "F0 = 0," << std::endl;
    }

    if (n >= 1)
    {
        std::cout << "F1 = 1," << std::endl;
    }

    long long prev = 0, curr = 1, next;

    for (int i = 2; i <= n; i++)
    {
        next = prev + curr;
        std::cout << "F" << i << " = " << next << "," << std::endl;
        prev = curr;
        curr = next;
    }
    
    return 0;
}