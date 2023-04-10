#include <iostream>
#include <string>

using namespace std;

struct Shape
{
    virtual string str() const = 0;
};

struct Circle : Shape
{
    float radius;
    Circle(float radius) : radius(radius) {}

    void resize(float factor)
    {
        radius *= factor;
    }
    string str() const override
    {
    }
};

struct Square : Shape
{
    float side;
    Square() {}
    Square(float side) : side(side) {}
    string str() const override {}
};

struct ColoredShape : Shape
{
    Shape &shape;
    string color;

    ColoredShape(Shape &shape, const string &color) : shape(shape), color(color) {}
    string str() const override
    {
        // do something to extend
        shape.str(); // <-- this is point
    }
};

struct TransparentShape : Shape
{
    Shape &shape;
    uint8_t transparency;

    TransparentShape(Shape &shape, uint8_t transparency) : shape(shape), transparency(transparency) {}
    string str() const override {}
}

int
main(int argc, char const *argv[])
{
    Circle circle{5};
    ColoredShape red_circle{circle, "red"};
    cout << circle.str() << endl
         << red_circle.str() << endl;

    TransparentShape my_square{red_circle, 51};
    cout << my_square << endl;

    return 0;
}
