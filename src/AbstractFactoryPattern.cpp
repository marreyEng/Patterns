#include <TestTitle.h>
#include <AbstractFactoryPattern.h>
#include <memory>

void ProductA::BeUsed() const {
    std::cout << "Product A is used" << std::endl;
}

void ProductB::BeUsed() const {
    std::cout << "Product B is used" << std::endl;
}
std::shared_ptr<AbstractProduct> FactoryA::Create() const {
    return std::make_shared<ProductA>();
}
std::shared_ptr<AbstractProduct> FactoryB::Create() const {
    return std::make_shared<ProductB>();
}

void Client::SetFactory(std::shared_ptr<AbstractFactory> _factory){
    factory = std::move(_factory);
}
void Client::CreateProduct(){
    product = factory->Create();
}
void Client::UseProduct() const{
    product->BeUsed();
}
void Client::Run(){
    CreateProduct();
    UseProduct();
}

int AbstractFactoryPattern(){
    Title title(__func__);
    
    auto a = std::make_shared<FactoryA>();
    auto b = std::make_shared<FactoryA>();

    Client client;
    client.SetFactory(a);
    client.Run();

    client.SetFactory(b);
    client.Run();

    return -42;
}