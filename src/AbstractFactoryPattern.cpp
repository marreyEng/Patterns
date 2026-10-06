#include <TestTitle.h>
#include <AbstractFactoryPattern.h>
#include <memory>

void ProductA1::BeUsed() const {
    std::cout << "Product A1 is used" << std::endl;
}
void ProductB1::BeUsed() const {
    std::cout << "Product B1 is used" << std::endl;
}
void ProductA2::BeUsed() const {
    std::cout << "Product A2 is used" << std::endl;
}
void ProductB2::BeUsed() const {
    std::cout << "Product B2 is used" << std::endl;
}
std::shared_ptr<AbstractProduct> FactoryA::CreateProduct1() const {
    return std::make_shared<ProductA1>();
}
std::shared_ptr<AbstractProduct> FactoryA::CreateProduct2() const {
    return std::make_shared<ProductA2>();
}
std::shared_ptr<AbstractProduct> FactoryB::CreateProduct1() const {
    return std::make_shared<ProductB1>();
}
std::shared_ptr<AbstractProduct> FactoryB::CreateProduct2() const {
    return std::make_shared<ProductB2>();
}

void Client::SetFactory(std::shared_ptr<AbstractFactory> _factory){
    factory = std::move(_factory);
}
void Client::CreateProduct(){
    product1 = factory->CreateProduct1();
    product2 = factory->CreateProduct2();
}
void Client::UseProduct() const{
    product1->BeUsed();
    product2->BeUsed();
}
void Client::Run(){
    CreateProduct();
    UseProduct();
}

int AbstractFactoryPattern(){
    Title title(__func__);
    
    auto a = std::make_shared<FactoryA>();
    auto b = std::make_shared<FactoryB>();

    Client client;
    client.SetFactory(a);
    client.Run();

    client.SetFactory(b);
    client.Run();

    return -42;
}