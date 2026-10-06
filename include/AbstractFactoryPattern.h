#ifndef ABSRACT_FACTORY_PATTERN_H
#define ABSRACT_FACTORY_PATTERN_H
#include <memory>
#include <iostream>

struct AbstractProduct{
    virtual void BeUsed() const = 0;
};
struct ProductA : public AbstractProduct{
    void BeUsed() const override;
};
struct ProductB : public AbstractProduct{
    void BeUsed() const override;
};

struct AbstractFactory{
    virtual std::shared_ptr<AbstractProduct> Create() const = 0;
};
struct FactoryA : public AbstractFactory{
    std::shared_ptr<AbstractProduct> Create() const override;
};
struct FactoryB : public AbstractFactory{
    std::shared_ptr<AbstractProduct> Create() const override;
};

struct Client{
    std::shared_ptr<AbstractFactory> factory{};
    std::shared_ptr<AbstractProduct> product{};

    Client() = default;

    void SetFactory(std::shared_ptr<AbstractFactory> factory);
    void CreateProduct();
    void UseProduct() const;
    void Run();
};

int AbstractFactoryPattern();

#endif