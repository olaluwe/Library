#include "BookBST.h"
#include <utility> // For std::move

// BSTNode constructor implementation
BSTNode::BSTNode(Book book) : book(std::move(book)), left(nullptr), right(nullptr) {}

// BookBST constructor
BookBST::BookBST() : root(nullptr) {}

// BookBST destructor
BookBST::~BookBST() 
{
    clear(root);
}

// insertHelper private member function
BSTNode* BookBST::insertHelper(BSTNode* node, const Book& book) 
{
    if (!node) {
        return new BSTNode(book);
    }

    // Assume that the Book class has a valid operator< for comparison
    if (book < node->book) {
        node->left = insertHelper(node->left, book);
    } else {
        node->right = insertHelper(node->right, book);
    }

    return node;
}

// clear helper function for destructor
void BookBST::clear(BSTNode* node) 
{
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

// Public insert function
void BookBST::insert(const Book& book) 
{
    root = insertHelper(root, book);
}

// Additional member functions (search, traversal, etc.) should also be implemented
