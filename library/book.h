#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <stdexcept>
#include <ctime>

class Book {
private:
    int id;
    std::string title;
    std::string author;
    std::string description;
    int year;
    std::string genre;
    std::string publisher;
    int pages;

    void validate() const;

public:
    Book(int id, const std::string& title, const std::string& author,
        const std::string& description, int year, const std::string& genre,
        const std::string& publisher, int pages = 0);

    int getId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getDescription() const;
    int getYear() const;
    std::string getGenre() const;
    std::string getPublisher() const;
    int getPages() const;
};

#endif