#include <iostream>

using namespace std;

class Date {
public:
	Date() : Day(1), Month(1), Year(2000){	}

	void setDay(int d){	Day = d; }
	void setMonth(int m) { Month = m; }
	void setYaer(int y) { Year = y;	}

	friend ostream& operator<< (ostream& out, const Date& date);
private:
	int Day;
	int Month;
	int Year;
};

ostream& operator<< (ostream& out, const Date& date) {
	out << date.Day << "." << date.Month << "." << date.Year;
	return out;
}

int main() {
	unique_ptr<Date> today = make_unique<Date>();
	unique_ptr<Date> date;

	today->setDay(8);
	today->setMonth(10);
	today->setYaer(2020);
	cout << "Today:" << *today << endl;

	date = move(today);
	cout << "Date:" << *date << endl;

	if (today)
		cout << "Today is not empty" << endl;
	else
		cout << "Today is empty" << endl;

	if (date)
		cout << "Date is not empty" << endl;
	else
		cout << "Date is empty" << endl;

	return 0;   
}
