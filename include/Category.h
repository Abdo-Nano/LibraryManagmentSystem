//
// Created by abdo on 7/6/25.
//

#ifndef CATEGORY_H
#define CATEGORY_H



#include <string>

class Category {
private:
    std::string title;
    std::string description;

public:
    Category(const std::string& title = "", const std::string& description = "");

    std::string getTitle() const;
    std::string getDescription() const;
};

#endif //CATEGORY_H
