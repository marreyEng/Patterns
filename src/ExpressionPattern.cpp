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

    return a * x *x + b * x + c;
}

int ExpressionPattern(){
    Title t{__func__};

    auto f = createExpression();
    for(float x = 0.f; x < 10.f; x += 0.2){
        std::cout << "f(" << x << ") = " << f.eval(x) <<std::endl;
    }
    return -42;
}
