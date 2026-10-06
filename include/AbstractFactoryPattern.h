#ifndef ABSRACT_FACTORY_PATTERN_H
#define ABSRACT_FACTORY_PATTERN_H
#include <memory>
#include <iostream>

struct Product{
    virtual void BeUsed() const = 0;
};

struct Chair : public Product{
};
struct Table: public Product{
};

struct ModernChair : public Chair{
    void BeUsed() const override;
};
struct ModernTable : public Table{
    void BeUsed() const override;
};
struct VintageChair : public Chair{
    void BeUsed() const override;
};
struct VintageTable : public Table{
    void BeUsed() const override;
};

struct AbstractFactory{
    virtual std::shared_ptr<Chair> CreateChair() const = 0;
    virtual std::shared_ptr<Table> CreateTable() const = 0;
};
struct ModernFactory : public AbstractFactory{
    std::shared_ptr<Chair> CreateChair() const override;
    std::shared_ptr<Table> CreateTable() const override;
};
struct VintageFactory : public AbstractFactory{
    std::shared_ptr<Chair> CreateChair() const override;
    std::shared_ptr<Table> CreateTable() const override;
};

struct Client{
    std::shared_ptr<AbstractFactory> factory{};
    std::shared_ptr<Chair> chair{};
    std::shared_ptr<Table> table{};

    Client() = default;

    void SetFactory(std::shared_ptr<AbstractFactory> factory);
    void CreateProduct();
    void UseProduct() const;
    void Run();
};

int AbstractFactoryPattern();

#endif