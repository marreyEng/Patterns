#include <ExpressionPattern.h>
#include <TestTitle.h>

#include <iostream>

int ExpressionPattern(){
    Title t{__func__};
    auto a = new Constant(2);
    auto b = new Variable();
    auto c = new Constant(1);

    /// = a*(b+c)
    auto bc = Add(b,c);
    auto z = Mul(a, bc);

    // z = 2 * (x + 1)
    std::cout << z->eval(42);

    delete z;
    return -42;
}