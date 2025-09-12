// Написать программу, которая определяет, является ли шестизначное
// число «счастливым» (т.е. сумма первых трёх цифр равняется сумме
// последних трёх цифр).

#include <iostream>

int main() {
    int _6_digit, sum1 = 0, sum2 = 0;

    std::cout << "Enter 6-digit number" << std::endl;
    if (!(std::cin >> _6_digit) || _6_digit < 100000 || _6_digit > 999999)
    {
        std::cout << "Invalid input!";
        exit(1);
    }

    for (int i = 0; i < 6; i++)
    {
        if (i < 3)
        {
            sum2 += _6_digit % 10;
            _6_digit /= 10;
        } else
        {
            sum1 += _6_digit % 10;
            _6_digit /= 10;
        }

    }

    if (sum1 == sum2)
    {
        std::cout << "Happy!";
    } else
    {
        std::cout << "Nope";
    }
    
    return 0;
}