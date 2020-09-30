#include <iostream>
#include <string>

using namespace std;

template <class T>
class Pair {
protected:
    string Name;
    T value;
public:
    Pair(string name, T val) : Name(name), value(val) {   }

    Pair(T val) :  value(val) {   }

    string first() {
        return Name;
    }

    T second() {
        return value;
    
    }
};

template <class T>
class StringValuePair : public Pair<T> { 
public:
    StringValuePair(string name, T value) : Pair<T>(name, value) {

    }
};

int main() {
    StringValuePair<int> svp("Amazing", 7);
    cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
    return 0;
}
