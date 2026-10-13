#ifndef EXPRESSION_PATTERN_H
#define EXPRESSION_PATTERN_H

//Basically composite pattern
#include <iostream>
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
    T value;
    Constant(T val) : value{val}
    {}

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
    : lhs{std::move(l)}
    , rhs{std::move(r)}
    {}
    Binary(const Binary& other)
       : lhs{other.lhs ? other.lhs->clone() : nullptr}
       , rhs{other.rhs ? other.rhs->clone() : nullptr}
    {}
    Binary(Binary&& other) noexcept = default;

    Binary& operator=(const Binary&) = delete;
    Binary& operator=(Binary&&) noexcept = default;

    virtual T eval(const T& x) const override {
        return Op::eval(lhs->eval(x), rhs->eval(x));
    }

    virtual std::unique_ptr<Expression<T>> clone() const override {
        return std::make_unique<Binary>(*this);
    }
};

template<typename T>
struct Expr{
    std::unique_ptr<Expression<T>> pimpl;

    Expr(T val)
    : pimpl{std::make_unique<Constant<T>>(val)}
    {}
    Expr(std::unique_ptr<Expression<T>> p)
    : pimpl{std::move(p)}
    {}

    Expr(const Expr& other)
    : pimpl{other.pimpl ? other.pimpl->clone() : nullptr}
    {}
    Expr(Expr&&) noexcept = default;
    Expr& operator=(const Expr& other) {
        if (this != &other) {
            pimpl = other.pimpl ? other.pimpl->clone() : nullptr;
        }
        return *this;
    }
    Expr& operator=(Expr&&) noexcept = default;
    
    static Expr CreateVariable() {
        return Expr(std::make_unique<Variable<T>>());
    }
    T eval(const T& x) const {
        return pimpl->eval(x);
    }
};

template<typename T>
Expr<T> operator+(const Expr<T>& lhs, const Expr<T>& rhs){
    return Expr<T>(std::make_unique<Binary<T,Add>>(lhs.pimpl->clone(), rhs.pimpl->clone()));
}
template<typename T>
Expr<T> operator-(const Expr<T>& lhs, const Expr<T>& rhs){
    return Expr<T>(std::make_unique<Binary<T,Sub>>(lhs.pimpl->clone(), rhs.pimpl->clone()));
}
template<typename T>
Expr<T> operator*(const Expr<T>& lhs, const Expr<T>& rhs){
    return Expr<T>(std::make_unique<Binary<T,Mul>>(lhs.pimpl->clone(), rhs.pimpl->clone()));
}
template<typename T>
Expr<T> operator/(const Expr<T>& lhs, const Expr<T>& rhs){
    return Expr<T>(std::make_unique<Binary<T,Div>>(lhs.pimpl->clone(), rhs.pimpl->clone()));
}

int ExpressionPattern();
#endif