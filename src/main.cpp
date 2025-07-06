#include <iostream>
#include <limits>
#include "../include/BookManagement.h"
#include "../include/MemberManagment.h"
#include "../include/BorrowingSystem.h"
#include "../include/Category.h"

void pause() {
    std::cout << "Press Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    BookManagement bookManager;
    MemberManagement memberManager;
    BorrowingSystem borrowingSystem;

    int choice;

    while (true) {
        std::cout << "\n--- Library Management System ---\n";
        std::cout << "1. Add Book\n";
        std::cout << "2. View All Books\n";
        std::cout << "3. Add Member\n";
        std::cout << "4. View All Members\n";
        std::cout << "5. Borrow Book\n";
        std::cout << "6. Return Book\n";
        std::cout << "7. Exit\n";
        std::cout << "Select an option: ";
        std::cin >> choice;
        std::cin.ignore(); // flush newline

        if (choice == 1) {
            int id, isbn, quantity;
            std::string title, categoryTitle, categoryDesc;
            std::vector<std::string> authors;
            std::string author;

            std::cout << "Enter Book ID: ";
            std::cin >> id;
            std::cout << "Enter ISBN: ";
            std::cin >> isbn;
            std::cin.ignore();

            std::cout << "Enter Title: ";
            std::getline(std::cin, title);

            std::cout << "Enter number of authors: ";
            int authorCount;
            std::cin >> authorCount;
            std::cin.ignore();

            for (int i = 0; i < authorCount; ++i) {
                std::cout << "Author " << (i + 1) << ": ";
                std::getline(std::cin, author);
                authors.push_back(author);
            }

            std::cout << "Enter Quantity: ";
            std::cin >> quantity;
            std::cin.ignore();

            std::cout << "Enter Category Title: ";
            std::getline(std::cin, categoryTitle);
            std::cout << "Enter Category Description: ";
            std::getline(std::cin, categoryDesc);

            Category category(categoryTitle, categoryDesc);
            Book book(id, isbn, title, authors, quantity, category);

            bookManager.addNewBook(book);
            std::cout << "Book added successfully!\n";
            pause();
        }

        else if (choice == 2) {
            std::vector<Book> books = bookManager.getAllBooks();
            if (books.empty()) {
                std::cout << "No books available.\n";
            } else {
                for (const auto& book : books) {
                    std::cout << "\nID: " << book.getId()
                              << "\nTitle: " << book.getTitle()
                              << "\nAuthors: ";
                    for (const auto& a : book.getAuthors())
                        std::cout << a << ", ";
                    std::cout << "\nQuantity: " << book.getQuantity()
                              << "\nCategory: " << book.getCategory().getTitle() << "\n";
                }
            }
            pause();
        }

        else if (choice == 3) {
            int id;
            std::string name, email;

            std::cout << "Enter Member ID: ";
            std::cin >> id;
            std::cin.ignore();

            std::cout << "Enter Name: ";
            std::getline(std::cin, name);

            std::cout << "Enter Email: ";
            std::getline(std::cin, email);

            Member member(id, name, email);
            memberManager.addMember(member);
            std::cout << "Member added successfully!\n";
            pause();
        }

        else if (choice == 4) {
            std::vector<Member> members = memberManager.getAllMembers();
            if (members.empty()) {
                std::cout << "No members found.\n";
            } else {
                for (const auto& member : members) {
                    std::cout << "\nID: " << member.getId()
                              << "\nName: " << member.getName()
                              << "\nEmail: " << member.getEmail() << "\n";
                }
            }
            pause();
        }

        else if (choice == 5) {
            int memberId, bookId;
            std::cout << "Enter Member ID: ";
            std::cin >> memberId;
            std::cout << "Enter Book ID: ";
            std::cin >> bookId;

            std::vector<Book> books = bookManager.getAllBooks();
            bool result = borrowingSystem.borrowBook(bookId, memberId, books);
            if (result) {
                std::cout << "Book borrowed successfully!\n";
                bookManager = BookManagement();  // Refresh book manager with updated books
                for (const auto& book : books)
                    bookManager.addNewBook(book);
            } else {
                std::cout << "Borrowing failed (book unavailable or not found).\n";
            }
            pause();
        }

        else if (choice == 6) {
            int memberId, bookId;
            std::cout << "Enter Member ID: ";
            std::cin >> memberId;
            std::cout << "Enter Book ID: ";
            std::cin >> bookId;

            bool result = borrowingSystem.returnBook(bookId, memberId);
            if (result)
                std::cout << "Book returned successfully!\n";
            else
                std::cout << "Return failed (not found).\n";
            pause();
        }

        else if (choice == 7) {
            std::cout << "Exiting the system. Goodbye!\n";
            break;
        }

        else {
            std::cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}
