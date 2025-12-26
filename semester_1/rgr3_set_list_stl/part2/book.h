#include "author.h"

class Book {
public:
    size_t getUDC() const;
    std::list<Author> getAuthors() const;
    std::string getTitle() const;
    size_t getPublicationDate() const;

    void setUDC(size_t UDC);
    void setAuthors(const std::list<Author> &authors);
    void setTitle(const std::string &title);
    void setPublicationDate(size_t publicationDate);

private:
    size_t UDC_;
    std::list<Author> authors_;
    std::string title_;
    size_t publication_date_;
};