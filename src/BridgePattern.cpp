#include <BridgePattern.h>
#include <memory>
#include <iostream>
#include <array>
#include <TestTitle.h>

struct Point{
    float x,y;
};

struct Printer{
    enum Type{Raster, Vector};
    virtual std::string Square() = 0;
    virtual std::string Circle() = 0;
};
struct RasterPrinter : public Printer{
    virtual std::string Square() override{
        return {"MathFormulasForSquare..."};
    }
    virtual std::string Circle() override{
        return {"MathFormulasForCircle..."};
    }
};
struct VectorPrinter : public Printer{
    virtual std::string Square() override{
        return {"PixelsForSquare..."};
    }
    virtual std::string Circle() override{
        return {"PixelsForCircle..."};
    }
};

struct Shape{
    std::unique_ptr<Printer> printer;
    Shape(Printer* ptr)
    : printer{ptr}
    {}
    virtual void print() const = 0;
};
struct Square : public Shape{
    Point A,B,C,D;
    Square(Printer::Type type)
    : Shape(type == Printer::Raster ? static_cast<Printer*>(new RasterPrinter) : static_cast<Printer*>(new VectorPrinter))
    {}
    virtual void print() const override{
        std::cout << printer->Square() << std::endl;
    }
};
struct Circle : public Shape{
    Point C;
    float R;
    Circle(Printer::Type type)
    : Shape(type == Printer::Raster ? static_cast<Printer*>(new RasterPrinter) : static_cast<Printer*>(new VectorPrinter))
    {}
    virtual void print() const override{
        std::cout << printer->Circle() << std::endl;
    }
};

template<typename T>
int f(std::unique_ptr<T> ptr){
    
}

int BridgePattern(){
    Title t{__func__};

    Square a(Printer::Raster);
    Square b(Printer::Vector);
    Circle c(Printer::Raster);
    Circle d(Printer::Vector);

    std::array<Shape*, 4> array{&a,&b,&c,&d};

    for(const auto& i : array){
        i->print();
    }

    return -42;
}