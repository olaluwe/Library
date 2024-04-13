#ifndef BOOK_BST_H
#define BOOK_BST_H

#include "Book.h" // Ensure this path is correct based on your project structure

// Forward declaration of BSTNode to resolve circular dependency
struct BSTNode {
    Book book;
    BSTNode* left;
    BSTNode* right;

    // Declare the constructor, do not define it here
    explicit BSTNode(Book book);
};

// Define a class for the Binary Search Tree for efficient book lookups
class BookBST {
    BSTNode* root;

public:
    BookBST();
    ~BookBST(); // Destructor to deallocate nodes, should be defined in the .cpp file

    BookBST(const BookBST&) = delete; // Prevent copy construction
    BookBST& operator=(const BookBST&) = delete; // Prevent assignment

    // Member functions
    void insert(const Book& book);
    std::vector<Book*> search(const std::string& title); // Search for books by title and return a vector of pointers

private:
    // Helper functions
    BSTNode* insertHelper(BSTNode* node, const Book& book);
    void clear(BSTNode* node);
    void searchHelper(BSTNode* node, const std::string& title, std::vector<Book*>& results); // Helper for searching books
};

#endif // BOOK_BST_H
