// Ниже будет предоставлен код, который проверяет на неотрицательность
// введённое число двумя разными способами: через реализованную функцию
// IsNotNegative(int number) и через обычный оператор сравнения в C++.
// Далее сравнивается работа этих двух способов. Может ли что-то пойти не
// так?

#include <iostream>
void TryRead(int &number)
{
    if (!(std::cin >> number))
    {
        std::cout << "Fail on reading the number." << std::endl;
        exit(0);
    }
}
bool IsNotNegative(int number)
{
    return abs(number) == number;
}
int main()
{
    int number;
    std::cout << "Enter the number: ";
    TryRead(number);
    bool std_non_negative_check = (number >= 0);
    if (IsNotNegative(number) == std_non_negative_check)
    {
        std::cout << "Try again...." << std::endl;
    }
    else
    {
        std::cout << "Shit, you broke my program :(" << std::endl;
        exit(1);
    }
    return 0;
}

// входные: -2,147,483,648
// ошибка так как abs = 2,147,483,648 не помещается в int