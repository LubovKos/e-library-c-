#include "publisher.h"
#include <regex>

void Publisher::validate() const {
    if (name.empty()) {
        throw std::invalid_argument("Publisher name must not be empty");
    }

    std::regex email_pattern(R"(^\S+@\S+\.\S+$)");
    if (!std::regex_match(mail, email_pattern)) {
        throw std::invalid_argument("Incorrect mail");
    }
}

Publisher::Publisher(int id, const std::string& name, const std::string& address,
    const std::string& phone, const std::string& mail)
    : id(id), name(name), address(address), phone(phone), mail(mail) {
    validate();
}

int Publisher::getId() const { return id; }
std::string Publisher::getName() const { return name; }
std::string Publisher::getAddress() const { return address; }
std::string Publisher::getPhone() const { return phone; }
std::string Publisher::getMail() const { return mail; }