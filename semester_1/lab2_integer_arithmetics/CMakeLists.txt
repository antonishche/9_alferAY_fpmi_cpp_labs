cmake_minimum_required(VERSION 3.10)
project(Lab2IntegerArithmetic)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

add_library(task1_lib src/task1.cpp)

add_executable(run_tests tests/test_task1.cpp)
target_link_libraries(run_tests task1_lib GTest::gtest GTest::gtest_main)


enable_testing()
# gtest_discover_tests()
add_test(NAME task1_tests COMMAND run_tests)


# --- Настройка для Boost.Test (Заголовочная версия) ---
# Эта версия проще, она включает весь код тестов напрямую
set(BOOST_ROOT "/opt/homebrew")
add_executable(run_boost_tests boost_tests/test_task1_boost.cpp)
# Связываем с нашей библиотекой алгоритмов
target_link_libraries(run_boost_tests task1_lib)
# Указываем компилятору, где искать заголовки Boost
target_include_directories(run_boost_tests PRIVATE /opt/homebrew/include)