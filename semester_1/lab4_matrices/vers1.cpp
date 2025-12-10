// В целочисленной квадратнойматрице:
// •найти максимальный элемент в тех столбцах, которые не содержат
// положительных элементов;
// •подсчитать количество отрицательных элементов в нижнем пра-
// вом треугольнике матрицы, включая диагональ.

#include <iostream>
#include <random>

// Основные функции
void createMatrix(int &n, int**& matrix, int &mode);
void solveTasks(int n, int** matrix);
void deleteMatrix(int n, int**& matrix);

// Подфункции
void chooseMode(int &mode);
void checkoutMatrixSizes(int &size);
void fillArr(int mode, int n, int**& matrix);
void keyboardEnter(int n, int**& matrix);
void randomEnter(int n, int**& matrix);
void limitsForRandom(int &a, int &b);
/*--------------------------------*/
void task1(int n, int** matrix);
void task2(int n, int** matrix);

// Вспомогательные функции
void checkInput(int &empty);
void showMatrix(int n, int** matrix);
void swap(int &a, int &b);
int randomNumber(std::mt19937 &gen, int a, int b);

int main()
{
    int n,
        mode;                       // вручную или рандом
    
    int** matrix;

    createMatrix(n, matrix, mode);
    solveTasks(n, matrix);
    deleteMatrix(n, matrix);

    return 0;
}

// Создание целочисленной матрицы
void createMatrix(int &n, int**& matrix, int &mode)
{
    checkoutMatrixSizes(n);

    matrix = new int* [n];
    for (size_t row = 0; row < n; row++)
    {
        matrix[row] = new int[n];
    }
    
    chooseMode(mode);
    fillArr(mode, n, matrix);
}

// Удаление матрицы
void deleteMatrix(int n, int**& matrix) {
    for (size_t row = 0; row < n; row++)
    {
        delete[] matrix[row];
    }
    delete[] matrix;
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
    std::cout << "Enter square martix size" << std::endl;
    checkInput(size);

    if (size < 1)
    {
        std::cout << "Must be at least 1.\n"
                  "Be careful next time" << std::endl;
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
void fillArr(int mode, int n, int**& matrix)
{
    switch (mode)
    {
    case 0:
        keyboardEnter(n, matrix);
        showMatrix(n, matrix);
        break;
    case 1:
        randomEnter(n, matrix);
        showMatrix(n, matrix);
        break;
    default:
        std::cout << "Something were wrong!\n"
                  << "Be careful while entering.";
        std::exit(1);
    }
}

// Ввод с клавиатуры
void keyboardEnter(int n, int**& matrix)
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
            checkInput(matrix[i][j]);
        }
    }
}

// Рандомный ввод
void randomEnter(int n, int**& matrix)
{
    int a, b;
    limitsForRandom(a, b);

    std::mt19937 gen(45218965);

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            matrix[i][j] = randomNumber(gen, a, b);
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
void showMatrix(int n, int** matrix)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Решение задач
void solveTasks(int n, int** matrix)
{
    task1(n, matrix);
    task2(n, matrix);
}

// Задача 1
// Найти максимальный элемент в тех столбцах, которые не содержат
// положительных элементов;
void task1(int n, int** matrix)
{
    int max = -101;
    for (size_t i = 0; i < n; i++)
    {
        int checkMax = -101;
        for (size_t j = 0; j < n; j++)
        {
            // Есть положительный элемент - новый столб
            if (matrix[j][i] > 0)
            {
                break;
            }

            // Проверяем элемент в столбце
            if (matrix[j][i] > checkMax)
            {
                checkMax = matrix[j][i];
            }
        }
        max = checkMax > max ? checkMax : max;
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
void task2(int n, int** matrix)
{
    int numOfNegative = 0;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j <= i; j++)
        {
            if (matrix[i][n-1-j] < 0)
            {
                numOfNegative += 1;
            }
        }
    }

    std::cout << "Num of negative: " << numOfNegative;
}