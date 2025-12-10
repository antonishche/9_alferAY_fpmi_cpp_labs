// С клавиатуры вводится четырёхзначное натуральное число. Выяснить,
// является ли оно палиндромом (т.е. читается одинаково как слева напра-
// во, так и справа налево).

#include <iostream>

int main() {
    int inp, num, pal_num = 0;

    std::cout << "Enter num, 1000 <= num <= 9999" << std::endl;
    if (!(std::cin >> inp) || inp < 1000 || inp > 9999)
    {
        std::cout << "Invalid input!";
        exit(1);
    } else
    {
        num = inp;
    }
    

    for (int i = 0; i < 4; i++)
    {
        pal_num = pal_num * 10 + num % 10;
        num = num / 10;
    }

    if (pal_num == inp)
    {
        std::cout << "Palindrom!!!";
    } else
    {
        std::cout << "Nope";
    }
    
    return 0;
    
}