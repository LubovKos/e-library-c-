#ifndef READER_H
#define READER_H

#include <string>
#include <stdexcept>

class Reader {
private:
    std::string name;
    std::string phone;
    std::string mail;

    void validate() const;

public:
    Reader(const std::string& name, const std::string& phone, const std::string& mail);

    std::string getName() const;
    std::string getPhone() const;
    std::string getMail() const;
};

#endif