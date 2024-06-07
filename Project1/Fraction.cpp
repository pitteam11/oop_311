#include "Fraction.h"

#include <iostream>

using namespace std;

Fraction Fraction::add(Fraction frac){
	int res_nom = Den * frac.Nom + Nom * frac.Den;
	int res_den = Den * frac.Den;
	return Fraction(res_nom, res_den);
}

void Fraction::show(){
	cout <<  Nom << "/" << Den;	
}


