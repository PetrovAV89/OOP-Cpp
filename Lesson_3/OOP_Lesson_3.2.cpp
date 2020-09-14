#include <iostream>
#include <string>
using namespace std;

class Car {
protected:
	string company;
	string model;
public:
	Car() {
		cout << "Class CAR:" << endl;
	}
};

class PassengerCar : virtual public Car {
public:
	PassengerCar() {
		company = "Audi";
		model = "A8";
		cout << "Passenger Car: " << company << " " << model << endl;
	}
};

class Bus : virtual public Car {
public:
	Bus() {
		company = "Mercedes-Benz";
		model = "Conecto";
		cout << "Bus: " << company << " " << model << endl;
	}
};

class Minivan : public PassengerCar, public Bus {
public:
	Minivan() {
		company = "Volkswagen";
		model = "Multivan";
		cout << "Minivan: " << company << " " << model << endl;
	}
};

int main() {
	PassengerCar car;
	cout << endl;
	Bus bus;
	cout << endl;
	Minivan minivan;
	
	return 0;
}