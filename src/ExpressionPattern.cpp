#include <ExpressionPattern.h>
#include <TestTitle.h>

#include <iostream>
#include <iomanip>

auto createExpression(){
    const float A = 1;
    const float B = 1;
    const float C = 1;
    const auto a = Constant<float>(A);
    const auto b = Constant<float>(B);
    const auto c = Constant<float>(C);
    const auto x = Variable<float>();

    auto f = a * x + b;

    return f;
}

int ExpressionPattern(){
    Title t{__func__};

    auto f = createExpression();
    for(float x = 0.f; x<10.0; x += 1.f){
    std::cout << std::setprecision(23);
        std::cout << "f(" << x << "): " << f.eval(x) <<std::endl;
    }
    return -42;
}
