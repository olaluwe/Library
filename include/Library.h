#ifndef LIBRARY_H
#define LIBRARY_H

#include "BookBST.h"

class Library {
    std::unordered_map<std::string, std::vector<Book>> catalogs;
    BookBST bookInventory;
    std::queue<int> requestQueue;
    std::stack<int> returnStack;

    public:
        Library();

        void addBook(const Book&);
        void issueBook(const std::string&);
        std::vector<std::unordered_map<std::string, Book>> searchBookTitle(const std::string&);
        Book searchBookTitleByGenre(const std::string &, const std::string &);
        void returnBook(const std::string &, const std::string &);
        void displayBooksByGenre(const std::string&);
        void displayBooks();
};

#endif // LIBRARY_H
