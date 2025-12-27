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

std::string stringFromConsole() {
    std::string str;
    if (!getline(std::cin, str)) {
        throw std::runtime_error("не удалось записать строку.");
    }

    return str;
}

void putAuthorInRightPlace(const Author &newAuthor, std::list<Author> &authors) {
    std::list<Author>::iterator it = authors.begin();

    while (it != authors.end() && it->getSurame() < newAuthor.getSurame()) {
        ++it;
    }

    authors.insert(it, newAuthor);
}

Author writeAuthorFromStr(const std::string &authorFullName) {
    std::stringstream authorStream(authorFullName);
    std::string name, surname, fatherName;
    if (authorStream >> name >> fatherName >> surname) {
        Author newAuthor(name, surname, fatherName);
        return newAuthor;
    } else {
        throw std::runtime_error("не удалось распознать автора \"" + authorFullName + "\".");
    }
}

std::list<Author> packAuthors(const std::string &str) {
    std::string checkedStr = checkStrForEmpty(str);
    if (checkedStr.empty())
        return std::list<Author>();

    std::list<Author> authors;

    std::stringstream ss(checkedStr);
    std::string authorFullName;

    while (getline(ss, authorFullName, ',')) {

        try {
            Author newAuthor = writeAuthorFromStr(authorFullName);
            putAuthorInRightPlace(newAuthor, authors);
        } catch (const std::exception &e) {
            std::cerr << "Ошибка: " << e.what() << std::endl;
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

        str = checkStrForEmpty(str);

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

void AddBook(std::list<Book> &library) {
    std::cout << "Для добавления книги введите строку типа:\n777; Иван Иванович Иванов, Петр Петрович Петров; Название книги; 2024;\n";

    std::string bookStr = stringFromConsole();

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

std::list<Book>::iterator findBookByTitle(std::list<Book> &library) {
    std::list<Book>::iterator it = library.begin();

    try {
        std::string titleStr = checkStrForEmpty(stringFromConsole());

        while (it != library.end() && it->getTitle() != titleStr) {
            ++it;
        }

        if (it == library.end()) {
            std::cout << "Книга \"" << titleStr << "\" не найдена.\n";
        } else {
            std::cout << "------------------------------\nКнига найдена:\n------------------------------\n";
            printBook(*it);
        }

    } catch (const std::exception &e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return it;
}

void DeleteBook(std::list<Book> &library) {
    std::cout << "Для удаления книги введите её название:\n";

    std::list<Book>::iterator it = findBookByTitle(library);

    if (it != library.end()) {
        try {
            library.erase(it);
            std::cout << "Удаление завершено успешно.\n";
            printBooks(library);
        } catch (const std::exception &e) {
            std::cerr << "Ошибка: " << e.what() << std::endl;
        }
    }
}

void findBooksByAuthor(std::list<Book> &library) {
    std::cout << "Для поиска книг по автору введите автора (Имя Отчество Фамилия):\n";

    try {
        std::string authorStr = checkStrForEmpty(stringFromConsole());

        Author findedAuthor = writeAuthorFromStr(authorStr);

        bool hasBook = false;

        std::cout << "------------------------------\nКниги автора \"" << authorStr << "\":\n------------------------------\n";
        for (Book &book : library) {
            std::list<Author> authors = book.getAuthors();
            for (Author &author : authors) {
                if (author == findedAuthor) {
                    hasBook = true;
                    printBook(book);
                }
            }
        }

        if (!hasBook) {
            std::cout << "Не найдены.\n";
        }

    } catch (const std::exception &e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
}

Author chooseAuthor() {
    std::cout << "Введите автора (Имя Отчество Фамилия):\n";
    std::string authorStr = checkStrForEmpty(stringFromConsole());
    Author findedAuthor = writeAuthorFromStr(authorStr);

    return findedAuthor;
}

void addAuthorToBook(std::list<Book> &library) {
    std::cout << "Введите название книги для добавления автора:\n";
    std::list<Book>::iterator it = findBookByTitle(library);

    if (it != library.end()) {
        try {
            Author newAuthor = chooseAuthor();
            std::list<Author> authors = it->getAuthors();
            putAuthorInRightPlace(newAuthor, authors);
            it->setAuthors(authors);
            std::cout << "Автор добавлен.\n";
        } catch (...) {
            std::cerr << "Ошибка добавления автора.\n";
        }
    }
}

void deleteAuthorFromBook(std::list<Book> &library) {
    std::cout << "Введите название книги для удаления автора:\n";
    std::list<Book>::iterator it = findBookByTitle(library);

    if (it != library.end() && !it->getAuthors().empty()) {
        try {
            Author oddAuthor = chooseAuthor();
            std::list<Author> authors = it->getAuthors();

            if (authors.size() == 0) {
                throw std::logic_error("некого удалять.");
            }

            std::list<Author>::iterator authorsIterator = authors.begin();
            while (authorsIterator != authors.end() && !(*authorsIterator == oddAuthor)) {
                ++authorsIterator;
            }

            if (authorsIterator != authors.end()) {
                authors.erase(authorsIterator);
                it->setAuthors(authors);
                std::cout << "Автор удалён.\n";
            } else {
                std::cout << "Автор не найден.\n";
            }

        } catch (const std::exception &e) {
            std::cerr << "Ошибка: " << e.what() << std::endl;
        } catch (...) {
            std::cerr << "Ошибка удаления автора.\n";
        }
    }
}

int main() {

    setlocale(LC_ALL, "");

    std::string inputFileName = "BOOKS.TXT";
    std::ifstream inputFile(inputFileName);

    try {
        checkInputFile(inputFile, inputFileName);

        std::list<Book> library = writeDataFromFile(inputFile);

        printBooks(library);

        // AddBook(library);

        // DeleteBook(library);

        // std::cout << "Для поиска книги введите название книги:\n";
        // findBookByTitle(library);

        // findBooksByAuthor(library);

        // addAuthorToBook(library);

        deleteAuthorFromBook(library);

        printBooks(library);

    } catch (const std::exception &e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
