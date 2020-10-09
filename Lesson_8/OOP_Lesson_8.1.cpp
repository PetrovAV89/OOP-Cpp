#include <iostream>

using namespace std;

double div_1 (int a, int b) {
	double res = 0;
	if (!b) 
		throw "Division By Zero";
	else 
		res = (double)a / b;
	return res;
}

int main() {
	int x, y;
	cout << "Enter the first value: ";
	cin >> x;
	cout << "Enter the second value: ";
	cin >> y;
	try {
		cout << div_1(x, y);
	}		
	catch (const char* ex) {
		cerr << "Error: " << ex << endl;
	}		

	return 0;   
}

