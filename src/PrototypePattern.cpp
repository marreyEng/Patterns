#include <PrototypePattern.h>
#include <TestTitle.h>
#include <iostream>

Object::Object(int _id, const std::string _name )
: id{id}
, name{_name}
{
    std::cout << "Object created\n";
}
Object::Object(const Object& other)
: id{other.id}
, name{other.name}
{
    std::cout << "Object copied\n";
}

std::shared_ptr<Prototype> Object::Clone() const {
    return std::make_shared<Object>(*this);
}
Object:: ~Object(){
    std::cout << "Object "<< name << " deleted\n";
}


int PrototypePattern(){
    Title title(__func__);

    PrototypeFactory<Object> factory(42, std::string("\"Prototype\""));
    auto p = factory.Create();

    return -42;
}