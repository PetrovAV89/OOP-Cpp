#include <iostream>
#include <iomanip>
#include <locale.h>  

using namespace std;

class Power {
public:
	Power() : x(3), y(4) {
	}

	void Set(int num1, int num2) {
		x = num1;
		y = num2;
	}

	void Calculate() {
		int res = x;
		for (int i = 2; i <= y; i++) {
			res = res * x;
		}
		cout << "Число " << x << " в степени " << y << " равно " << res << endl;
	}

private:
	int x;
	int y;
};

int main() {
	setlocale (LC_ALL, "rus");
	Power a, b;
	a.Calculate();

	b.Set(2, 4);
	b.Calculate();

	return 0;
}
