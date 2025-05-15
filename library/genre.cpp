#include "genre.h"

using namespace std;

void Genre::validate() const {
    if (title.empty()) {
        throw invalid_argument("Genre title must not be empty");
    }
}

Genre::Genre(const string& title, const string& description)
    : title(title),description(description) {
    validate();
}


string Genre::getTitle() const { return title; }
string Genre::getDescription() const { return description; }
