// Вычислить сумму всех чётных чисел и произведение всех нечётных на
// отрезке [1, n]. Число n вводится с клавиатуры.

#include <iostream>

int main() {
    int n, sum = 0, mult = 1;

    std::cout << "Enter n: " << std::endl;
    std::cin >> n;

    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            sum += i;
        } else
        {
            mult *= i;
        }  
    }
    
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Mult: " << mult << std::endl;

    return 0;
}