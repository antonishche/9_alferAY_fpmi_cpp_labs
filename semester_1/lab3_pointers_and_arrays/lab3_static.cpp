// Version 1

// В массиве, состоящем из n целых элементов, вычислить:
// 1. произведение элементов массива с четными номерами;
// 2. сумму элементов массива, расположенных между первым и последним
// нулевыми элементами.
// Преобразовать массив таким образом, чтобы сначала располагались все от-
// рицательные элементы, а потом — все остальные. Порядок следования эле-
// ментов не изменять.

#include <iostream>
#include <random>

// Основные функции
void createArr(int &n, int *arr, int &mode, int maxLength);
void solveTasks(int n, int *arr);
void changeArr(int n, int *arr);

// Подфункции
void chooseMode(int &mode);
void checkoutArrLength(int &length, int maxLength);
void fillArr(int mode, int n, int *arr);
void keyboardEnter(int n, int arr[]);
void randomEnter(int n, int *arr);
void limitsForRandom(int &a, int &b);
//
void task1(int n, int *arr);
void task2(int n, int *arr);

// Вспомогательные функции
void checkInput(int &empty);
void showArr(int n, int arr[]);
void swap(int &a, int &b);
int randomNumber(std::mt19937 &gen, int a, int b);
//
void moveElem(int copyId, int *arr, int lastNegative);

// solve task with usage of
// static arrays
int main()
{
    const int maxLength = 1000;
    int arr[maxLength], n,
        mode; // клавиатура или рандом

    createArr(n, arr, mode, maxLength);

    solveTasks(n, arr);

    changeArr(n, arr);

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

// Проверка и установка длины массива
void checkoutArrLength(int &length, int maxLength)
{
    std::cout << "Enter array length (1 <= n <= " << maxLength << ")\n" << 
    "(Reccomend under 100): " << std::endl;
    checkInput(length);

    if (length > maxLength || length < 1)
    {
        std::cout << "Check limits!" << std::endl;
        exit(1);
    }
}

// Выбор режима заполнения массива
void chooseMode(int &mode)
{
    std::cout << "How would you fill array with integers?" << std::endl
              << "Keyboard (0) or random (1)?" << std::endl;

    checkInput(mode);
}

// Заполнение масива
void fillArr(int mode, int n, int *arr)
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
void keyboardEnter(int n, int arr[])
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "Elem " << i + 1 << ": ";
        checkInput(arr[i]);
    }
}

// Рандомный ввод
void randomEnter(int n, int *arr)
{
    int a, b;
    limitsForRandom(a, b);

    std::mt19937 gen(45218965);

    for (int i = 0; i < n; i++)
    {
        arr[i] = randomNumber(gen, a, b);
    }
}

// Границы значений элементов
void limitsForRandom(int &a, int &b)
{
    std::cout << "Enter integer limits of elements (a, b)" << std::endl
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
int randomNumber(std::mt19937 &gen, int a, int b)
{
    std::uniform_int_distribution<int> dist(a, b);
    return dist(gen);
}

// Поменять местами два числа
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Показать массив поэлементно
void showArr(int n, int arr[])
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "Elem " << i + 1 << ": " << arr[i] << std::endl;
    }
}

// Полная подготовка массива
void createArr(int &n, int *arr, int &mode, int maxLength)
{
    checkoutArrLength(n, maxLength);
    chooseMode(mode);
    fillArr(mode, n, arr);

    std::cout << "\nCreated array:\n";
    showArr(n, arr);
}

// Решение подзадачи 1:
// Произведение элементов массива с четными номерами;
void task1(int n, int *arr)
{
    long long mult = 1;
    bool hasZero = false;
    
    for (int i = 1; i < n; i += 2)
    {
        if (arr[i] != 0)
        {
            mult *= arr[i];
        } else
        {
            hasZero = true;
        }      
    }

    if (hasZero)
    {
        std::cout << "1.Mult of elements with even numbers" << std::endl
                  << "-For all elements: 0" << std::endl
                  << "-For non-zero elements: " << mult << std::endl;
    } else
    {
        std::cout << "1.Mult of elements with even numbers: " << mult << std::endl;
    }
    
}

// Решение подзадачи 2:
// Сумма элементов массива, расположенных между первым и последним
// нулевыми элементами.
void task2(int n, int *arr) {
    int firstZero = 0;
    long long sum = 0, partSum = 0;
    bool enoughZeros = false;

    while (arr[firstZero] != 0 && firstZero < n - 1)
    {
        firstZero += 1;
    }

    for (int i = firstZero + 1; i < n; i++)
    {
        if (arr[i] == 0)
        {
            sum += partSum;
            partSum = 0;
            enoughZeros  = true;
        } else
        {
            partSum += arr[i];
        }
    }

    if (!enoughZeros)
    {
        std::cout << "Not enough null-elements for the task\n";
    } else 
    {
        std::cout << "\n2.Sum between zero-elements (if such exist): "
              << sum << "\n\n";
    }
    
}

// Решение подзадач
void solveTasks(int n, int *arr) {
    std::cout << std::endl << "--RESULTS--\n\n";
    task1(n, arr);
    task2(n, arr);
}

// Перенести отрицательный элемент вначало
void moveElem(int copyId, int *arr, int lastNegative) {
    while (copyId > lastNegative)
    {
        swap(arr[copyId], arr[copyId-1]);
        copyId -= 1;
    }
    
}

// Преобразование массива
void changeArr(int n, int *arr) {
    int lastNegative = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < 0)
        {
            moveElem(i, arr, lastNegative);
            lastNegative++;
        } 
    }

    std::cout << "Changed array:\n";
    showArr(n, arr);
}
