#ifndef EXPRESSION_PATTERN_H
#define EXPRESSION_PATTERN_H

//Basically composite pattern

struct Expression{
    virtual ~Expression(){};
    virtual float eval(float x) = 0;
};

struct Constant : public Expression{
    const float d;
    Constant(float dd)
    : d{dd}
    {}
    virtual float eval(float x) override{
        return d;
    }
};

struct Variable : public Expression{
    virtual float eval(float x) override {
        return x;
    }
};

struct BinarySum : public Expression{
    Expression* lhs{};
    Expression* rhs{};

    BinarySum(Expression* l, Expression* r)
    : lhs{l}
    , rhs{r}
    {}

    ~BinarySum(){
        delete lhs;
        delete rhs;
    }

    virtual float eval(float x) override{
        return lhs->eval(x) + rhs->eval(x);
    }
};

struct BinaryMul : public Expression{
    Expression* lhs{};
    Expression* rhs{};

    BinaryMul(Expression* l, Expression* r)
    : lhs{l}
    , rhs{r}
    {}

    ~BinaryMul(){
        delete lhs;
        delete rhs;
    }

    virtual float eval(float x) override{
        return lhs->eval(x) * rhs->eval(x);
    }
};

Expression* Add(Expression* lhs, Expression* rhs){
    return new BinarySum(lhs, rhs);
}
Expression* Mul(Expression* lhs, Expression* rhs){
    return new BinaryMul(lhs, rhs);
}

int ExpressionPattern();
#endif