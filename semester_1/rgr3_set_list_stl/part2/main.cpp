#include "book.h"

#include <fstream>
#include <sstream>
#include <stdexcept>

void checkInputFile(std::ifstream &file, const std::string &fileName) {
    if (!file.is_open()) {
        throw std::runtime_error("не удалось открыть файл \"" + fileName + "\".");
    }

    if (file.peek() == std::fstream::traits_type::eof()) {
        throw std::runtime_error("файл \"" + fileName + "\" пуст.");
    }
}

std::string checkStrForEmpty(const std::string &str) {
    size_t start = str.find_first_not_of(' ');
    if (start == std::string::npos)
        return "";
    size_t end = str.find_last_not_of(' ');
    return str.substr(start, end - start + 1);
}

size_t checkNum(const std::string &str) {
    long long input;
    try {
        input = std::stoll(str);
    } catch (const std::exception &) {
        throw std::invalid_argument("неверный формат числа: " + str);
    }
    if (input <= 0) {
        throw std::invalid_argument("число должно быть положительным: " + str);
    }
    return static_cast<size_t>(input);
}

void putAuthorInRightPlace(const Author &newAuthor, std::list<Author> &authors) {
    std::list<Author>::iterator it = authors.begin();

    while (it != authors.end() && it->getSurame() < newAuthor.getSurame()) {
        ++it;
    }

    authors.insert(it, newAuthor);
}

std::list<Author> packAuthors(const std::string &str) {
    std::string checkedStr = checkStrForEmpty(str);
    if (checkedStr.empty())
        return std::list<Author>();

    std::list<Author> authors;
    std::stringstream ss(checkedStr);
    std::string authorFullName;

    while (getline(ss, authorFullName, ',')) {
        std::stringstream authStream(authorFullName);
        std::string name, surname, fatherName;
        if (authStream >> name >> fatherName >> surname) {
            Author newAuthor(name, surname, fatherName);
            putAuthorInRightPlace(newAuthor, authors);
        }
    }

    if (authors.empty()) {
        throw std::invalid_argument("не удалось записать автора из строки: \"" + str + "\".");
    }

    return authors;
}

void putBookInRightBookshelf(const Book &newBook, std::list<Book> &books) {
    std::list<Book>::iterator it = books.begin();

    while (it != books.end() && it->getTitle() < newBook.getTitle()) {
        ++it;
    }

    books.insert(it, newBook);
}

Book writeBookFromStr(const std::string &bookStr) {
    size_t count = 4; // 4 поля в классе Book

    size_t start = 0;
    size_t end = bookStr.find(";", start);

    Book newBook;

    for (size_t i = 0; i < count && start != std::string::npos; i++) {
        std::string str = bookStr.substr(start, end - start);

        if (str.find_first_not_of(' ') == std::string::npos) {
            str = "";
        }

        try {
            switch (i) {
            case 0:
                if (str.empty()) {
                    throw std::invalid_argument("поле UDC пусто");
                }
                newBook.setUDC(checkNum(str));
                break;
            case 1:
                if (str.empty()) {
                    newBook.setAuthors(std::list<Author>());
                } else {
                    newBook.setAuthors(packAuthors(str));
                }
                break;
            case 2:
                if (str.empty()) {
                    throw std::invalid_argument("поле названия пусто");
                }
                newBook.setTitle(checkStrForEmpty(str));
                break;
            case 3:
                if (str.empty()) {
                    throw std::invalid_argument("поле года пусто");
                }
                newBook.setPublicationDate(checkNum(str));
                break;
            default:
                throw std::runtime_error("невалидный этап при чтении строки:\n" + bookStr);
                break;
            }
        } catch (const std::exception &e) {
            throw;
        }

        start = end + 1;
        if (start == std::string::npos) {
            throw std::runtime_error("переменная start приняла значение npos в строке:\n" + bookStr);
        }
        end = bookStr.find(";", start);
    }

    return newBook;
}

std::list<Book> writeDataFromFile(std::ifstream &file) {
    std::list<Book> books;

    std::string bookStr;
    while (getline(file, bookStr)) {
        try {
            Book newBook = writeBookFromStr(bookStr);
            putBookInRightBookshelf(newBook, books);
        } catch (const std::exception &e) {
            std::cerr << "*\nОшибка: " << e.what() << std::endl;
            std::cout << "Книга \"" + bookStr + "\" не записана.\n*" << std::endl;
        }
    }

    return books;
}

void printBook(const Book &book) {
    std::cout << "УДК: " << book.getUDC() << ";\nНазвание: " << book.getTitle() << ";\nГод издания: " << book.getPublicationDate() << ";\n";

    std::cout << "Авторы: ";
    bool hasAuthor = false;
    for (const Author &author : book.getAuthors()) {
        hasAuthor = true;
        std::cout << author.getName() << " " << author.getFatherName() << " " << author.getSurame() << "; ";
    }

    if (!hasAuthor) {
        std::cout << "отсутствуют.\n";
    } else {
        std::cout << "\n";
    }

    std::cout << "..............................\n";
}

void printBooks(const std::list<Book> &library) {
    std::cout << "==============================\nБиблиотека:\n==============================\n";

    bool hasBook = false;

    for (const Book &book : library) {
        hasBook = true;
        printBook(book);
    }

    if (!hasBook) {
        std::cout << "Пуста." << std::endl;
    }

    std::cout << "==============================\n";
}

void Add(std::list<Book> &library) {
    std::cout << "Для добавления книги введите строку типа:\n777; Иван Иванович Иванов, Петр Петрович Петров; Название книги; 2024;\n";

    std::string bookStr;
    if (!getline(std::cin, bookStr)) {
        throw std::runtime_error("не удалось записать строку.");
    }

    try {
        Book newBook = writeBookFromStr(bookStr);
        putBookInRightBookshelf(newBook, library);
        std::cout << "------------------------------\nКнига добавлена:\n------------------------------\n";
        printBook(newBook);
    } catch (const std::exception &e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        std::cout << "Книга \"" + bookStr + "\" не добавлена.\n";
    }
}

void Delete(std::list<Book> &library) {
}

int main() {

    setlocale(LC_ALL, "");

    std::string inputFileName = "BOOKS.TXT";
    std::ifstream inputFile(inputFileName);

    try {
        checkInputFile(inputFile, inputFileName);

        std::list<Book> library = writeDataFromFile(inputFile);

        printBooks(library);

        Add(library);
        Delete(library);

    } catch (const std::exception &e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
