#ifndef FACTORY_METHOD_H
#define FACTORY_METHOD_H

struct Point{
    float x;
    virtual void Print() const = 0;
};
struct Point2D : public Point{
    float y;
    void Print() const override;
};
struct Point3D : public Point2D{
    float z;
    void Print() const override;
};

struct Shape{
    virtual Point* CreatePoint() const = 0;
    virtual void Print() const = 0;
};

struct Triangle : public Shape{
    Point* A;
    Point* B;
    Point* C;

    Point* CreatePoint() const override;

    Triangle();
    ~Triangle();
    void Print() const override;
};

struct Tetrahedron : public Shape{
    Point* A;
    Point* B;
    Point* C;
    Point* D;

    Tetrahedron();
    ~Tetrahedron();

    Point* CreatePoint() const override;
    void Print() const override;
};

int FactoryMethodPattern();


#endif