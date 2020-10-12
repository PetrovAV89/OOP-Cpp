#include <iostream>

using namespace std;

template <class T>
class Pair1 {
private:
    T x;
    T y;
public:
    Pair1() : x(0), y(0) { }

    Pair1(T x, T y) : x(x), y (y) { }
    
    T first() const { return x; }

    T second() const { return y; }
};

int main() {
    Pair1<int> p1(6, 9);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    return 0;
}