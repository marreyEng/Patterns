#ifndef ADAPTOR_PATTERN_H
#define ADAPTOR_PATTERN_H

#include <vector>

struct IFace{
    virtual void print() const = 0;
};

struct Adaptee{
    std::vector<unsigned char> data;
};

struct Adaptor : public IFace{
    Adaptee* m_adaptee;

    Adaptor(Adaptee* adaptee)
    : m_adaptee{adaptee}
    {}

    void print() const override;
};


int AdaptorPattern();

#endif