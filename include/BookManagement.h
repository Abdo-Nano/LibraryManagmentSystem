//
// Created by abdo on 7/6/25.
//

#ifndef BOOKMANAGEMENT_H
#define BOOKMANAGEMENT_H

#include "Book.h"
#include <vector>
#include <optional>

class BookManagement {
private:
    std::vector<Book> books;

public:
    bool addNewBook(const Book& book);
    bool removeBook(int id);
    bool updateBook(int id, const Book& updatedBook);
    std::optional<Book> searchBook(int id) const;
    std::vector<Book> getAllBooks() const;
};

#endif
