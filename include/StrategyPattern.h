#ifndef STRATEGY_PATTERN_H
#define STRATEGY_PATTERN_H

struct Iterative{
    static int power(int base, int exp);
};

struct Recursive{
    static int power(int base, int exp);
};

int StrategyPattern();

#endif