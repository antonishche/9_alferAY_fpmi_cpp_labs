#include <algorithm>
#include <exception>
#include <iostream>
#include <numeric>
#include <set>
#include <stdexcept>
#include <vector>

void separate() {
    std::cout << "*\n";
}

void print(const std::vector<int>& vec) {
    std::cout << "[";
    for (int num : vec) {
        std::cout << num << ", ";
    }
    std::cout << "\b\b";
    std::cout << "]\n";
}

void fillVec(std::vector<int>& vec) {
    std::cout << "Введите числа через пробел, закончите символом 'q':\n";

    int num;
    while (std::cin >> num) {
        vec.push_back(num);
    }

    if (vec.size() == 0) {
        throw std::runtime_error("не удалось добавить элементы.");
    }

    std::cin.clear();
    std::cin.ignore(1000, '\n');
}

int elemsSum(const std::vector<int>& vec) {
    int sum = std::accumulate(vec.begin(), vec.end(), 0);

    std::cout << "Сумма элементов:"
              << sum
              << std::endl;

    return sum;
}

size_t allElemsNum(const std::vector<int>& vec) {
    size_t size = vec.size();

    std::cout << "Общее количество элементов: "
              << size
              << std::endl;

    return size;
}

int countEqual(const std::vector<int>& vec) {
    std::cout << "Введите число, количество элементов, равных которому, нужно найти:";

    int target;
    if (!(std::cin >> target)) {
        throw std::runtime_error("неверно введено число.");
    }

    int count = 0;
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] == target) {
            ++count;
        }
    }

    std::cout << "Количество чисел, равных заданному: "
              << count
              << std::endl;

    return count;
}

int coutWithCondition(const std::vector<int>& vec) {
    std::cout << "Введите число, количество чисел, больших которого, нужно найти:";

    int n;
    if (!(std::cin >> n)) {
        throw std::runtime_error("неверно введено n.");
    }

    int count = 0;
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] > n) {
            ++count;
        }
    }

    std::cout << "Количество чисел, больших, чем " << n << ": "
              << count
              << std::endl;

    return count;
}

void changeZeros(std::vector<int>& vec, int sum, size_t size) {
    int average = sum / size;

    bool hasZeros = false;
    for (size_t i = 0; i < size; i++) {
        if (vec[i] == 0) {
            hasZeros = true;
            break;
        }
    }

    if (hasZeros) {
        for (size_t i = 0; i < size; i++) {
            if (vec[i] == 0) {
                vec[i] = average;
            }
        }

        std::cout << "Вектор после замены нулей: ";
        print(vec);
    } else {
        std::cout << "Нулей нет. Изменений нет.\n";
    }
}

void checkoutBorder(int& num, size_t size) {
    if (!(std::cin >> num) || num < 0) {
        throw std::runtime_error("введено недопустимое значение");
    } else if (num >= size) {
        throw std::runtime_error("граница превышает количество элементов");
    }
}

int addSum(std::vector<int>& vec, size_t size) {
    int a, b;  // [a, b]

    std::cout << "Введите нижнюю границу интервала:";
    checkoutBorder(a, size);

    std::cout << "Введите верхнюю границу интервала:";
    checkoutBorder(b, size);

    if (a > b) {
        throw std::runtime_error("нижняя граница больше верхней");
    }

    int sumToAdd = 0;
    for (size_t i = a; i < b; i++) {
        sumToAdd += vec[i];
    }

    for (size_t i = 0; i < size; i++) {
        vec[i] += sumToAdd;
    }

    std::cout << "После увеличения каждого элемента на " << sumToAdd << " получилось: ";
    print(vec);

    return sumToAdd;
}

int changeEvenNums(std::vector<int>& vec) {
    bool hasEven = false;
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] % 2 == 0) {
            hasEven = true;
            break;
        }
    }

    if (hasEven) {
        int min = vec.front();
        int max = vec.front();

        for (size_t i = 0; i < vec.size(); i++) {
            int target = vec[i];
            min = min < target ? min : target;
            max = max > target ? max : target;
        }

        int diff = max - min;

        int count = 0;
        for (size_t i = 0; i < vec.size(); i++) {
            if (vec[i] % 2 == 0) {
                vec[i] = diff;
                ++count;
            }
        }

        std::cout << "После замены чисел, модуль которых есть четное число, на разность максимального и минимального: ";
        print(vec);

        return count;
    } else {
        std::cout << "Чётных нет. Изменений нет.\n";
        return 0;
    }
}

int deleteSameAbs(std::vector<int>& vec) {
    std::set<int> seen;

    int count = 0;

    vec.erase(std::remove_if(vec.begin(), vec.end(), [&](int x) {
                  int val = std::abs(x);
                  if (seen.count(val)) {
                      ++count;
                      return true;
                  }
                  seen.insert(val);
                  return false;
              }),
              vec.end());

    std::cout << "После удаления одинаковых по модулю: ";
    print(vec);

    return count;
}

int main() {
    // your code goes here

    setlocale(LC_ALL, "Russian");

    std::vector<int> vec;

    try {
        fillVec(vec);
        std::cout << "Получившийся вектор: ";
        print(vec);
        separate();

        int sum = elemsSum(vec);
        separate();

        size_t size = allElemsNum(vec);
        separate();

        countEqual(vec);
        separate();

        coutWithCondition(vec);
        separate();

        changeZeros(vec, sum, size);
        separate();

        addSum(vec, size);
        separate();

        changeEvenNums(vec);
        separate();

        deleteSameAbs(vec);

    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << '\n';
    }

    return 0;
}