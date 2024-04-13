// #include "Book.h"


// Book::Book(int id, std::string title, std::string author, std::string genre, std::string publisher, std::string ISBN, int count) :
//     id(id), title(title), author(author), genre(genre), publisher(publisher), ISBN(ISBN), count(count), isCheckedOut(false) {}

// bool Book::operator <(const Book& other) const {
//     return id < other.id;
// }

#include "Book.h"

// Initialize the static member `lastId`
int Book::lastId = 0;

Book::Book(const std::string& title, const std::string& author,
           const std::string& genre, const std::string& publisher,
           const std::string& ISBN, int additional_count)
    : title(title), author(author), genre(genre),
      publisher(publisher), ISBN(ISBN), count(additional_count),
      issue(0), total(additional_count), isCheckedOut(false) {
    id = ++lastId;  // Increment and assign the next ID
}

bool Book::operator<(const Book& other) const {
    return title < other.title;
}

int Book::getId() const {
    return id;
}

int Book::getCount() const {
    return count;
}

int Book::getIssue() const {
    return issue;
}

int Book::getTotal() const {
    return total;
}

void Book::addBooks(int additional_count) {
    count += additional_count;
    total += additional_count;
}

void Book::returnBook()
{
    count++;
}

void Book::issueBook() {
    if (count > 0) {  // Only issue a book if there are available copies
        updateIssue();  // Update the issue count privately
        count--;
    }
    if (count == 0)
    {
        isCheckedOut = true;
    }    
}

void Book::updateIssue() {
    issue++;
}
