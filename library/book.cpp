#include "book.h"
#include <ctime>

void Book::validate() const {
    if (title.empty()) {
        throw std::invalid_argument("Book title must not be empty");
    }
    if (author.empty()) {
        throw std::invalid_argument("Author field must not be empty");
    }

    std::time_t now = std::time(nullptr);
    std::tm current_tm = *std::localtime(&now);
    int current_year = current_tm.tm_year + 1900;

    if (year > current_year) {
        throw std::invalid_argument("The year of publication cannot be in the future");
    }
}

Book::Book(int id, const std::string& title, const std::string& author,
    const std::string& description, int year, const std::string& genre,
    const std::string& publisher, int pages)
    : id(id), title(title), author(author), description(description),
    year(year), genre(genre), publisher(publisher), pages(pages) {
    validate();
}

int Book::getId() const { return id; }
std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
std::string Book::getDescription() const { return description; }
int Book::getYear() const { return year; }
std::string Book::getGenre() const { return genre; }
std::string Book::getPublisher() const { return publisher; }
int Book::getPages() const { return pages; }