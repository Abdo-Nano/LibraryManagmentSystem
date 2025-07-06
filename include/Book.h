#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <vector>
#include "Category.h"

enum class Status { AVAILABLE, LOST, ISSUED };

class Book {
private:
    int id;
    int isbn;
    std::string title;
    std::vector<std::string> authors;
    int quantity;
    Category category;
    Status status;

public:
    Book(int id, int isbn, const std::string& title, const std::vector<std::string>& authors, int quantity, const Category& category);

    int getId() const;
    int getISBN() const;
    std::string getTitle() const;
    std::vector<std::string> getAuthors() const;
    int getQuantity() const;
    Category getCategory() const;
    Status getStatus() const;

    void setQuantity(int q);
    void setStatus(Status s);
};

#endif

