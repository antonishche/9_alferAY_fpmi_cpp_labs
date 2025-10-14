// Доп задание:
// Вынести создание и удаление динамического массива
// в функцию

#include <iostream>

// Создание динамического массива
int* createArr(int size) {
    return new int[size];
}

// Заполнение массива
void fillArr(int* arr, int size, int value = 0) {
    for (int i = 0; i < size; i++) {
        arr[i] = value;
    }
}

// Удаление массива
void deleteArr(int* arr) {
    delete[] arr;
}

// Вывод массива
void printArr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int size = 5;

    int* myArray = createArr(size);

    fillArr(myArray, size, 10);
    printArr(myArray, size);

    deleteArr(myArray);
    
    return 0;
}