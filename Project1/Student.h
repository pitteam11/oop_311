#pragma once
#include <iostream>

using namespace std;

enum UNIVERS { MSU, SFU, DSTU, MIT };

class Univercity {
private:
	UNIVERS name;
	string city;
	string country;
public:
	Univercity(UNIVERS name);
};

class Student {

private:
	string fio;
	int age;
	string phone;
	string city;
	string country;
	Univercity univercity{ UNIVERS::MIT};

public:
	Student(string fio);
	void set_phone(string phone);
	string get_phone();	
	void set_city(string city);
	string get_city();
	void set_country(string country);
	string get_country();
	void set_age(int age); 
	string get_fio();
	void show();

	~Student();
};