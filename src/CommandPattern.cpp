#include <iostream>
#include <CommandPattern.h>

int SayHello::Execute() const {
    std::cout << "Hello" << std::endl;
    return 0;
}
int SayBye::Execute() const {
    std::cout << "Bye" << std::endl;
    return 0;
}

int useCommand(const Command& command){
    command.Execute();
    return 0;
}

int CommandPattern(){
    SayHello a;
    SayBye b;

    useCommand(a);
    useCommand(b);

    return 0;
}