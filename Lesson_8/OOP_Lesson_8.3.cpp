#include <iostream>
#include <string>

using namespace std;

class Exception {
public:
	static void OffTheField(int x, int y, string str)  {
		cerr << "Current coordinate: X = " << x << ", Y = " << y << ". Direction of movement: " << str << endl;
	}

	static void IllegalCommand() {
		cerr << "Incorrect command" << endl;
	}
};

class Robot {
private:
	int x;
	int y;
public:
	Robot() : x(0), y(0) { }

	void Up()
	{
		if (y + 1 > 10) {
			Exception::OffTheField(x, y, "Up");
		}
		else y++;
		show_coordinates();
	}

	void Down() {
		if (y - 1 < 0)
			Exception::OffTheField(x, y, "Down");
		else
			y--;
		show_coordinates();	
	}

	void Right() {
		if (x + 1 > 10)
			Exception::OffTheField(x, y, "Right");
		else
			x++;
		show_coordinates();
	}

	void Left() {
		if (x - 1 < 0)
			Exception::OffTheField(x, y, "Left");
		else
			x--;
		show_coordinates();
	}

	void show_coordinates() {
		cout << "Coordinates X = " << x << ", Y = " << y << endl;
	}
};
 


int main() {
	Robot robot;
	char ch;

	cout << "The robot moves up - click 'W'" << endl
		<< "The robot moves down - click 'S'" << endl
		<< "The robot moves to the right - click 'D'" << endl
		<< "The robot moves to the left - click 'A'" << endl
		<< "Exit - click 'Q'" << endl;

	while (true) {
		cin >> ch;
		switch (ch) {
		case 'W':
		case 'w': robot.Up(); break;
		case 'S':
		case 's': robot.Down(); break;
		case 'D':
		case 'd': robot.Right(); break;
		case 'A':
		case 'a':  robot.Left(); break;
		case 'Q':
		case 'q': exit(1);
		default: Exception::IllegalCommand(); break;
		}		
	}
		return 0;
}