#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include "BookBST.h"

class Library {
    std::unordered_map<std::string, std::vector<Book>> catalogs;
    BookBST bookInventory;
    std::queue<int> requestQueue;
    std::stack<int> returnStack;

    public:
        Library();

        void addBook(const Book& book);
        void issueBook(int bookId);
        std::vector<Book*> searchBookTitle(const std::string& title);
        void displayBooksByGenre(const std::string& genre);
        void displayBooks();
};

#endif // LIBRARY_H
