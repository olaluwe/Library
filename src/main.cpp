#include "Library.h"
#include "Miscellaneous.h"
#include <iostream>
#include <Constants.h>

int main() {
    // Create a library instance and add books to it
    Library myLibrary;

    // Add books to the library
    myLibrary.addBook(Book(1, "The C++ Programming Language", "Bjarne Stroustrup", "Programming", "Publisher1", "ISBN1", 5));
    myLibrary.addBook(Book(2, "Effective Modern C++", "Scott Meyers", "Programming", "Publisher2", "ISBN2", 3));
    myLibrary.addBook(Book(3, "Pride and Prejudice", "Jane Austen", "Fiction", "Publisher3", "ISBN3", 7));
    // ... add more books as needed

    // Perform other library operations like handling requests, returns, etc.
    // ...

    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <limits>
#include "Library.h"
#include "Constants.h"
#include "Miscellaneous.h"

using namespace std;

int main()
{
    Miscellaneous misc;
    Constants constants;
    int choice, id, count;
    char response;
    bool validInput = false;
    std::string title, author, publisher, ISBN, genre;
    Library myLibrary;
    while (!validInput)
    {
        std::cout << "MENU OPTIONS:" << std::endl;
        std::cout << "1. Add New Book" << std::endl;
        std::cout << "2. Search Book" << std::endl;
        std::cout << "3. Issue Book" << std::endl;
        std::cout << "4. Return Book" << std::endl;
        std::cout << "5. Display Book Records" << std::endl;
        std::cout << "6. Exit" << std::endl;
        choice = misc.getValidInt("Enter your choice: ", constants.MIN_VALUE, constants.MAX_VALUE);
        switch (choice)
        {
        case 1:
        {
          id = misc.getValidInt("Enter Id: ");
          title = misc.getValidString("Enter Title: ");
          author = misc.getValidString("Enter Author: ");
          publisher = misc.getValidString("Enter Publisher: ");
          ISBN = misc.getValidString("Enter ISBN: ");
          genre = misc.getValidString("Enter the genre: ");
          count++;
          Book book(id, title, author, genre, publisher, ISBN, count);
          myLibrary.addBook(book);
          std::cout << "Book added successfully." << std::endl;
          break;
        }
        case 2:
        {
            const std::string titleToSearch = misc.getValidString("Enter Title to search: ");
            std::vector<Book*> bookResults = myLibrary.searchBookTitle(titleToSearch);

            if (bookResults.empty()) {
                std::cout << "Book not found.\n";
            } else {
                std::cout << "Search results:\n";
                for (auto* book : bookResults) {
                    if (book) { // Implicit check for nullptr
                        std::cout << "Title: " << book->title << ", Author: " << book->author << '\n';
                    }
                }
            }
            break;
        }
        case 3:
        {
            const std::string titleToIssue = misc.getValidString("Enter Title of book to issue: ");
            myLibrary.issueBook(titleToIssue);
            break;
        }
        case 4:
        {
            std::string titleToReturn = misc.getValidString("Enter Title of book to return: ");
            catalog.returnBook(titleToReturn);
            break;
        }
        case 5:
        {
            std::cout << "Book src/miscellaneous.cppRecords:" << std::endl;
            catalog.displayBooks();
            break;
        }
        case 6:
        {
            std::cout << "Exiting program." << std::endl;
            return 0;
        }
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
        const std::vector<char> Response = constants.validResponse;
        response = misc.getValidChar("Do you want to continue (Enter 'n|N' for No 'y|Y' for Yes): ", Response);
        validInput = (response == 'N');
    }
    return 0;
}
