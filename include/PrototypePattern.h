#ifndef PROTORTYPE_H
#define PROTORTYPE_H
#include <string>
#include <memory>

struct Prototype{
    virtual std::shared_ptr<Prototype> Clone() const = 0;
    virtual ~Prototype() = default;
};

struct Object : public Prototype{
    int id;
    std::string name;
    Object(int id, const std::string _name);
    Object(const Object&);

    std::shared_ptr<Prototype> Clone() const override;
    ~Object() override;
};

template<typename T, typename = decltype(std::declval<T>().Clone())>
struct PrototypeFactory{
    std::unique_ptr<T> proto;
    template<typename... Us>
    PrototypeFactory(Us&&... args)
    : proto{std::make_unique<T>(std::forward<Us>(args)...)}
    {}

    std::shared_ptr<Prototype> Create() const {
        auto o = proto->Clone();
        Object* ptr = static_cast<T*>(o.get());
        ptr->name = std::string("CopyOf") + ptr->name;
        return o;
    }
};

int PrototypePattern();

#endif