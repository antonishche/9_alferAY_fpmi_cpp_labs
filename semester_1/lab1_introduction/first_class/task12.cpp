// Напечатать месяц из календаря. На вход подается номер дня недели
// первого числа месяца n (целое число от 1 до 7) и k — количество дней
// в этом месяце(целое число от 1 до 99), n ≤k. Обратите внимание, что
// число дней в месяце не обязательно должно быть таким же, как в
// привычном календаре.

#include <iostream>
#include <locale>

int main() {
    setlocale(LC_ALL, "Russian");

    int day_num, month_size, counter = 0;

    std::cout << "Введите день (1-7)" << std::endl;
    if (!(std::cin >> day_num) || day_num < 1 || day_num > 7)
    {
        std::cout << "Неверный день" << std::endl;
        exit(1);
    }

    std::cout << "Введите размер месяца (" << day_num << "-99)" << std::endl;
    if (!(std::cin >> month_size) || month_size < day_num || month_size > 99)
    {
        std::cout << "Неверный размер месяца" << std::endl;
        exit(1);
    }

    std::cout << "пн вт ср чт пт сб вс" << std::endl;

    for (int i = 1; i < day_num; i++)
    {
        std::cout << "  " << " ";
        counter += 1;
    }

    for (int i = 1; i <= month_size; i++)
    {
        if (counter == 7)
        {
            std::cout << std::endl;
            counter ^= counter;
        }
        
        if (i < 10)
        {
            std::cout << " " << i << " ";
        } else {
            std::cout << i << " ";
        }

        counter += 1;
        
    }
    
    return 0;
}