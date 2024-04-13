#include "Library.h"
#include "BookBST.h"

Library::Library() {}

void Library::addBook(const Book& book) 
{
    bookInventory.insert(book);
    catalogs[book.genre].push_back(book);
}

void Library::issueBook(int bookId) {
    // Implement logic to issue a book
}

std::vector<Book*> Library::searchBookTitle(const std::string& title) 
{
    std::vector<Book*> foundBooks;

    // Assuming you have some container (e.g., std::vector, std::list) storing your books
    // For example, if you store your books in a std::vector<Book> books;
    for (auto& book : books) {
        if (book.title == title) {
            foundBooks.push_back(&book); // Add the address of the book to foundBooks
        }
    }

    return foundBooks; // This will be empty if no books were found
}

void Library::displayBooksByGenre(const std::string& genre) 
{
    // Implement logic to display books by genre
}

void Library::displayBooks() 
{
    // Implement logic to display all books in the library
}
