// Доп задание:
// Создание и удаление квадратной матрицы
// Выбор: вручную и рандом
// Сортировка строк
// Выбор: по возрастанию или по убыванию
// Выбор типа

#include <iostream>
#include <random>

// Основные функции
void createMatrix(int &n, int **&matrix, int &mode);
void sortMatrix(int n, int **&matrix);
void deleteMatrix(int n, int **&matrix);

// Подфункции
void chooseMode(int &mode);
void checkoutMatrixSizes(int &size);
void fillArr(int mode, int n, int **&matrix);
void keyboardEnter(int n, int **&matrix);
void randomEnter(int n, int **&matrix);
void limitsForRandom(int &a, int &b);
void choseHowToSort(int& howToSort);
void choseTypeOfSort(int& typeOfSort);

// Вспомогательные функции
void checkInput(int &empty);
void showMatrix(int n, int **matrix);
void swap(int &a, int &b);
int randomNumber(std::mt19937 &gen, int a, int b);
void reverseArray(int* arr, int n);

// Сортировки
void insertionSort(int n, int**& matrix);
void quickSort(int n, int**& matrix);
void selectionSort(int n, int**& matrix);
void bubbleSort(int n, int**& matrix);
void countingSort(int n, int**& matrix);
void mergeSort(int n, int**& matrix);

// Выбор сортировки
void choseSort(int typeOfSort, int howToSort, int n, int **&matrix);

int main()
{
    int n, mode;
    int **matrix;

    createMatrix(n, matrix, mode);
    sortMatrix(n, matrix);
    deleteMatrix(n, matrix);

    return 0;
}

// Создание целочисленной матрицы
void createMatrix(int &n, int **&matrix, int &mode)
{
    checkoutMatrixSizes(n);

    matrix = new int *[n];
    for (size_t row = 0; row < n; row++)
    {
        matrix[row] = new int[n];
    }

    chooseMode(mode);
    fillArr(mode, n, matrix);
}

// Удаление матрицы
void deleteMatrix(int n, int **&matrix)
{
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
                     "Be careful next time"
                  << std::endl;
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
void fillArr(int mode, int n, int **&matrix)
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
void keyboardEnter(int n, int **&matrix)
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
void randomEnter(int n, int **&matrix)
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
void showMatrix(int n, int **matrix)
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

// Переворот массива
void reverseArray(int* arr, int n) {
    for (int i = 0; i < n / 2; i++) {
        swap(arr[i], arr[n - 1 - i]);
    }
}

// Выбрать как сортировать
void choseHowToSort(int& howToSort) {
    std::cout << "Sort by\n ascending (0) or descending (1): ";
    checkInput(howToSort);

    if (howToSort != 0 && howToSort != 1)
    {
        std::cout << "Invalid value!\nBe careful while entering.";
        std::exit(0);
    }
}

// Выбрать тип сортировки
void choseTypeOfSort(int& typeOfSort) {
    std::cout << "Sort type:\n"
              << "insertion (1), quicksort (2), selection (3), bubble(4), counting (5), merge (6):";
    checkInput(typeOfSort);
}

// Отсортировать матрицу
void sortMatrix(int n, int **&matrix)
{
    int howToSort;
    choseHowToSort(howToSort);

    int typeOfSort;
    choseTypeOfSort(typeOfSort);

    choseSort(typeOfSort, howToSort, n, matrix);
    
    std::cout << "Sorted matrix:\n";
    showMatrix(n, matrix);
}

void choseSort(int typeOfSort, int howToSort, int n, int **&matrix)
{
    switch (typeOfSort)
    {
    case 1: insertionSort(n, matrix); break;
    case 2: quickSort(n, matrix); break;
    case 3: selectionSort(n, matrix); break;
    case 4: bubbleSort(n, matrix); break;
    case 5: countingSort(n, matrix); break;
    case 6: mergeSort(n, matrix); break;
    default: 
        std::cout << "Unknown sort type."; 
        std::exit(1);
    }

    if (howToSort == 1) {
        for (int i = 0; i < n; i++) {
            reverseArray(matrix[i], n);
        }
    }
}

// Сортировка вставками (0)
void insertionSort(int n, int**& matrix) {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            int key = matrix[i][j];
            int k = j - 1;
            while (k >= 0 && matrix[i][k] > key) {
                matrix[i][k + 1] = matrix[i][k];
                k--;
            }
            matrix[i][k + 1] = key;
        }
    }
}

// Быстрая сортировка (2)
void quickSortRecursive(int** matrix, int row, int low, int high) {
    if (low < high) {
        int pivot = matrix[row][high];
        int i = low - 1;
        
        for (int j = low; j < high; j++) {
            if (matrix[row][j] <= pivot) {
                i++;
                swap(matrix[row][i], matrix[row][j]);
            }
        }
        swap(matrix[row][i + 1], matrix[row][high]);
        int pi = i + 1;
        
        quickSortRecursive(matrix, row, low, pi - 1);
        quickSortRecursive(matrix, row, pi + 1, high);
    }
}

void quickSort(int n, int**& matrix) {
    for (int i = 0; i < n; i++) {
        quickSortRecursive(matrix, i, 0, n - 1);
    }
}

// Сортировка выбором (3)
void selectionSort(int n, int**& matrix) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            int minIndex = j;
            for (int k = j + 1; k < n; k++) {
                if (matrix[i][k] < matrix[i][minIndex]) {
                    minIndex = k;
                }
            }
            swap(matrix[i][j], matrix[i][minIndex]);
        }
    }
}

// Сортировка пузырьком (4)
void bubbleSort(int n, int**& matrix) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            for (int k = 0; k < n - j - 1; k++) {
                if (matrix[i][k] > matrix[i][k + 1]) {
                    swap(matrix[i][k], matrix[i][k + 1]);
                }
            }
        }
    }
}

// Сортировка подсчётом (5)
void countingSort(int n, int**& matrix) {
    const int RANGE = 201;
    const int OFFSET = 100;

    for (int i = 0; i < n; i++) {
        int count[RANGE] = {0};

        // Подсчёт элементов
        for (int j = 0; j < n; j++) {
            count[matrix[i][j] + OFFSET]++;
        }

        // Восстановление отсортированного массива (по возрастанию)
        int index = 0;
        for (int j = 0; j < RANGE; j++) {
            while (count[j] > 0) {
                matrix[i][index++] = j - OFFSET;
                count[j]--;
            }
        }
    }
}

// Сортировка слиянием (6)
void merge(int** matrix, int row, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int leftArr[n1], rightArr[n2];
    
    for (int i = 0; i < n1; i++)
        leftArr[i] = matrix[row][left + i];
    for (int i = 0; i < n2; i++)
        rightArr[i] = matrix[row][mid + 1 + i];
    
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            matrix[row][k] = leftArr[i];
            i++;
        } else {
            matrix[row][k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        matrix[row][k] = leftArr[i];
        i++; k++;
    }
    
    while (j < n2) {
        matrix[row][k] = rightArr[j];
        j++; k++;
    }
}

void mergeSortRecursive(int** matrix, int row, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortRecursive(matrix, row, left, mid);
        mergeSortRecursive(matrix, row, mid + 1, right);
        merge(matrix, row, left, mid, right);
    }
}

void mergeSort(int n, int**& matrix) {
    for (int i = 0; i < n; i++) {
        mergeSortRecursive(matrix, i, 0, n - 1);
    }
}

