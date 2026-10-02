#include <StrategyPattern.h>

int Iterative::power(int base, int exp){
    for(int i = 0; i < exp;++i){
        base *= base;
    }
    return base;
}

int Recursive::power(int base, int exp){
    return exp == 0 ? 1 : base * power(base, exp-1);
}

enum class Type{
    Iterative,
    Recursive,
};

int Power(int base, int exp, Type type){
    switch(type){
        case Type::Iterative:
            return Iterative::power(base, exp);
        case Type::Recursive:
            return Recursive::power(base, exp);
        default:
            return {};
    }
}

int StrategyPattern(){
    if(Power(2, 8, Type::Iterative) == Power(2, 8, Type::Recursive)){
        return 0;
    }
    return -42;
}