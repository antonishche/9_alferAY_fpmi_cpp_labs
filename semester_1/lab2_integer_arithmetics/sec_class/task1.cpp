// С клавиатуры вводится натуральное число n. Удалить из десятичной
// записи этого числа все цифры, совпадающие с минимальной цифрой.

#include <iostream>

int main() {
    int num, min_digit = 9, rest;

    std::cout << "Enter natural number" << std::endl;
    if (!(std::cin >> num) || num <= 0)
    {
        std::cout << "Invalid input" << std::endl;
        exit(1);
    }

    // ищем минимальную цифру
    int copy = num; 
    while (copy != 0)
    {
        rest = copy % 10;
        min_digit = min_digit > rest ? rest : min_digit;
        copy /= 10;
    }
    
    // удаляем минимальные цифры
    int new_num_reverse = 0;
    while (num != 0) {
        rest = num % 10;
        if (rest != min_digit)
        {
            new_num_reverse = new_num_reverse * 10 + rest;
        }
        num /= 10;
    }

    // переворачиваем обратно
    int new_num = 0;
    while (new_num_reverse != 0) {
        new_num = new_num * 10 + new_num_reverse % 10;
        new_num_reverse /= 10;
    }

    std::cout << "You get " << new_num << std::endl;

    return 0;
    
}