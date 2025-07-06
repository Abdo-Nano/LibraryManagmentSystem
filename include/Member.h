//
// Created by abdo on 7/6/25.
//

#ifndef MEMBER_H
#define MEMBER_H

#include <string>

class Member {
private:
    int id;
    std::string name;
    std::string email;

public:
    Member(int id, const std::string& name, const std::string& email);

    int getId() const;
    std::string getName() const;
    std::string getEmail() const;

    void setName(const std::string& name);
    void setEmail(const std::string& email);
};

#endif
