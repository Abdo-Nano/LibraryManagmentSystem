//
// Created by abdo on 7/6/25.
//

#include "../include/BookManagement.h"

bool BookManagement::addNewBook(const Book& book) {
    books.push_back(book);
    return true;
}

bool BookManagement::removeBook(int id) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->getId() == id) {
            books.erase(it);
            return true;
        }
    }
    return false;
}

bool BookManagement::updateBook(int id, const Book& updatedBook) {
    for (auto& book : books) {
        if (book.getId() == id) {
            book = updatedBook;
            return true;
        }
    }
    return false;
}

std::optional<Book> BookManagement::searchBook(int id) const {
    for (const auto& book : books) {
        if (book.getId() == id)
            return book;
    }
    return std::nullopt;
}

std::vector<Book> BookManagement::getAllBooks() const {
    return books;
}
