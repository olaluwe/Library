// #ifndef BOOK_H
// #define BOOK_H

// #include <string>

// class Book 
// {
//     public:
//         std::string title;
//         std::string author;
//         std::string genre;
//         std::string publisher;
//         std::string ISBN;
//         bool isCompletelyCheckedOut;

//         Book(int id, std::string title, std::string author, std::string genre, std::string publisher, std::string ISBN, int count);

//         bool operator <(const Book& other) const;
    
//     private:
//         int id, count, issue, total;
// };

// #endif // BOOK_H

#ifndef BOOK_H
#define BOOK_H

#include "Include.h"

class Book {
public:
    // Public properties
    std::string title;
    std::string author;
    std::string genre;
    std::string publisher;
    std::string ISBN;

    // Default constructor
    Book() = default;
    // Constructor
    Book(const std::string& title, const std::string& author,
         const std::string& genre, const std::string& publisher,
         const std::string& ISBN, int additional_count = 0);

    // Comparison operator
    bool operator<(const Book& other) const;

    // Getter methods for private properties
    int getId() const;
    int getCount() const;
    int getIssue() const;
    int getTotal() const;

    // Methods to manage book inventory
    void addBooks(int additional_count);
    void returnBook();
    void issueBook();

    // Method to determine if the book is "empty"
    bool isEmpty() const {
        return title.empty() && author.empty() && genre.empty() && publisher.empty() && ISBN.empty();
    }

private:
    static int lastId; // Static member to remember the last ID
    int id;
    int count = 0;
    int issue = 0;
    int total = 0;
    bool isCheckedOut = false;

    // Private helper to update issue count
    void updateIssue();
};

#endif // BOOK_H
