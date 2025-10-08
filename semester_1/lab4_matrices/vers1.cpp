// В целочисленной квадратнойматрице:
// •найти максимальный элемент в тех столбцах, которые не содержат
// положительных элементов;
// •подсчитать количество отрицательных элементов в нижнем пра-
// вом треугольнике матрицы, включая диагональ.

#include <iostream>
#include <random>

const int maxSize = 32;

// Основные функции
void createMatrix(int &n, int arr[][maxSize], int &mode);
void solveTasks(int n, int arr[][maxSize]);

// Подфункции
void chooseMode(int &mode);
void checkoutMatrixSizes(int &size);
void fillArr(int mode, int n, int arr[][maxSize]);
void keyboardEnter(int n, int arr[][maxSize]);
void randomEnter(int n, int arr[][maxSize]);
void limitsForRandom(int &a, int &b);
/*--------------------------------*/
void task1(int n, int arr[][maxSize]);
void task2(int n, int arr[][maxSize]);

// Вспомогательные функции
void checkInput(int &empty);
void showMatrix(int n, int arr[][maxSize]);
void swap(int &a, int &b);
int randomNumber(std::mt19937 &gen, int a, int b);

int main()
{
    int n,
        mode;                       // вручную или рандом
    int arr[maxSize][maxSize] = {}; // использовал статику

    createMatrix(n, arr, mode);
    solveTasks(n, arr);
    return 0;
}

// Создание целочисленной матрицы
void createMatrix(int &n, int arr[][maxSize], int &mode)
{
    checkoutMatrixSizes(n);
    chooseMode(mode);
    fillArr(mode, n, arr);
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

// Проверка и установка длины массива
void checkoutMatrixSizes(int &size)
{
    std::cout << "Enter square martix size (1 <= n <= " << maxSize << ")" << std::endl;
    checkInput(size);

    if (size > maxSize || size < 1)
    {
        std::cout << "Check limits!" << std::endl;
        exit(1);
    }
}

// Выбор режима
void chooseMode(int &mode)
{
    std::cout << "How would you fill matrix?\n"
              << "Keyboard (0) or random (1): ";
    checkInput(mode);
}

// Заполнение массива
void fillArr(int mode, int n, int arr[][maxSize])
{
    switch (mode)
    {
    case 0:
        keyboardEnter(n, arr);
        showMatrix(n, arr);
        break;
    case 1:
        randomEnter(n, arr);
        showMatrix(n, arr);
        break;
    default:
        std::cout << "Something were wr...";
        std::exit(1);
    }
}

// Ввод с клавиатуры
void keyboardEnter(int n, int arr[][maxSize])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == 0)
            {
                std::cout << "Str " << i + 1 << "\n";
            }

            std::cout << "Elem " << j + 1 << ": ";
            checkInput(arr[i][j]);
        }
    }
}

// Рандомный ввод
void randomEnter(int n, int arr[][maxSize])
{
    int a, b;
    limitsForRandom(a, b);

    std::mt19937 gen(45218965);

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            arr[i][j] = randomNumber(gen, a, b);
        }
    }
}

// Установка границ
void limitsForRandom(int &a, int &b)
{
    std::cout << "Enter limits for random\n"
              << "Lower (a >= -100): ";
    checkInput(a);
    std::cout << "Upper (b <= 100): ";
    checkInput(b);

    if (a < -100 || a > 100 || b < -100 || b > 100)
    {
        std::cout << "Check limits!\n";
        std::exit(1);
    }

    if (a > b)
    {
        std::cout << "You mixed up values, but that's OK!\n";
        swap(a, b);
    }
}

// Рандомное число
int randomNumber(std::mt19937 &gen, int a, int b)
{
    std::uniform_int_distribution<int> dist(a, b);
    return dist(gen);
}

// Поменять местами
void swap(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

// Показать марицу
void showMatrix(int n, int arr[][maxSize])
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Решение задач
void solveTasks(int n, int arr[][maxSize])
{
    task1(n, arr);
    task2(n, arr);
}

// Задача 1
// Найти максимальный элемент в тех столбцах, которые не содержат
// положительных элементов;
void task1(int n, int arr[][maxSize])
{
    int max = -101;
    for (size_t i = 0; i < n; i++)
    {
        int checkMax = -101;
        for (size_t j = 0; j < n; j++)
        {
            // Есть положительный элемент - новый столб
            if (arr[j][i] > 0)
            {
                continue;
            }

            // Проверяем элемент в столбце
            if (arr[j][i] > checkMax)
            {
                checkMax = arr[j][i];
            }
        }
        max = checkMax;
    }

    std::cout << "1.Max elem: ";
    if (max == -101)
    {
        std::cout << "none\n";
    }
    else
    {
        std::cout << max << "\n";
    }
}

// Задача 2
// Подсчитать количество отрицательных элементов в нижнем пра-
// вом треугольнике матрицы, включая диагональ.
void task2(int n, int arr[][maxSize])
{
    int numOfNegative = 0;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j <= i; j++)
        {
            if (arr[i][j] < 0)
            {
                numOfNegative += 1;
            }
        }
    }

    std::cout << "Num of negative: " << numOfNegative;
}