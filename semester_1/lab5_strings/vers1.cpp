// 1. Преобразовать строку по следующему правилу: найти первое из самых
// больших и последнее из самых малых слов-чисел (по длине) и поменять
// их местами. Количество разделителей между словами должно остаться
// таким же, как и в исходной строке.

#include <iostream>
#include <string>
#include <vector>

// Прототипы функций
void getTextString(std::string &text);
void getSeparators(std::string &separators);
std::vector<std::string> splitText(const std::string &text, const std::string &separators, std::vector<std::string> &separators_between);
void printArr(const std::vector<std::string> &words);
void changeArrWords(std::vector<std::string> &words);
void checkArrSize(const std::vector<std::string> &words);
void findWords(const std::vector<std::string> &words, size_t &shortId, size_t &longId);
void swapWords(std::vector<std::string> &words, size_t shortId, size_t longId);
std::string createNewString(const std::vector<std::string> &words, const std::vector<std::string> &separators_between);

int main() {

    int longestId, shortestId;
    std::string text, separators;
    
    getTextString(text);
    getSeparators(separators);

    std::vector<std::string> separators_between;
    std::vector<std::string> words = splitText(text, separators, separators_between);

    changeArrWords(words);

    std::string output = createNewString(words, separators_between);

    return 0;
}

void getTextString(std::string &text) {
    std::cout << "\nEnter your string: ";
    getline(std::cin, text);
}

void getSeparators(std::string &separators) {
    std::cout << "\nEnter string of separators: ";
    getline(std::cin, separators);
}

std::vector<std::string> splitText(const std::string &text, const std::string &separators, std::vector<std::string> &separators_between) {
    std::vector<std::string> words;
    separators_between.clear();

    size_t start = 0;
    size_t end = 0;
    
    while (end != std::string::npos) {
        start = text.find_first_not_of(separators, end);
        if (start == std::string::npos) break;
        
        end = text.find_first_of(separators, start);
        
        std::string word = text.substr(start, end - start);
        if (!word.empty()) {
            words.push_back(word);
            
            // Сохраняем разделитель после слова
            if (end != std::string::npos) {
                size_t sep_end = text.find_first_not_of(separators, end);
                separators_between.push_back(text.substr(end, sep_end - end));
                end = sep_end;
            }
        }
    }

    printArr(words);
    return words;
}

void printArr(const std::vector<std::string> &words) {;
    std::cout << std::endl;
    for (size_t i = 0; i < words.size(); i++)
    {
        std::cout << "[" << i << "]" << " " << words[i] << "\n";
    }
    std::cout << std::endl;
}

void changeArrWords(std::vector<std::string> &words) {

    checkArrSize(words);
     
    size_t shortId = 0, longId = 0;

    findWords(words, shortId, longId);

    swapWords(words, shortId, longId);
    printArr(words);
    
}

void checkArrSize(const std::vector<std::string> &words) {
    if (words.empty())
    {
        std::cout << "No words founded.\nEnter at least one word";
        std::exit(1);
    }
}

void findWords(const std::vector<std::string> &words, size_t &shortId, size_t &longId) {
    
    size_t shortLen = words[0].length(), longLen = words[0].length();
    
    for (size_t i = 1; i < words.size(); i++)
    {
        int currLen = words[i].length();

        if (currLen < shortLen)
        {
            shortId = i;
            shortLen = currLen;
        } else if (currLen >= longLen)
        {
            longId = i;
            longLen = currLen;
        }
    }
    
    std::cout << "First shortest word's id: " << shortId << ",\n"
              << "Last longest word's id: " << longId << ".\n";
}

void swapWords(std::vector<std::string> &words, size_t shortId, size_t longId) { 
    std::string temp = words[shortId];
    words[shortId] = words[longId];
    words[longId] = temp;
}

std::string createNewString(const std::vector<std::string> &words, const std::vector<std::string> &separators_between) {
    std::string output = "";
    
    for (size_t i = 0; i < words.size(); i++) {
        output += words[i];
        if (i < separators_between.size()) {
            output += separators_between[i];
        }
    }

    std::cout << "\nResult:\n" << output << std::endl;
    return output;
}