// Version 19

// В массиве, состоящем из n вещественных элементов, вычислить:
// 1. количество различных элементов;
// 2. сумму элементов массива, расположенных между первым и последним
// отрицательными элементами.
// Сжать массив, удалив из него все элементы, модуль которых не превышает X
// (вводится с клавиатуры). Оставшиеся в конце массива элементы заполнить
// нулями

#include <iostream>
#include <random>
#include <algorithm>
#include <cmath>

// Основные функции
void createArr(int &n, double *arr, int &mode);
void solveTasks(int n, double *arr, int &numOfDifferentElems, long double &sumBetweenNegatives);
void changeArr(int n, double *arr);

// Подфункции
void chooseMode(int &mode);
void checkoutArrLength(int &length);
void fillArr(int mode, int n, double *arr);
void keyboardEnter(int n, double *arr);
void randomEnter(int n, double *arr);
void limitsForRandom(double &a, double &b);
/*--------------------------------*/
void task1(int n, double *arr, int &numOfDifferentElems);
void task2(int n, double *arr, long double &sumBetweenNegatives);

// Вспомогательные функции
void checkInput(int &empty);
void checkInput(double &empty);
void showArr(int n, double *arr);
void swap(double &a, double &b);
double randomNumber(std::mt19937 &gen, double a, double b);

// solve task with usage of
// dymanic arrays
int main()
{
    int n,
        mode; // клавиатура или рандом

    checkoutArrLength(n);

    double *arr = new double[n];

    int numOfDifferentElems = 1;
    long double sumBetweenNegatives = 0;

    createArr(n, arr, mode);

    solveTasks(n, arr, numOfDifferentElems, sumBetweenNegatives);

    std::cout << "\n1.Number of different elements: "
              << numOfDifferentElems << "\n\n";
    std::cout << "\n2.Sum between negative-elements (if such exist): "
              << sumBetweenNegatives << "\n\n";

    changeArr(n, arr);

    delete[] arr;
    return 0;
}

// Проверка ввода
void checkInput(int &empty)
{
    if (!(std::cin >> empty))
    {
        std::cout << "Invalid input!" << std::endl;
        exit(1);
    }
}

void checkInput(double &empty)
{
    if (!(std::cin >> empty))
    {
        std::cout << "Invalid input!" << std::endl;
        exit(1);
    }
}

// Проверка и установка длины массива
void checkoutArrLength(int &length)
{
    std::cout << "Enter array length (1 <= n <= 1000)" << std::endl;
    checkInput(length);

    if (length > 1000 || length < 1)
    {
        std::cout << "Check limits!" << std::endl;
        exit(1);
    }
}

// Выбор режима заполнения массива
void chooseMode(int &mode)
{
    std::cout << "How would you fill array with reals?" << std::endl
              << "Keyboard (0) or random (1)?" << std::endl;

    checkInput(mode);
}

// Заполнение масива
void fillArr(int mode, int n, double *arr)
{
    switch (mode)
    {
    case 0:
        keyboardEnter(n, arr);
        break;
    case 1:
        randomEnter(n, arr);
        break;
    default:
        std::cout << "Something went wrong." << std::endl
                  << "Please, be careful while entering.";
        exit(1);
    }
}

// Ввод с клавиатуры
void keyboardEnter(int n, double *arr)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "Elem " << i + 1 << ": ";
        checkInput(arr[i]);
    }
}

// Рандомный ввод
void randomEnter(int n, double *arr)
{
    double a, b;
    limitsForRandom(a, b);

    std::mt19937 gen(45218965);

    for (int i = 0; i < n; i++)
    {
        arr[i] = randomNumber(gen, a, b);
    }
}

// Границы значений элементов
void limitsForRandom(double &a, double &b)
{
    std::cout << "Enter real limits of elements (a, b)" << std::endl
              << "Lower (recommend -10): ";
    checkInput(a);
    std::cout << "Upper (recommend 10): ";
    checkInput(b);

    if (a > b)
    {
        std::cout << "You mixed up values, but that's OK!" << std::endl;
        swap(a, b);
    }
}

// Рандомное число
double randomNumber(std::mt19937 &gen, double a, double b)
{
    std::uniform_real_distribution<double> dist(a, b);
    return dist(gen);
}

// Поменять местами два числа
void swap(double &a, double &b)
{
    double temp = a;
    a = b;
    b = temp;
}

// Показать массив поэлементно
void showArr(int n, double *arr)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "Elem " << i + 1 << ": " << arr[i] << std::endl;
    }
}

// Полная подготовка массива
void createArr(int &n, double *arr, int &mode)
{
    chooseMode(mode);
    fillArr(mode, n, arr);

    std::cout << "\nCreated array:\n";
    showArr(n, arr);
}

/*--------------------------------*/

// Решение подзадачи 1:
// Количество различных элементов
void task1(int n, double *arr, int &numOfDifferentElems)
{
    std::sort(arr, arr + n);

    double current = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != current)
        {
            current = arr[i];
            numOfDifferentElems += 1;
        }
    }
}

// Решение подзадачи 2:
// Сумма элементов массива, расположенных между первым и последним
// отрицательными элементами
void task2(int n, double *arr, long double &sumBetweenNegatives)
{
    int firstNegative = 0;
    long double partSum = 0;

    while (arr[firstNegative] >= 0 && firstNegative < n - 1)
    {
        firstNegative += 1;
    }

    for (int i = firstNegative + 1; i < n; i++)
    {
        if (arr[i] < 0)
        {
            sumBetweenNegatives += partSum;
            partSum = arr[i];
        }
        else
        {
            partSum += arr[i];
        }
    }
}

// Решение подзадач
void solveTasks(int n, double *arr, int &numOfDifferentElems, long double &sumBetweenNegatives)
{
    std::cout << std::endl
              << "--RESULTS--\n\n";
    task2(n, arr, sumBetweenNegatives);
    task1(n, arr, numOfDifferentElems);
}

// Преобразование массива
void changeArr(int n, double *arr)
{
    int lastPosition = 0;

    double lim;
    std::cout << "Enter positive X (abs min value for elems): \n";
    checkInput(lim);

    for (int i = 0; i < n; i++)
    {
        if (std::abs(arr[i]) > lim)
        {
            arr[lastPosition++] = arr[i];
        }
    }

    for (int i = lastPosition; i < n; i++)
    {
        arr[i] = 0;
    }

    std::cout << "Changed array:\n";
    showArr(n, arr);
}
