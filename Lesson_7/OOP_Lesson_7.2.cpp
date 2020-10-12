#include <iostream>

using namespace std;

class Date {
public:
	Date() : Day(1), Month(1), Year(2000) {	}

	void setDay(int d) { Day = d; }

	void setMonth(int m) { Month = m; }

	void setYaer(int y) { Year = y; }

	int getDay() { return Day;  }

	int getMonth() { return Month; }

	int getYear() { return Year; }

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

Date &comparison(const unique_ptr<Date> &d1, const unique_ptr<Date> &d2) {
	if ((d1->getYear() > d2->getYear())) 
		return *d1;
	else if (d1->getYear() < d2->getYear()) 
		return *d2;

	if ((d1->getMonth() > d2->getMonth())) 
		return *d1;
	else if (d1->getMonth() < d2->getMonth()) 
		return *d2;

	if ((d1->getDay() > d2->getDay())) 
		return *d1;
	else if (d1->getDay() < d2->getDay()) 
		return *d2;

	return *d1;		
}

void exchange(unique_ptr<Date> &d1, unique_ptr<Date> &d2) {
	unique_ptr<Date> temp = move(d1);
	d1 = move(d2);
	d2 = move(temp);
}


int main()
{
	unique_ptr<Date> date1 = make_unique<Date>();
	unique_ptr<Date> date2 = make_unique<Date>();
	date1->setDay(8);
	date1->setMonth(10);
	date1->setYaer(2020);
	cout << "Date1:" << *date1 << endl;

	date2->setDay(20);
	date2->setMonth(10);
	date2->setYaer(2020);
	cout << "Date2:" << *date2 << endl;

	cout << comparison(date1, date2) << endl;

	exchange(date1, date2);
	cout << "Date1:" << *date1 << endl;
	cout << "Date2:" << *date2 << endl;

	return 0;
}