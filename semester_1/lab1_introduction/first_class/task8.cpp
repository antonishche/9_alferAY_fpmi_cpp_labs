// Дано 10 вещественных чисел (вводятся с клавиатуры). Определить,
// сколько из них меньше своих «соседей», т.е. предыдущего и последу-
// ющего чисел.

#include <iostream>

int main() {
    double nums[10];
    int n = 0;

    for (int i = 0; i < 10; i++)
    {
        std::cout << "Num " << i + 1 << ": ";
        std::cin >> nums[i];
        std::cout << std::endl;
    }

    for (int i = 1; i < 9; i++)
    { 
        if (nums[i] < nums[i - 1] && nums[i] < nums[i + 1])
        {
            n += 1;
        }
        
    }
    
    std::cout << "Takich chisel " << n;

    return 0;
    
}