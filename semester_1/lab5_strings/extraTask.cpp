// Сложить два числа (строки) в столбик

#include <iostream>
#include <string>
#include <algorithm>

// Прототипы
/**/
void defineNums(std::string &num1, std::string &num2);
std::string::size_type defineLength(const std::string &num1, const std::string &num2);
void reverseNum(std::string &num);
std::string combineNums(const std::string &num1, const std::string &num2, const std::string::size_type &length);
/**/

int main() {
    std::string num1, num2;
    defineNums(num1, num2);
    std::string::size_type length = defineLength(num1, num2);

    reverseNum(num1);
    reverseNum(num2);

    std::string sum = combineNums(num1, num2, length);

    std::cout << "Sum = " << sum << std::endl;

    return 0;
}

void defineNums(std::string &num1, std::string &num2) {
    std::cout << "Enter num1" << std::endl;
    getline(std::cin, num1);

    std::cout << "Enter num2" << std::endl;
    getline(std::cin, num2);
}

std::string::size_type defineLength(const std::string &num1, const std::string &num2) {
    std::string::size_type len1 = num1.length(), len2 = num2.length();
    return len1 > len2 ? len1 : len2;
}

void reverseNum(std::string &num) {
    std::reverse(num.begin(), num.end());
}

std::string combineNums(const std::string &num1, const std::string &num2, const std::string::size_type &length) {
    std::string sum;
    int rest = 0;

    for (std::string::size_type i = 0; i < length; i++)
    {
        int firstDigit = i < num1.length() ? num1[i] - '0' : 0,
            secondDigit = i < num2.length() ? num2[i] - '0' : 0;

            std::cout << i << ":" << "firstD = " << firstDigit << ", secondD = " << secondDigit << std::endl;


        int partSum = firstDigit + secondDigit + rest;

        std::cout << "Sum = " << partSum << std::endl;
        rest = partSum / 10;
        sum += std::to_string(partSum % 10);
        
    }
    
    if (rest != 0)
    {
        sum += std::to_string(rest);
    }
    
    reverseNum(sum);

    return sum;
    
}