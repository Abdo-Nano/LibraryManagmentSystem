//
// Created by abdo on 7/6/25.
//


#ifndef BORROWINGSYSTEM_H
#define BORROWINGSYSTEM_H

#include "Book.h"
#include "Member.h"
#include <unordered_map>
#include <vector>

class BorrowingSystem {
private:
    std::unordered_map<int, std::vector<Book>> borrowedBooks;

public:
    bool borrowBook(int bookId, int memberId, std::vector<Book>& books);
    bool returnBook(int bookId, int memberId);
    std::vector<Book> getBorrowedBooks(int memberId) const;
};

#endif

