#ifndef ABSRACT_FACTORY_PATTERN_H
#define ABSRACT_FACTORY_PATTERN_H
#include <memory>
#include <iostream>

struct AbstractProduct{
    virtual void BeUsed() const = 0;
};

struct ProductA : public AbstractProduct{
};
struct ProductB: public AbstractProduct{
};

struct ProductA1 : public ProductA{
    void BeUsed() const override;
};
struct ProductA2 : public ProductA{
    void BeUsed() const override;
};
struct ProductB1 : public ProductB{
    void BeUsed() const override;
};
struct ProductB2 : public ProductB{
    void BeUsed() const override;
};

struct AbstractFactory{
    virtual std::shared_ptr<AbstractProduct> CreateProduct1() const = 0;
    virtual std::shared_ptr<AbstractProduct> CreateProduct2() const = 0;
};
struct FactoryA : public AbstractFactory{
    std::shared_ptr<AbstractProduct> CreateProduct1() const override;
    std::shared_ptr<AbstractProduct> CreateProduct2() const override;
};
struct FactoryB : public AbstractFactory{
    std::shared_ptr<AbstractProduct> CreateProduct1() const override;
    std::shared_ptr<AbstractProduct> CreateProduct2() const override;
};

struct Client{
    std::shared_ptr<AbstractFactory> factory{};
    std::shared_ptr<AbstractProduct> product1{};
    std::shared_ptr<AbstractProduct> product2{};

    Client() = default;

    void SetFactory(std::shared_ptr<AbstractFactory> factory);
    void CreateProduct();
    void UseProduct() const;
    void Run();
};

int AbstractFactoryPattern();

#endif