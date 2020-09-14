#include <iostream>
using namespace std;

class Fraction{ 
private:
	int numerator;
	int denominator;

public:
	Fraction() : numerator(1), denominator(1) {
	}

	Fraction(int n, int d)  {
		numerator = n;
		if (d)
			denominator = d;
		else {
			cout << "Error, cannot be divided by 0";
			exit(0);
		}
	}

	Fraction operator+(Fraction &f) {
		Fraction res;
		if (denominator == f.denominator) {
			res.denominator = denominator;
			res.numerator = numerator + f.numerator;
		} else {
			res.denominator = denominator * f.denominator;
			res.numerator = (numerator * f.denominator) + (f.numerator * denominator);
		}
		return res;
	}

	Fraction operator-(Fraction &f) {
		Fraction res;
		if (denominator == f.denominator) {
			res.denominator = denominator;
			res.numerator = numerator - f.numerator;
		} else {
			res.denominator = denominator * f.denominator;
			res.numerator = (numerator * f.denominator) - (f.numerator * denominator);
		}
		return res;
	}

	Fraction operator*(Fraction &f) {
		Fraction res;
		res.numerator = numerator * f.numerator;
		res.denominator = denominator * f.denominator;
		return res;
	}

	Fraction operator/(Fraction &f) {
		Fraction res;
		Fraction res_1;
		Fraction res_2;
		res_1 = Fraction(f.denominator, f.numerator);
		res_2 = Fraction(numerator, denominator);
		res = res_1 * res_2;
		return res;
	}

	bool operator== (const Fraction &f) const {
		return numerator == f.numerator && denominator == f.denominator;
	}

	bool operator!= (const Fraction &f) const {
		return !(*this == f);
	}

	bool operator> (const Fraction &f) const {
		if (denominator == f.denominator) {
			return denominator > f.denominator;
		}
		else {
			return (numerator * f.denominator) > (denominator * f.numerator);
		}
	}

	bool operator<= (const Fraction &f) const {
		return !(*this > f);
	}

	bool operator< (const Fraction &f) const {
		if (denominator == f.denominator) {
			return denominator < f.denominator;
		}
		else {
			return (numerator * f.denominator) < (denominator * f.numerator);
		}
	}

	bool operator>= (const Fraction &f) const {
		return !(*this < f);
	}

	//Fraction operator-(const Fraction &f) {
	//	return Fraction(-f.numerator, f.denominator);
	//}

	void print() const {
		cout << numerator << "/" << denominator << endl;
	}
};

int main() {
	Fraction d1(3,4);
	d1.print();

	Fraction d2(2,5);
	d2.print();

	Fraction res1 = d1 + d2; cout << "+: ";
	res1.print();

	Fraction res2 = d1 - d2; cout << "-: ";
	res2.print();

	Fraction res3 = d1 * d2; cout << "*: ";
	res3.print();

	Fraction res4 = d1 / d2; cout << "/: ";
	res4.print();

	int x = (d1 == d2);
	cout << "==: " << x << endl;
	int y = (d1 != d2);
	cout << "!=: " << y << endl;
	
	int n = d1 > d2;
	cout << ">: " << n << endl;
	int h = d1 <= d2;
	cout << "<=: " << h << endl;

	int m = d1 < d2;
	cout << "<: " << m << endl;
	int g = d1 >= d2;
	cout << ">=: " << g << endl;

	return 0;
}
