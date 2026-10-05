#include <AdaptorPattern.h>
#include <iostream>

void Adaptor::print() const {
    for(const auto& d : m_adaptee->data){
        std::cout << d;
    }
    std::cout << std::endl;
}

void use(const IFace& impl){
    impl.print();
}

int AdaptorPattern(){
    Adaptee adaptee;

    Adaptor adaptor(&adaptee);

    use(adaptor);

    return -42;
}
