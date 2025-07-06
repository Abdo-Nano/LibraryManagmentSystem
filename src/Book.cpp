//
// Created by abdo on 7/6/25.
//

#include "../include/Book.h"

Book::Book(int id, int isbn, const std::string& title, const std::vector<std::string>& authors, int quantity, const Category& category)
    : id(id), isbn(isbn), title(title), authors(authors), quantity(quantity), category(category), status(Status::AVAILABLE) {}

int Book::getId() const { return id; }

int Book::getISBN() const { return isbn; }

std::string Book::getTitle() const { return title; }

std::vector<std::string> Book::getAuthors() const { return authors; }

int Book::getQuantity() const { return quantity; }

Category Book::getCategory() const { return category; }

Status Book::getStatus() const { return status; }

void Book::setQuantity(int q) { quantity = q; }

void Book::setStatus(Status s) { status = s; }
