#include <FactoryMethod.h>
#include <iostream>

void Point2D::Print() const {
    std::cout << x << ' ' << y << std::endl;
}
void Point3D::Print() const {
    std::cout << x << ' ' << y << ' ' << z << std::endl;
}

Triangle::Triangle(){
    A = CreatePoint();
    B = CreatePoint();
    C = CreatePoint();
}
Triangle::~Triangle(){
    delete A;
    delete B;
    delete C;
}
Point* Triangle::CreatePoint() const {
    return new Point2D(); 
}
void Triangle::Print() const{
    A->Print();
    B->Print();
    C->Print();
}


Tetrahedron::Tetrahedron(){
    A = CreatePoint();
    B = CreatePoint();
    C = CreatePoint();
    D = CreatePoint();
}
Tetrahedron::~Tetrahedron(){
    delete A;
    delete B;
    delete C;
    delete D;
}
Point* Tetrahedron::CreatePoint() const {
    return new Point3D(); 
}

void Tetrahedron::Print() const{
    A->Print();
    B->Print();
    C->Print();
    D->Print();
}


int FactoryMethod(){
    Triangle t1;
    Tetrahedron t2;

    t1.Print();
    t2.Print();

    return -42;
}