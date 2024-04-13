#ifndef BOOK_BST_H
#define BOOK_BST_H

#include "Book.h" // Make sure this path is correct based on your project structure

// Forward declaration of BSTNode to resolve circular dependency
struct BSTNode;

// Node structure for a Binary Search Tree
struct BSTNode {
    Book book;
    BSTNode* left;
    BSTNode* right;

    explicit BSTNode(Book book);
};

// Define a class for the Binary Search Tree for efficient book lookups
class BookBST {
    BSTNode* root;

    public:
        BookBST();
        ~BookBST(); // Destructor to deallocate nodes
        BookBST(const BookBST&) = delete; // Prevent copy construction
        BookBST& operator=(const BookBST&) = delete; // Prevent assignment

        // Member functions
        void insert(const Book& book);

        // You may also want to provide functions to remove a book, search for a book, etc.
        // ...

    private:
        // Helper functions
        BSTNode* insertHelper(BSTNode* node, const Book& book);
        void clear(BSTNode* node);

        // Add other helper functions as needed for searching, traversal, etc.
        // ...
};

#endif // BOOK_BST_H
