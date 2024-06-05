#pragma once
#include <iostream>

using namespace std;

class Student {
	
	enum UNIVERS {MSU, SFU, DSTU, MIT};

	class Univercity {
	private:
		UNIVERS name;
		string city;
		string country;

	public:
		Univercity(UNIVERS name) {
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
	};

private:
	string fio;
	int age;
	string phone;
	string city;
	string country;
	//Univercity univercity;

public:
	Student(string fio){
		this->fio = fio;
		//univercity = Univercity(UNIVERS::MIT);
	}

	void set_phone(string phone) {
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

	string get_phone() {
		return phone;
	}
	
	void set_city(string city) {
		this->city = city;
	}

	string get_city() {
		return city;
	}

	void set_country(string country) {
		this->country = country;
	}

	string get_country() {
		return country;
	}

	void set_age(int age) {
		if (age <= 1 || age >= 150) {
			cout << "Bad format age\n";
			return;
		}
		else {
			this->age = age;
		}
	}

	string get_fio() {
		return fio;
	}

	void show() {
		cout << fio << " " << phone << endl;
	}

	~Student(){
		cout << "Hello I am destructor" << endl;
	}
};

void test_student() {
	Student student = Student("Goncharov Petr Petrovich");
	
	string s;
	cout << "Enter the phone" << endl;
	//cin >> s;
	s = "89281234567";
	student.set_phone(s);
	cout << "This is phone: ";
	cout << student.get_phone() << endl;
	
	student.show();	
}