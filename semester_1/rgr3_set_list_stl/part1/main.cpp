#include <iostream>
#include <limits>
#include <set>
#include <stdexcept>

size_t getN() {
  long long input;

  std::cout << "Введите N: ";

  if (!(std::cin >> input)) {
    throw std::invalid_argument("введено некорректное значение или число слишком велико.");
  }

  if (input <= 0) {
    throw std::out_of_range("число N должно быть положительным.");
  }

  if (input > 100000) {
    throw std::out_of_range("слишком большое N.");
  }

  return static_cast<size_t>(input);
}

void fillNums(std::set<size_t>& nums, size_t N) {
  for (size_t i = 2; i <= N; i++) {
    nums.insert(i);
  }
}

void filterNums(std::set<size_t>& nums, size_t N) {
  for (size_t num = 2; num * num <= N; num++) {
    if (nums.count(num)) {
      for (size_t toDelete = num * num; toDelete <= N; toDelete += num) {
        nums.erase(toDelete);
      }
    }
  }
}

void printNums(const std::set<size_t>& nums, size_t N) {
  std::cout << "*\nВсе простые числа, не превосходящие " << N << ":\n";

  if (nums.empty()) {
    std::cout << "Отсутствуют.\n";
  } else {
    for (const size_t num : nums) {
      std::cout << num << " ";
    }
  }
}

int main() {
  // your code goes here

  setlocale(LC_ALL, "Russian");

  try {
    size_t N = getN();

    std::set<size_t> nums;

    fillNums(nums, N);
    filterNums(nums, N);
    printNums(nums, N);

  } catch (const std::exception& e) {
    std::cerr << "Ошибка: " << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Произошла неизвестная ошибка." << std::endl;
  }

  return 0;
}