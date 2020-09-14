#include <iostream>
#define PI 3.14
using namespace std;

class Figure {
public:
    virtual void area() = 0;
};

class Parallelogram : public Figure { //S = a⋅h
protected:
    int a;
    int b;
public:
    Parallelogram() : a(1), b(1) {    
    }
    Parallelogram(int x, int y) : a(x), b(y) {
    }

    void area() override {
        cout << "Area of a parallelogram with side " << a << " and height " << b << " = " << a * b << endl;
    }
};

class Circle : public Figure {   // S = PI * r²
private: 
    int rad;
public:
    Circle() : rad(1) { 
    }
    Circle(int x) : rad(x) {
    }

    void area() override { 
        cout << "The area of a circle with a radius of " << rad <<  " = " << rad * rad * PI << endl;
    }
};

class Rectangle : public Parallelogram {  // S = a* b
public:
    Rectangle() : Parallelogram() {
    }
    Rectangle(int x, int y){
        a = x;
        b = y;
    }

    void area() override{
        cout << "Area of a rectangle with sides " << a << " and " << b << " = " << a * b << endl;
    }
};

class Square : public Parallelogram { //S=a²
public:
    Square() : Parallelogram() {
    }
    Square(int x) {
        a = x;
    }

    void area() override {
        cout << "The area of a square with a side " << a << " = " << a * a << endl;
    }
};

class Rhombus : public Parallelogram { // S=ah   
public:
    Rhombus() : Parallelogram() {
    }
    Rhombus(int x, int y) {
        a = x;
        b = y;
    }

    void area() override {
        cout << "Area of a rhombus with side " << a <<  " and height "  << b << " = " << a * b << endl;
    }
};

int main()
{
    Circle circle(5);    
    Figure* figure_1 = &circle;    
    figure_1->area();
    cout << endl;

    Parallelogram parallelogram;
    Figure* figure_2 = &parallelogram;
    figure_2->area();
    cout << endl;

    Rhombus rhombus(3, 7);
    Figure* figure_3 = &rhombus;
    figure_3->area();
    cout << endl;

    Square square(4);
    Figure* figure_4 = &square;
    figure_4->area();
    cout << endl;

    Rectangle rectangle(4, 6);
    Figure* figure_5 = &rectangle;
    figure_5->area();

    return 0;
}
