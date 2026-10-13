#ifndef EXPRESSION_PATTERN_H
#define EXPRESSION_PATTERN_H

//Basically composite pattern
#include <utility>
#include <memory>

template<typename T>
struct Expression{
    virtual ~Expression() = default;
    virtual T eval(const T& x) const = 0;
    virtual std::unique_ptr<Expression<T>> clone() const = 0;
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
    virtual std::unique_ptr<Expression<T>> clone() const override {
        return std::make_unique<Constant>(*this);
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

    virtual std::unique_ptr<Expression<T>> clone() const override {
        return std::make_unique<Variable>(*this);
    }
};

struct Add{
    static auto eval(const auto& lhs, const auto& rhs){return lhs + rhs;}
};
struct Sub{
    static auto eval(const auto& lhs, const auto& rhs){return lhs - rhs;}
};
struct Mul{
    static auto eval(const auto& lhs, const auto& rhs){return lhs * rhs;}
};
struct Div{
    static auto eval(const auto& lhs, const auto& rhs){return lhs / rhs;}
};

template<typename T, typename Op>
struct Binary : public Expression<T>{
    std::unique_ptr<Expression<T>> lhs;
    std::unique_ptr<Expression<T>> rhs;

    Binary(std::unique_ptr<Expression<T>> l, std::unique_ptr<Expression<T>> r)
    : lhs{std::move(l)}, rhs{std::move(r)}
    {}
    Binary(const Binary& other)
    {
        lhs = other.lhs ? other.lhs->clone() : nullptr;
        rhs = other.rhs ? other.rhs->clone() : nullptr;
    }
    Binary(Binary&& other) noexcept = default;
    ~Binary(){}
    Binary& operator=(const Binary&) = delete;
    Binary& operator=(Binary&&) noexcept = default;

    virtual T eval(const T& x) const override {
        return Op::eval(lhs->eval(x), rhs->eval(x));
    }

    virtual std::unique_ptr<Expression<T>> clone() const override {
        return std::make_unique<Binary>(lhs->clone(), rhs->clone());
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