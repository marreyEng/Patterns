#include <TypeErasurePattern.h>
#include <TestTitle.h>

#include <iostream>
#include <vector>
#include <memory>

struct A{
    void a() const {
        std::cout << "A" << std::endl;
    }
};
struct B{
    void b() const {
        std::cout << "B" << std::endl;
    }
};
struct C{
    void c() const {
        std::cout << "C" << std::endl;
    }
};
struct D{
    void d() const {
        std::cout << "D" << std::endl;
    }
};

struct Iface{
    virtual ~Iface() = default;
    virtual void invoke() const = 0;
};

template<typename T>
struct Adaptor : public Iface{
    T m_object;

    template<typename U>
    explicit Adaptor(U&& object)
        : m_object(std::forward<U>(object))
    {}
    void invoke() const override;
};

template<>
void Adaptor<A>::invoke() const {
    m_object.a();
}
template<>
void Adaptor<B>::invoke() const {
    m_object.b();
}
template<>
void Adaptor<C>::invoke() const {
    m_object.c();
}
template<>
void Adaptor<D>::invoke() const {
    m_object.d();
}

struct Any{
    std::shared_ptr<Iface> ptr;

    template<typename T>
    Any(T&& object)
    : ptr{std::make_shared<Adaptor<T>>(std::forward<T>(object))}
    {}

    void invoke() const {
        ptr->invoke();
    }
};

int TypeErasurePattern(){
    Title title{__func__};

    std::vector<Any> vs;
    vs.push_back(A{});
    vs.push_back(B{});
    for(const auto& v : vs){
        v.invoke();
    }

    return -42;
}