#include "BookBST.h"

// Define the BSTNode constructor
BSTNode::BSTNode(Book book) : book(std::move(book)), left(nullptr), right(nullptr) {}

// Define the BookBST constructor
BookBST::BookBST() : root(nullptr) {}

// Define the destructor for BookBST
BookBST::~BookBST() {
    clear(root);
}

// Implement the clear method to deallocate all nodes
void BookBST::clear(BSTNode* node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

// Implement other member functions as needed
void BookBST::insert(const Book& book) {
    root = insertHelper(root, book);
}

BSTNode* BookBST::insertHelper(BSTNode* node, const Book& book) {
    // Implementation of BST insertion logic
    if (!node) return new BSTNode(book);
    // Further logic as necessary...
    return node;
}

std::vector<Book*> BookBST::search(const std::string& title) {
    std::vector<Book*> results;
    searchHelper(root, title, results);
    return results;
}

void BookBST::searchHelper(BSTNode* node, const std::string& title, std::vector<Book*>& results) {
    if (!node) return;  // Base case: node is nullptr

    // Check the current node's book title against the search title
    if (node->book.title == title) {
        results.push_back(&node->book);  // Add the address of the book to the results vector
    }

    // Recursively search in the left subtree
    searchHelper(node->left, title, results);

    // Recursively search in the right subtree
    searchHelper(node->right, title, results);
}
