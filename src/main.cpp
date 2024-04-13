#include "Library.h"
#include "Constants.h"
#include "Miscellaneous.h"

using namespace std;

int main()
{
    Miscellaneous misc;
    Constants constants;
    int choice, copies;
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
          title = misc.getValidString("Enter Title: ");
          author = misc.getValidString("Enter Author: ");
          publisher = misc.getValidString("Enter Publisher: ");
          ISBN = misc.getValidString("Enter ISBN: ");
          genre = misc.getValidString("Enter the genre: ");
          copies = misc.getValidInt("How many copies is being added: ");
          
          Book book(title, author, genre, publisher, ISBN, copies);
          book.addBooks(copies);
          myLibrary.addBook(book);
          std::cout << "Book added successfully." << std::endl;
          break;
        }
        case 2:
        {
            const std::string titleToSearch = misc.getValidString("Enter Title to search: ");
            genre = misc.getValidString("Enter the genre to search: ");
            Book bookResult = myLibrary.searchBookTitleByGenre(titleToSearch, genre);

            if (bookResult.isEmpty()) 
            {
                std::cout << "Book not found.\n";
            } 
            else 
            {
                std::cout << "Search results:\n";
                std::cout << "Title: " << bookResult.title << ", Author: " << bookResult.author << '\n';
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
            genre = misc.getValidString("Enter the genre: ");
            myLibrary.returnBook(titleToReturn, genre);
            break;
        }
        case 5:
        {
            std::cout << "Book src/miscellaneous.cppRecords:" << std::endl;
            myLibrary.displayBooks();
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
