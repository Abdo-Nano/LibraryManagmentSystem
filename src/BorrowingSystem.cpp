//
// Created by abdo on 7/6/25.
//

#include "../include/BorrowingSystem.h"

bool BorrowingSystem::borrowBook(int bookId, int memberId, std::vector<Book>& books) {
    for (auto& book : books) {
        if (book.getId() == bookId && book.getQuantity() > 0) {
            book.setQuantity(book.getQuantity() - 1);
            borrowedBooks[memberId].push_back(book);
            return true;
        }
    }
    return false;
}

bool BorrowingSystem::returnBook(int bookId, int memberId) {
    auto& borrowed = borrowedBooks[memberId];
    for (auto it = borrowed.begin(); it != borrowed.end(); ++it) {
        if (it->getId() == bookId) {
            it->setQuantity(it->getQuantity() + 1);
            borrowed.erase(it);
            return true;
        }
    }
    return false;
}

std::vector<Book> BorrowingSystem::getBorrowedBooks(int memberId) const {
    if (borrowedBooks.find(memberId) != borrowedBooks.end()) {
        return borrowedBooks.at(memberId);
    }
    return {};
}
