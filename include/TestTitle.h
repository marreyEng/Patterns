#ifndef TEST_TITLE_H
#define TEST_TITLE_H

#include <string>

struct Title{
    Title(const std::string& _name);
    ~Title();

    std::string name;
    int result;
};


#endif