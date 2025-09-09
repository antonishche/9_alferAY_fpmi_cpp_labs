// Даны два натуральных числа n и m(вводятся с клавиатуры). Вывести
// все их общие делители.

#include <iostream>

int main() {
    int m, n, little;

    std::cout << "Write 1st num" << std::endl;
    std::cin >> m;
    std::cout << "Write 2nd num" << std::endl;
    std::cin >> n;
    
    little = m > n ? n : m;

    std::cout << "Deliteli: ";

    for (int i = 1; i <= little; i++)
    {
        if (m % i == 0 && n % i == 0)
        {
            std::cout << i << " ";
        }
        
    }

    return 0;
    
}