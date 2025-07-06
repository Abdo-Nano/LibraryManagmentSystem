//
// Created by abdo on 7/6/25.
//

#include "../include/Member.h"

Member::Member(int id, const std::string& name, const std::string& email)
    : id(id), name(name), email(email) {}

int Member::getId() const { return id; }
std::string Member::getName() const { return name; }
std::string Member::getEmail() const { return email; }

void Member::setName(const std::string& name) { this->name = name; }
void Member::setEmail(const std::string& email) { this->email = email; }
