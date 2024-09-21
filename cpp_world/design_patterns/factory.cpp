/*
core components are
1- Abstract creator
2- Concrete creator
3- Abstract product
4- Concrete product
5- Client

Factory Method Pattern provides an interface for creating objects but leaves the actual object instantiation to derived classes.
*/

#include <bits/stdc++.h>

// Abstract product class
class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() {}
};

// Concrete product class - Circle
class Circle : public Shape {
public:
    void draw() override {
        std::cout<<"Drawing a Circle"<< std::endl;
    }
};

// Concrete product class - Square
class Square : public Shape {
public:
    void draw() override {
        std::cout<<"Drawing a Square"<<std::endl;
    }
};

// Abstract creator class
class ShapeFactory {
public:
    virtual Shape* createShape() = 0;
    virtual ~ShapeFactory() {}
};

// Concrete creator class - CircleFactory
class CircleFactory : public ShapeFactory {
public:
    Shape* createShape() override {
        return new Circle();
    }
};

// Concrete creator class - SquareFactory
class SquareFactory : public ShapeFactory {
public:
    Shape* createShape() override {
        return new Square();
    }
};

int main() {
    ShapeFactory* circleFactory = new CircleFactory();
    ShapeFactory* squareFactory = new SquareFactory();

    Shape* circle = circleFactory->createShape();
    Shape* square = squareFactory->createShape();

    circle->draw();
    square->draw();

    delete circleFactory;
    delete squareFactory;
    delete circle;
    delete square;

    return 0;
}