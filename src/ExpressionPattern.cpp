#include <ExpressionPattern.h>
#include <TestTitle.h>

#include <iostream>
#include <iomanip>

auto createExpression(){
    float A = 1;
    float B = 1;
    float C = 1;
    auto a = Expr<float>(A);
    auto b = Expr<float>(B);
    auto c = Expr<float>(C);
    auto x = Expr<float>::CreateVariable();

    return a * x + b;
}

int ExpressionPattern(){
    Title t{__func__};

    auto f = createExpression();
    std::cout << f.eval(1);
    return -42;
}
