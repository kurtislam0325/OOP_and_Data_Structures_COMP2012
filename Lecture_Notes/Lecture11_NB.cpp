#include <iostream>
using namespace std;

class Shape { // Shape is a ABC because it has a pure virtual function
    protected:
        int height;
        int width;
    public:
        Shape(int h = 0, int w = 0): height(h), width(w) {};
        virtual double get_area() = 0;
};

class Triangle: public Shape {
    public:
        Triangle(int h = 0, int w = 0): Shape(h, w) {};
        double get_area() override { return (width*height)/2;}
};

class Rectangle: public Shape {
    public:
        Rectangle(int h = 0, int w = 0): Shape(h, w) {};
        double get_area() override { return (width*height);}
        
};

int main() {
    Triangle t(5, 10); Rectangle r(5, 10);
    cout << "Area of the triangle = " << t.get_area() << endl;
    cout << "Area of the Rectangle = " << r.get_area() << endl;

    // Dynamic Binding
    Shape* ptrs[2] = {&t, &r};
    cout << ptrs[0]->get_area() << endl;
    cout << ptrs[1]->get_area() << endl;
    char x = 'A' - ('A' - 'a');
    cout << x << endl;
    return 0;
}