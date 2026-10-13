#ifndef EXPRESSION_PATTERN_H
#define EXPRESSION_PATTERN_H

//Basically composite pattern
#include <utility>

template<typename T>
struct Expression{
    virtual ~Expression(){}
    virtual T eval(const T& x) const = 0;
    virtual Expression<T>* clone() const = 0;
};

template<typename T>
struct Constant : public Expression<T>{
    const T value;

    Constant(const T& value_)
    : value{value_}
    {}
    Constant(const Constant&) = default;
    Constant(Constant&&) noexcept = default;

    virtual T eval(const T& x) const override {
        return value;
    }
    virtual Expression<T>* clone() const override {
        return new Constant(*this);
    }
};

template<typename T>
struct Variable : public Expression<T>{
    virtual T eval(const T& x) const override {
        return x;
    }
    Variable() = default;
    Variable(const Variable&) = default;
    Variable(Variable&&) noexcept = default;

    virtual Expression<T>* clone() const override {
        return new Variable(*this);
    }
};

struct Add{
    static auto eval(const auto& lhs, const auto& rhs){
        return lhs + rhs;
    }
};
struct Sub{
    static auto eval(const auto& lhs, const auto& rhs){
        return lhs - rhs;
    }
};
struct Mul{
    static auto eval(const auto& lhs, const auto& rhs){
        return lhs * rhs;
    }
};
struct Div{
    static auto eval(const auto& lhs, const auto& rhs){
        return lhs / rhs;
    }
};

template<typename T, typename Op>
struct Binary : public Expression<T>{
    Expression<T>* lhs{};
    Expression<T>* rhs{};

    Binary(Expression<T>* l, Expression<T>* r)
    : lhs{l}, rhs{r}
    {}
    Binary(const Binary& other)
    {
        lhs = other.clone();
        rhs = other.clone();
    }
    Binary(Binary&& other) noexcept
    {
        std::swap(lhs, other.lhs);
        std::swap(rhs, other.rhs);
    }
    ~Binary(){
        delete lhs;
        delete rhs;
    }

    virtual T eval(const T& x) const override {
        return Op::eval(lhs->eval(x), rhs->eval(x));
    }

    virtual Expression<T>* clone() const override {
        return new Binary(lhs->clone(), rhs->clone());
    }
};

template<typename T>
auto operator+(const Expression<T>& lhs, const Expression<T>& rhs){
    return Binary<T,Add>(lhs.clone(), rhs.clone());
}
template<typename T>
auto operator-(const Expression<T>& lhs, const Expression<T>& rhs){
    return Binary<T,Sub>(lhs.clone(), rhs.clone());
}
template<typename T>
auto operator*(const Expression<T>& lhs, const Expression<T>& rhs){
    return Binary<T,Mul>(lhs.clone(), rhs.clone());
}
template<typename T>
auto operator/(const Expression<T>& lhs, const Expression<T>& rhs){
    return Binary<T,Div>(lhs.clone(), rhs.clone());
}


int ExpressionPattern();
#endif