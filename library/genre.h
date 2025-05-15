#pragma once
#ifndef GENRE_H
#define GENRE_H

#include <string>
#include <stdexcept>

class Genre {
private:
    std::string title;
    std::string description;
    void validate() const;

public:
    Genre(const std::string& title, 
        const std::string& description);

    std::string getTitle() const;
    std::string getDescription() const;
};

#endif