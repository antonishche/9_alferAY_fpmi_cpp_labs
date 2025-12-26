#include "book.h"

size_t Book::getUDC() const {
    return UDC_;
}

std::list<Author> Book::getAuthors() const {
    return authors_;
}

std::string Book::getTitle() const {
    return title_;
}

size_t Book::getPublicationDate() const {
    return publication_date_;
}

void Book::setUDC(size_t UDC) {
    UDC_ = UDC;
}

void Book::setAuthors(const std::list<Author> &authors) {
    authors_ = authors;
}

void Book::setTitle(const std::string &title) {
    title_ = title;
}

void Book::setPublicationDate(size_t publicationDate) {
    publication_date_ = publicationDate;
}