#pragma once
#ifndef AUTHOR_H
#define AUTHOR_H

#include <string>
#include <stdexcept>
#include <ctime>

class Author {
private:
    string full_name;
    string biography;
    string date_of_birth;
    string date_of_death;

    tm parseDate(const string& date) const;
    bool isDateBefore(const tm& date1, const tm& date2) const;
    void validate() const;

public:
    Author(const string& full_name, const string& date_of_birth = "",
        const string& date_of_death = "", const string& biography = "");

    string getFullName() const;
    string getBiography() const;
    string getDateOfBirth() const;
    string getDateOfDeath() const;
};

#endif