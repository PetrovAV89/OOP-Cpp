#include <iostream>

using namespace std;

class Ex {
private:
	int x;
public:
	Ex(int q) : x(q) { }
	int getEx() const {	return x; }
};

class Bar {
private:
	int y;
public:
	Bar() : y(0) { }
	void setBar(int a) {
		if (y + a > 100)
			throw Ex(y*a);		
		else 
			y = a;		
	}
};

int main() {
	Bar bar;
	int n;
	while (true) {
		try {
			cin >> n;
			if (!n)
				break;
			bar.setBar(n);
		}
		catch (Ex er) {
			cerr << "Error! Ex(a*y) = " << er.getEx() << endl;
		}
	}

	return 0;
}