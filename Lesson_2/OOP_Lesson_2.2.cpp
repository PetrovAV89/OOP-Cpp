#include <iostream>
#include <string.h>

using namespace std;

class Fruit {
protected:
    string name;
    string color;

public:
    Fruit() {
    }

    string getName() const {
        return name;
    }

    string getColor() const {
        return color;
    }
};

class Apple : public Fruit {
public:
    Apple() {
        name = "apple";
        color = "green";
    }

    Apple(string color) {
        name = "apple";
        this->color = color;
    }
};

class Banana : public Fruit {
public:
    Banana() {
        name = "banana";
        color = "yellow";
    }
};

class GrannySmith : public Apple {
public:
    GrannySmith() {
        name = "GrannySmith apple";
        color = "green";
    }
};

int main()
{
    Apple a("red");
    Banana b;
    GrannySmith c;
    cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
    return 0;
}


