#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <exception>
#include <stdexcept>

struct WordInfo {
    std::string str;
    size_t repeats = 0;
};

void checkInputFile(std::ifstream& file, const std::string& fileName) {
    if (!file)
    {
        throw std::runtime_error("could not open file \"" + fileName + "\".");
    }

    if (file.peek() == std::fstream::traits_type::eof())
    {
        throw std::runtime_error("file \"" + fileName + "\" is empty.");
    }
    
}

size_t findIndex(const std::vector<WordInfo>& words, const std::string& word) {

    for (size_t i = 0; i < words.size(); i++)
    {
        if (words[i].str == word)
        {
            return i;
        }
        
    }

    return -1;
}

std::vector<WordInfo> getWords(std::ifstream& file) {
    std::vector<WordInfo> words;

    std::string word;
    while (file >> word)
    {
        size_t index = findIndex(words, word);
        if (index == -1)
        {
            words.push_back({word, 1});
        } else {
            words[index].repeats++;
        }
        
    }

    return words;
}

// void printWords(const std::vector<WordInfo>& words) {
//     for (size_t i = 0; i < words.size(); i++)
//     {
//         std::cout << words[i].str << ",";
//     }
    
// }

size_t getIndexMax(const std::vector<WordInfo>& words) {
    size_t maxIndex = 0;
    size_t maxRepeats = words[0].repeats;

    for (size_t i = 1; i < words.size(); i++)
    {
        size_t currentRepeats = words[i].repeats;
        if (currentRepeats > maxRepeats)
        {
            maxIndex = i;
            maxRepeats = currentRepeats;
        }
        
    }
    return maxIndex;
}

int main() {
    const std::string inputFileName = "input.txt";
    std::ifstream inputFile(inputFileName);

    try
    {
        checkInputFile(inputFile, inputFileName);
        std::vector<WordInfo> words = getWords(inputFile);
        if (words.empty())
        {
            throw std::runtime_error("could not find words.");
        }
        
        // printWords(words);

        size_t indexMax = getIndexMax(words);

        // std::ofstream outputFile("output.txt");
        // outputFile << words[indexMax].str << std::endl;
        std::cout 
            << "Cлово, которое чаще всего встречается в файле: "
            << words[indexMax].str
            << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    
    return 0;
}