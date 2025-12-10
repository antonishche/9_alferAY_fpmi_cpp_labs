// Доп задание:
// Вынести создание и удаление двумерного динамического
// целочисленного массива в функцию

#include <iostream>

// Основные функции
void createMatrix(int**& arr, int l, int w);
void deleteMatrix(int**& arr, int l);
void printMatrix(int** arr, int l, int w);
void fillMatrix(int**& arr, int length, int width);

// Вспомогательные функции
int initMatrixLength();
int initMatrixWidth();
void checkInput(int& empty);

int main() {
    int length = initMatrixLength();
    int width = initMatrixWidth();

    int** matrix;

    createMatrix(matrix, length, width);
    fillMatrix(matrix, length, width);
    printMatrix(matrix, length, width);
    deleteMatrix(matrix, length);

    return 0;
}

void checkInput(int& empty) {
    if(!(std::cin >> empty)) {
        std::cout << "Invalid input!";
        std::exit(1);
    }
}

int initMatrixLength() {
    int length;
    std::cout << "Init matrix length";
    checkInput(length);

    return length;
}

int initMatrixWidth() {
    int width;
    std::cout << "Init matrix width";
    checkInput(width);

    return width;
}

void createMatrix(int**& arr, int l, int w) {
    arr = new int* [l];

    for (size_t row = 0; row < l; row++)
    {
        arr[row] = new int[w];
    }
}

void fillMatrix(int**& arr, int l, int w) {
    for (size_t i = 0; i < l; i++)
    {
        std::cout << "Str " << i + 1 << std::endl;
        for (size_t j = 0; j < w; j++)
        {
            std::cout << "Elem " << j + 1 << ":";
            checkInput(arr[i][j]);
        }
        
    }
    
}

void deleteMatrix(int**& arr, int l) {
    for (size_t i = 0; i < l; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;
    
}

void printMatrix(int** arr, int l, int w) {
    for (size_t i = 0; i < l; i++)
    {
        std::cout << "Str " << i + 1 << std::endl;
        for (size_t j = 0; j < w; j++)
        {
            std::cout << "Elem " << j + 1 << ": " << arr[i][j] << "\n";
        }
        
    }
    
}
