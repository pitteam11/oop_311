#include "Student.h"
#include <iostream>

using namespace std;

Student::Student(string fio){
	this->fio = fio;
	//univercity = Univercity(UNIVERS::MIT);
}

void Student::set_phone(string phone) {
	if (phone.size() == 11) {
		if (phone[0] == '7')
			this->phone = "+" + phone;
		else if (phone[0] == '8') {
			phone[0] = '7';
			this->phone = "+" + phone;
		}
	}
	else if (
		phone.size() == 12 &&
		phone[0] == '+' &&
		phone[1] == '7')
		this->phone = phone;
	else
		cout << "Bad format for phone\n";
}

string Student::get_phone() {
	return phone;
}

void Student::set_city(string city) {
	this->city = city;
}

string Student::get_city() {
	return city;
}

void Student::set_country(string country) {
	this->country = country;
}

string Student::get_country() {
	return country;
}

void Student::set_age(int age) {
	if (age <= 1 || age >= 150) {
		cout << "Bad format age\n";
		return;
	}
	else {
		this->age = age;
	}
}

string Student::get_fio() {
	return fio;
}

void Student::show() {
	cout << fio << " " << phone << endl;
}

Student::~Student() {
	cout << "Hello I am destructor" << endl;
}



Univercity::Univercity(UNIVERS name)
{
	switch (name)
	{
	case UNIVERS::MSU:
		city = "Moscow";
		country = "Russia";
		break;
	case UNIVERS::SFU:
	case UNIVERS::DSTU:
		city = "Rostov-on-Don";
		country = "Russia";
		break;
	case UNIVERS::MIT:
		city = "Cambridge";
		country = "USA";
		break;
	default:
		break;
	}
}

