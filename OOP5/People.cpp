#include <iostream>
#include "People.h"


Object::Object(void) {
	std::cout << "Abstract base object was created" << std::endl;
};
Object::~Object(void) {
	std::cout << "Abstract base object was destroyed" << std::endl;
};


Person::Person() {
	name = "";
	age = 0;
	std::cout << "Person object was created" << std::endl;
}

Person::Person(const Person& T) {
	name = T.name;
	age = T.age;
	std::cout << "Person object was created" << std::endl;
}

Person::Person(std::string name, int age) {
	this->name = name;
	this->age = age;
	std::cout << "Person object was created" << std::endl;
}

Person::~Person(void) {
	std::cout << "Person object was destroyed" << std::endl;
}

void Person::setName(std::string name) {
	this->name = name;
}

void Person::setAge(int age) {
	if (age > 0) this->age = age;
}

std::string Person::getName() {
	return this->name;
}

int Person::getAge() {
	return this->age;
}

void Person::show() {
	std::cout << "Name: " << this->name << std::endl << "Age: " << this->age << std::endl;
}

Person& Person::operator=(const Person& H) {
	if (&H == this) return *this;
	name = H.name;
	age = H.age;
	return *this;
}

std::istream& operator>>(std::istream& in, Person& H) {
	std::cout << "Enter name: ";
	in >> H.name;
	std::cout << "Enter age: ";
	in >> H.age;
	std::cout << std::endl;
	return in;
}

std::ostream& operator<<(std::ostream& out, Person& H) {
	out << "Name: " << H.name << std::endl << "Age: " << H.age << std::endl;
	return out;
}


Student::Student() {
	name = "";
	age = 0;
	subject = "";
	rank = 0;
	std::cout << "Student object was created" << std::endl;
}
Student::Student(Student& S) {
	this->name = S.name;
	this->age = S.age;
	this->subject = S.subject;
	this->rank = S.rank;
	std::cout << "Student object was created" << std::endl;
}

Student::Student(std::string name, int age, std::string subject, int rank) {
	this->name = name;
	this->age = age;
	this->subject = subject;
	this->rank = rank;
	std::cout << "Student object was created" << std::endl;
}

Student::~Student() {
	std::cout << "Student object was destroyed" << std::endl;
}
Student& Student::operator=(Student& S) {
	this->name = S.name;
	this->age = S.age;
	this->subject = S.subject;
	this->rank = S.rank;
	return *this;
}
void Student::setRank(int rank) {
	this->rank = rank;
}

int Student::getRank() {
	return this->rank;
}

void Student::setSubject(std::string subject) {
	this->subject = subject;
}

std::string Student::getSubject() {
	return this->subject;
}

void Student::checkRank() {
	switch (rank) {
	case 0: {
		std::cout << "Нет оценок по предмету " << subject << "!" << std::endl;
		break;
	}
	default:
		std::cout << "Оценка по предмету " << subject << " - " << rank << std::endl;
	}
}

void Student::show(){
	std::cout << "Name: " << this->name << std::endl << "Age: " << this->age << std::endl << "Subject: " << this->subject << std::endl << "Rank: " << this->rank << std::endl;
}

std::istream& operator>>(std::istream& in, Student& H) {
	std::cout << "Enter name: ";
	in >> H.name;
	std::cout << "Enter age: ";
	in >> H.age;
	std::cout << "Enter subject: ";
	in >> H.subject;
	std::cout << "Enter rank: ";
	in >> H.rank;
	return in;
}

std::ostream& operator<<(std::ostream& out, Student& S) {
	out << "Name: " << S.name << std::endl << "Age: " << S.age << std::endl << "Subject: " << S.subject << std::endl << "Rank: " << S.rank << std::endl;
	return out;
}
