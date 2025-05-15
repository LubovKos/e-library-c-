#include "reader.h"
#include <regex>

void Reader::validate() const {
    if (name.empty()) {
        throw std::invalid_argument("Reader name must not be empty");
    }

    std::regex email_pattern(R"(^\S+@\S+\.\S+$)");
    if (!std::regex_match(mail, email_pattern)) {
        throw std::invalid_argument("Incorrect mail");
    }
}

Reader::Reader(const std::string& name, const std::string& phone, const std::string& mail)
    : name(name), phone(phone), mail(mail) {
    validate();
}

std::string Reader::getName() const { return name; }
std::string Reader::getPhone() const { return phone; }
std::string Reader::getMail() const { return mail; }