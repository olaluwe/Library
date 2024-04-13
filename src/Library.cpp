#include "Library.h"

Library::Library() {}

void Library::addBook(const Book& book) 
{
    bookInventory.insert(book);
    catalogs[book.genre].push_back(book);  // Assuming catalogs is a map from string to vector of Book pointers
}

void Library::issueBook(const std::string& title) {
    for (auto& catalog : catalogs) { // Loop through all genres
        for (Book& book : catalog.second) { // Loop through books in each genre
            if (book.title == title) { // Check for the title and if it's not already issued
                book.issueBook(); // Mark the book as issued
                std::cout << "Book issued: " << book.title << " by " << book.author << std::endl;
                return; // Exit the function once the book is issued
            }
        }
    }
    std::cout << "Book not found or already issued." << std::endl; // No book found or all copies issued
}

void Library::returnBook(const std::string& isbn, const std::string& genre) 
{
    // Iterate over a reference to a vector of Book pointers
    auto iter = catalogs.find(genre);
    if (iter != catalogs.end())
    {
        for (auto book : iter->second)
        {
            if (book.ISBN == isbn)
            {
                book.returnBook();
            }
        }
    }
}

std::vector<std::unordered_map<std::string, Book>> Library::searchBookTitle(const std::string& title) {
    // Iterate over a reference to a vector of Book pointers
    std::unordered_map<std::string, Book> foundBooksByCatalog;
    std::vector<std::unordered_map<std::string, Book>> result;
    for (const auto& pair : catalogs)
    {
        std::cout << "Genre: " << pair.first << std::endl;
        for (auto book : pair.second) 
        {
            if (book.title == title) 
            {  // Check for nullptr and matching title
                foundBooksByCatalog[pair.first] = book;  // save the first matching book found in that genre
                result.push_back(foundBooksByCatalog);
            }
        }
    }
    if (!result.empty())
    {
        return result;
    }
    std::cout << "Title: " << title << " not found!" << std::endl;
    return std::vector<std::unordered_map<std::string, Book>>();  // Return if no matching book is found
}

Book Library::searchBookTitleByGenre(const std::string& title, const std::string& genre) {
    // Check if the genre exists in the map
    auto iter = catalogs.find(genre);
    if (iter != catalogs.end()) {
        // Iterate over the vector of Books within the found genre
        for (const auto& book : iter->second) {
            if (book.title == title) {
                return book;  // Return the first matching book found
            }
        }
    }

    std::cout << "Book with title: '" << title << "' not found in genre: '" << genre << "'." << std::endl;
    return Book();  // Return a default (empty) book if no matching book is found
}

void Library::displayBooksByGenre(const std::string& genre) {
    // Assuming catalogs contains the books categorized by genre
    auto iter = catalogs.find(genre);
    if (iter != catalogs.end()) {
        for (auto book : iter->second) {
            std::cout << "Title: " << book.title;
            std::cout << ", Author: " << book.author;
            std::cout << ", Publisher: " << book.publisher;
            std::cout << ", ISBN: " << book.ISBN;
            std::cout << ", Stock: " << book.getCount() << std::endl;
        }
    }
}

void Library::displayBooks() {
    // Placeholder for displaying all books
    for (const auto& pair : catalogs) {
        std::cout << "Genre: " << pair.first << std::endl;
        for (auto book : pair.second) {
            std::cout << "Title: " << book.title;
            std::cout << ", Author: " << book.author;
            std::cout << ", Publisher: " << book.publisher;
            std::cout << ", ISBN: " << book.ISBN;
            std::cout << ", Stock: " << book.getCount() << std::endl;
        }
    }
}
