#pragma once
#include <iostream>

class Fraction
{
private:
	int Den;
	int Nom;
public:
	Fraction(int Nom, int Den) :
		Den{ Den }, Nom{ Nom }{};

	Fraction add(Fraction frac);
		
};

