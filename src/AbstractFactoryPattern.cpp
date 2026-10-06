#include <TestTitle.h>
#include <AbstractFactoryPattern.h>
#include <memory>

void ModernChair::BeUsed() const {
    std::cout << "Product A1 is used" << std::endl;
}
void VintageChair::BeUsed() const {
    std::cout << "Product B1 is used" << std::endl;
}
void ModernTable::BeUsed() const {
    std::cout << "Product A2 is used" << std::endl;
}
void VintageTable::BeUsed() const {
    std::cout << "Product B2 is used" << std::endl;
}
std::shared_ptr<Chair> ModernFactory::CreateChair() const {
    return std::make_shared<ModernChair>();
}
std::shared_ptr<Table> ModernFactory::CreateTable() const {
    return std::make_shared<ModernTable>();
}
std::shared_ptr<Chair> VintageFactory::CreateChair() const {
    return std::make_shared<VintageChair>();
}
std::shared_ptr<Table> VintageFactory::CreateTable() const {
    return std::make_shared<VintageTable>();
}

void Client::SetFactory(std::shared_ptr<AbstractFactory> _factory){
    factory = std::move(_factory);
}
void Client::CreateProduct(){
    chair = factory->CreateChair();
    table = factory->CreateTable();
}
void Client::UseProduct() const{
    chair->BeUsed();
    table->BeUsed();
}
void Client::Run(){
    CreateProduct();
    UseProduct();
}

int AbstractFactoryPattern(){
    Title title(__func__);
    
    auto a = std::make_shared<ModernFactory>();
    auto b = std::make_shared<VintageFactory>();

    Client client;
    client.SetFactory(a);
    client.Run();

    client.SetFactory(b);
    client.Run();

    return -42;
}