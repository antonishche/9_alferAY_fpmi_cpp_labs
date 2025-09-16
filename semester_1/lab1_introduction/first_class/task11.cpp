// С клавиатуры вводится натуральное десятичное число. Написать про-
// грамму, которая конвертирует данное число в двоичную и шестнадца-
// теричную системы счисления.

#include <iostream>
#include <string>

char useRest(int rest);

int main()
{
    int num;
    std::string s2, s16;

    std::cout << "Enter natural number" << std::endl;
    if (!(std::cin >> num) || num <= 0)
    {
        std::cout << "Invalid input!" << std::endl;
        exit(1);
    }
    
    int _copy2 = num;
    int _copy16 = num;

    while (_copy2 != 0)
    {
        s2 = useRest(_copy2 % 2) + s2;
        _copy2 /= 2;
    }

    while (_copy16 != 0)
    {
        s16 = useRest(_copy16 % 16) + s16;
        _copy16 /= 16;
    }

    std::cout << "In binary: " << s2 << std::endl;
    std::cout << "In 16-nary: " << s16 << std::endl;

    return 0;
}

char useRest(int rest)
{
    switch (rest)
    {
    case 0:
        return '0';
    case 1:
        return '1';
    case 2:
        return '2';
    case 3:
        return '3';
    case 4:
        return '4';
    case 5:
        return '5';
    case 6:
        return '6';
    case 7:
        return '7';
    case 8:
        return '8';
    case 9:
        return '9';
    case 10:
        return 'A';
    case 11:
        return 'B';
    case 12:
        return 'C';
    case 13:
        return 'D';
    case 14:
        return 'E';
    case 15:
        return 'F';
    }
}