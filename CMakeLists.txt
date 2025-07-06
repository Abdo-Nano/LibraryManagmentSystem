cmake_minimum_required(VERSION 3.31)
project(LibraryManagementSystem)

set(CMAKE_CXX_STANDARD 23)

add_executable(LibraryManagementSystem src/main.cpp
        src/Book.cpp
        include/Book.h
        src/Category.cpp
        include/Category.h
        src/Member.cpp
        include/Member.h
        src/BookManagement.cpp
        include/BookManagement.h
        src/MemberManagment.cpp
        include/MemberManagment.h
        src/BorrowingSystem.cpp
        include/BorrowingSystem.h)
