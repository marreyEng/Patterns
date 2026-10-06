#include <iostream>
#include <TestTitle.h>
#include <CommandPattern.h>

int SayHello::Execute(const int& arg) const {
    return arg * 2;
}
int SayBye::Execute(const int& arg) const {
    return arg + arg;
}

int useCommand(const Command& command, const int& arg){
    return command.Execute(arg);
}

int CommandPattern(){
    Title title(__func__);
    SayHello a;
    SayBye b;

    if(useCommand(a,1) == useCommand(b,1)){
        return 0;
    }

    return -42;
}