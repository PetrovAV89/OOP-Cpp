#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

class Person {
protected:
    string name;    
    string gender;
    int age;
    int weight;

public:
    Person() : name("Andrey Petrov"), gender("male"), age(30), weight(80) {
    }

    Person (string name, string gender, int age, int weight) : name(name), gender(gender), age(age), weight(weight) {
    }

    void setName(string name) {
        this->name = name;
    }

    void setAge(int age) {
        this->age = age;
    }

    void setWeight(int weight) {
        this->weight = weight;
    }
};

class Student : public Person {
private:
    int year;

public:
    Student() : Person(), year(2020) {
        numb++;
    }

    Student(string name, string gender, int age, int weight, int year) {
        this->name = name;
        this->gender = gender;
        this->age = age;
        this->weight = weight;
        this->year = year;
        numb++;
    }

    void setYear(int year) {
        this->year = year;
    }

    void setAddYear() {
        year++;
    }

    void print() {
        cout << "Student's name: " << setw(14) << name  << "; gender: " << setw(6) << gender 
            << "; age: " << age  << "; weight: " << weight  << "; year of study: " << year << endl << endl;
       
    }

    ~Student() {
        numb--;
    }

    static int numb;
};

int Student::numb = 0;

int main()
{
    Student a;
    a.print();

    Student b("Ivanov Ivan", "male", 23, 70, 2019);
    b.print();

    Student c("Smirnova Irina", "female", 25, 56, 2017);
    c.print();

    b.setAge(24);
    b.setYear(2020);
    b.setWeight(75);
    b.print();

    c.setAddYear();
    c.setName("Ivanova Irina");
    c.setAge(26);
    c.print();

    cout << "Total students: " << Student::numb << endl;
    return 0;
}
