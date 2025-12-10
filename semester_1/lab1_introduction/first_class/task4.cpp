// ычислить так называемый «двойной факториал»:
// k!! =
// {
// 1 ·3 ·5 ·. . . ·k, k — нечётное
// 2 ·4 ·6 ·. . . ·k, k — чётное
// Число k вводится с клавиатуры.

#include <iostream>

int main() {
    int k;
    long long result = 1;

    std::cout << "Write a num" << std::endl;
    std::cin >> k;

    for (int i = k; i > 0; i -= 2)
    {
        result *= i;
    }
    
    std::cout << k << "!! = " << result;

    return 0;
    
}