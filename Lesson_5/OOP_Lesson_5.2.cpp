#include <iostream>

using namespace std;

template <class T1, class T2>
class Pair {
private:
    T1 a;
    T2 b;
public:
    Pair() : a(0), b(0) {  }

    Pair(T1 x, T2 y) : a(x), b(y) {  }

    T1 first() const { return a; }

    T2 second() const { return b; }
};

int main() {
    Pair<int, double> p1(6, 7.8);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair<double, int> p2(3.4, 5);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    return 0;
}
