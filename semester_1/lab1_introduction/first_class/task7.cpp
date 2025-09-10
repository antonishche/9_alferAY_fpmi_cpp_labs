// Написать программу, которая вычисляет среднее арифметическое по-
// следовательности дробных чисел, вводимых с клавиатуры. После ввода
// пользователем последнего числа программа выводит среднее арифме-
// тическое, минимальное и максимальное числа в последовательности.
// количество чисел в последовательности вводится с клавиатуры.

#include <iostream>
#include <cmath>

int main() {
    int n;
    float sum = 0, min = INFINITY, max = -INFINITY;

    std::cout << "Enter number" << std::endl;
    std::cin >> n;

    if (n <= 0)
    {
        std::cout << "Number is invalid!" << std::endl;
    }
    

    for (int i = 0; i < n; i++)
    {
        float num;
        std::cout << "Enter number" << i + 1 << std::endl;
        std::cin >> num;

        sum += num;
        min = min < num ? min : num;
        max = max > num ? max : num;
    }

    std::cout << "Middle: " << sum / n << ", max: " << max << ", min: " << min;

    return 0;
    
}