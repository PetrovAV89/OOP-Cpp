#include <iostream>
#include <iomanip>

using namespace std;

ostream& endll(ostream& stream) {
	stream.put(stream.widen('\n'));
	stream.put(stream.widen('\n'));
	stream.flush();
	return stream;
}

int main() {
	cout << "GeekBrains" << endll << "OOP-Cpp" << endll << "Lesson 6" << endl << "Task 2" << endll;

	return 0;
}

