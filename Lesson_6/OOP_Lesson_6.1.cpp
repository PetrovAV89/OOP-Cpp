#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int i;
	while (true) {
		cout << "Enter a number: ";
		cin >> i;
		if (cin.good()) {
			cin.ignore(10, '\n');
			break;
		}
		cin.clear();
		cout << "Error!" << endl;
		cin.ignore(10, '\n');	
	}
	cout << "Number: " << i << endl;


	return 0;	
}

