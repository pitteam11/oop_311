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
			case Student::MSU:
				city = "Moscow";
				country = "Russia";
				break;
			case Student::SFU:				
			case Student::DSTU:
				city = "Rostov-on-Don";
				country = "Russia";
				break;
			case Student::MIT:
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
	Student(){
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
	
	void show() {
		cout << fio << " " << phone << endl;
	}

	~Student(){
		cout << "Hello I am destructor" << endl;
	}
};

void test_student() {
	Student student;
	
	string s;
	cout << "Enter the phone" << endl;
	cin >> s;
	student.set_phone(s);
	cout << "This is phone: ";
	cout << student.get_phone();
	
	//student.show();	
}