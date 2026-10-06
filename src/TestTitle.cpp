#include <TestTitle.h>
#include <iostream>

Title::Title(const std::string& _name)
: name{_name}
{
    std::cout << "\nStarting Test: " << name << std::endl;
}
Title::~Title(){
    std::cout << "Finishin Test: " << name << " = ";
    if(result != -42)
        std::cout << "Ok\n";
    else
        std::cout << "Fail\n";

    std::cout << std::endl;
}
