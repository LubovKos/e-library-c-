#include "author.h"
#include <sstream>
#include <iomanip>
using namespace std;

tm Author::parseDate(const string& date) const {
    tm tm = {};
    stringstream ss(date);
    ss >> get_time(&tm, "%d.%m.%Y");
    if (ss.fail()) {
        throw invalid_argument("Invalid date format: " + date);
    }
    return tm;
}

bool Author::isDateBefore(const tm& date1, const tm& date2) const {
    time_t t1 = mktime(const_cast<tm*>(&date1));
    time_t t2 = mktime(const_cast<tm*>(&date2));
    return t1 < t2;
}

void Author::validate() const {
    if (full_name.empty()) {
        throw invalid_argument("Author's name cannot be empty");
    }

    tm birth_tm = {};
    tm death_tm = {};
    bool has_birth = !date_of_birth.empty();
    bool has_death = !date_of_death.empty();

    if (has_birth) {
        birth_tm = parseDate(date_of_birth);
    }
    if (has_death) {
        death_tm = parseDate(date_of_death);
    }

    if (has_birth && has_death) {
        if (isDateBefore(death_tm, birth_tm)) {
            throw invalid_argument("Date of death cannot be earlier than date of birth");
        }
    }

    time_t now = time(nullptr);
    tm current_tm = *localtime(&now);

    if (has_birth && isDateBefore(current_tm, birth_tm)) {
        throw invalid_argument("Date of birth cannot be in the future");
    }
    if (has_death && isDateBefore(current_tm, death_tm)) {
        throw invalid_argument("Date of death cannot be in the future");
    }
}
Author::Author(const string& full_name, const string& date_of_birth,
    const string& date_of_death, const string& biography)
    : full_name(full_name), biography(biography),
    date_of_birth(date_of_birth), date_of_death(date_of_death) {
    validate();
}

string Author::getFullName() const { return full_name; }
string Author::getBiography() const { return biography; }
string Author::getDateOfBirth() const { return date_of_birth; }
string Author::getDateOfDeath() const { return date_of_death; }