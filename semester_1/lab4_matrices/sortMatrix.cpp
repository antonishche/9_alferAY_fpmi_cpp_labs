// Доп задание:
// Создание и удаление квадратной матрицы
// Выбор: вручную и рандом
// Сортировка строк
// Выбор: по возрастанию или по убыванию
// Выбор типа

#include <iostream>
#include <random>

// Основные функции
void createMatrix(int &n, int**& matrix, int &mode);
void sortMatrix(int n, int**& matrix);
void choseSort(int typeOfSort, int howToSort, int n, int**& matrix);
void deleteMatrix(int n, int**& matrix);

// Подфункции
void chooseMode(int &mode);
void checkoutMatrixSizes(int &size);
void fillArr(int mode, int n, int**& matrix);
void keyboardEnter(int n, int**& matrix);
void randomEnter(int n, int**& matrix);
void limitsForRandom(int &a, int &b);

// Вспомогательные функции
void checkInput(int &empty);
void showMatrix(int n, int** matrix);
void swap(int &a, int &b);
int randomNumber(std::mt19937 &gen, int a, int b);
bool compare(int a, int b, int howToSort);

// Сортировки
void bubbleSort(int howToSort, int n, int**& matrix);

int main()
{
    int n,
        mode; // вручную или рандом
    
    int** matrix;

    createMatrix(n, matrix, mode);
    sortMatrix(n, matrix);
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
void checkInput(int &num)
{
    if (!(std::cin >> num))
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

// Отсортировать матрицу
void sortMatrix(int n, int**& matrix)
{
    int howToSort;
    std::cout << "Sort by\n ascending (0) or descending (1): ";
    checkInput(howToSort);
    if (howToSort != 0 && howToSort != 1)
    {
        std::cout << "Invalid value!\nBe careful while entering.";
        std::exit(0);
    }
    
    int typeOfSort;
    std::cout << "Sort type:\n"
              << "bubble (0), counting (1), ..."
              << std::endl;
    checkInput(typeOfSort);
    
    choseSort(typeOfSort, howToSort, n, matrix);
}

// Сравнить элементы
bool compare(int a, int b, int howToSort) {
    if (howToSort = 0)
    {
        return a > b;
    } else if (howToSort = 1)
    {
        return a < b;
    }
    
    
    return howToSort  ? a > b : a < b;
}

void choseSort(int typeOfSort, int howToSort, int n, int**& matrix) {
    switch (typeOfSort)
    {
    case 0:
        bubbleSort(howToSort, n, matrix);
        showMatrix(n, matrix);
        break;
    
    case 1:
        countingSort(howToSort, n, matrix);
        showMatrix(n, matrix);
        break;

    default:
        break;
    }
} 

// Сортировка пузырьком
void bubbleSort(int howToSort, int n, int**& matrix) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            if (
                compare(matrix[i][j], matrix[i][j + 1], howToSort)
            )
            {
                int currId = j;
                while (
                    currId >= 0 &&
                    compare(matrix[i][currId], matrix[i][currId+1], howToSort)
                )
                {
                    swap(matrix[i][currId], matrix[i][currId+1]);
                    currId -= 1;
                }
                
            }
            
        }
           
    }
    
}

// Сортировка подсчётом
void countingSort(int howToSort, int n, int**& matrix) {
    std::cout << "Out of service (temporarily).\nWe apologize.";
    std::exit(0);
}

