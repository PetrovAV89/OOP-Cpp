#include <iostream>
#define SIZE 10

using namespace std;

class Stack {
private:
	int array[SIZE];
	int count;

public:
	void reset()
	{
		count = -1;
		for (int i = 0; i < SIZE; i++) {
			array[i] = 0;
		}
	}

	bool push(int data) {
		if (count < SIZE) {
			array[++count] = data;
			return true;
		}
		else {
			cout << "Stack overflow" << endl;
			return false;
		}
	}

	int pop() {
		if (count != -1) {
			return array[--count];
		}
		else {
			cout << "Stack is empty" << endl;
			return -1;
		}
	
	}

	void print()
	{
		cout << "( " ;
		for (int i = 0; i <= count; i++) {
			cout << array[i] << " ";
		}
		cout << ")" << endl;
	}
};

int main()
{
	Stack stack;
	stack.reset();
	stack.print();

	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();
	stack.print();

	return 0;
}
