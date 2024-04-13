#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book 
{
    public:
        int id;
        std::string title;
        std::string author;
        std::string genre;
        std::string publisher;
        std::string ISBN;
        int count;
        bool isCheckedOut;

        Book(int id, std::string title, std::string author, std::string genre, std::string publisher, std::string ISBN, int count);

        bool operator <(const Book& other) const;
};

#endif // BOOK_H