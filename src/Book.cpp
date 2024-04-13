#include "Book.h"


Book::Book(int id, std::string title, std::string author, std::string genre, std::string publisher, std::string ISBN, int count) :
    id(id), title(title), author(author), genre(genre), publisher(publisher), ISBN(ISBN), count(count), isCheckedOut(false) {}

bool Book::operator <(const Book& other) const {
    return id < other.id;
}
