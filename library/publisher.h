#ifndef PUBLISHER_H
#define PUBLISHER_H

#include <string>
#include <stdexcept>

class Publisher {
private:
    int id;
    std::string name;
    std::string address;
    std::string phone;
    std::string mail;

    void validate() const;

public:
    Publisher(int id, const std::string& name, const std::string& address,
        const std::string& phone, const std::string& mail);

    int getId() const;
    std::string getName() const;
    std::string getAddress() const;
    std::string getPhone() const;
    std::string getMail() const;
};

#endif