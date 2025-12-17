#include <gtest/gtest.h>
#include "../src/task1.h"

TEST(RemoveMinDigitsTest, BasicTest) {
    EXPECT_EQ(remove_min_digits(12341), 234);
    EXPECT_EQ(remove_min_digits(555), 0);
    EXPECT_EQ(remove_min_digits(98765), 9876);
    EXPECT_EQ(remove_min_digits(1234321), 23432);
}

TEST(RemoveMinDigitsTest, WithZero) {
    EXPECT_EQ(remove_min_digits(102030), 123);   // Удаляем 0
    EXPECT_EQ(remove_min_digits(100200300), 123); // Несколько нулей
    EXPECT_EQ(remove_min_digits(101010), 111);    // Чередование с нулями
}

TEST(RemoveMinDigitsTest, SingleAndRepeated) {
    EXPECT_EQ(remove_min_digits(7), 0);          // Одна цифра
    EXPECT_EQ(remove_min_digits(111), 0);        // Все одинаковые
    EXPECT_EQ(remove_min_digits(1122), 22);      // Удаляем 1
    EXPECT_EQ(remove_min_digits(2211), 22);      // Удаляем 1 (в конце)
}

TEST(RemoveMinDigitsTest, EdgeCases) {
    EXPECT_EQ(remove_min_digits(0), 0);          // Ноль
    EXPECT_EQ(remove_min_digits(10), 1);         // 0 - минимальная
    EXPECT_EQ(remove_min_digits(99), 0);         // Две одинаковые
    EXPECT_EQ(remove_min_digits(123456789), 23456789); // 1 минимальная
    EXPECT_EQ(remove_min_digits(987654321), 98765432); // 1 минимальная
}

TEST(RemoveMinDigitsTest, RandomCases) {
    EXPECT_EQ(remove_min_digits(332211), 3322);  // Минимальная 1
    EXPECT_EQ(remove_min_digits(444333), 444);   // Минимальная 3
    EXPECT_EQ(remove_min_digits(121212), 222);   // Минимальная 1
    EXPECT_EQ(remove_min_digits(777888), 888);   // Минимальная 7
}

TEST(FindMinDigitTest, Basic) {
    EXPECT_EQ(find_min_digit(12341), 1);
    EXPECT_EQ(find_min_digit(98765), 5);
    EXPECT_EQ(find_min_digit(111), 1);
    EXPECT_EQ(find_min_digit(999), 9);
}

TEST(FindMinDigitTest, WithZero) {
    EXPECT_EQ(find_min_digit(102030), 0);
    EXPECT_EQ(find_min_digit(1000), 0);
    EXPECT_EQ(find_min_digit(500), 0);
}

TEST(FindMinDigitTest, SingleDigit) {
    EXPECT_EQ(find_min_digit(0), 0);
    EXPECT_EQ(find_min_digit(5), 5);
    EXPECT_EQ(find_min_digit(9), 9);
}

TEST(FindMinDigitTest, AllSame) {
    EXPECT_EQ(find_min_digit(777), 7);
    EXPECT_EQ(find_min_digit(22), 2);
    EXPECT_EQ(find_min_digit(4444), 4);
}

// Тест на обработку отрицательных чисел (если требуется)
TEST(RemoveMinDigitsTest, InvalidInput) {
    EXPECT_EQ(remove_min_digits(-123), 0);      // Отрицательное число
    EXPECT_EQ(remove_min_digits(-1), 0);        // Отрицательная цифра
}

// Дополнительный тест для пустого результата
TEST(RemoveMinDigitsTest, EmptyResult) {
    EXPECT_EQ(remove_min_digits(1), 0);         // Только минимальная цифра
    EXPECT_EQ(remove_min_digits(11), 0);        // Все минимальные
    EXPECT_EQ(remove_min_digits(1111), 0);      // Все минимальные (много)
}