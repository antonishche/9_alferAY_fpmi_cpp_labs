// Дана арифметическая прогрессия: ak = ak−1 + d. Вывести все члены
// этой прогрессии, кратные 3, которые лежат на отрезке [a, b]. Числа a, b
// и d вводятся с клавиатуры(a0 = a).

#include <iostream>

int main() {
    int a, b, d;

    std::cout << "Enter first num: " << std::endl;
    std::cin >> a;

    std::cout << "Enter second num: " << std::endl;
    std::cin >> b;

    std::cout << "Enter a step: " << std::endl;
    std::cin >> d;

    if (d > 0)
    {
        for (int i = a; i <= b; i += d)
        {
            if (i % 3 == 0)
            {
                std::cout << i << " ";
            }

        }
        
    } else if (d < 0)
    {
        for (int i = a; i >= b; i += d)
        {
            if (i % 3 == 0)
            {
                std::cout << i << " ";
            }

        }
    } else
    {
        if (a % 3 == 0)
        {
            std::cout << a << " ";
        }
        
    }

    return 0;
}