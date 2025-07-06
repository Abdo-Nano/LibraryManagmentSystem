//
// Created by abdo on 7/6/25.
//

#include "../include/Category.h"

Category::Category(const std::string& title, const std::string& description)
    : title(title), description(description) {}

std::string Category::getTitle() const { return title; }
std::string Category::getDescription() const { return description; }