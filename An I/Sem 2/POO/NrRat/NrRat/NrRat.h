#pragma once
#include <iostream>

using namespace std;

class NrRat {
private:
	int a, b;
public:
	NrRat();
	NrRat(int, int);
	void setA(int);
	void setB(int);
	int getA();
	int getB();
	friend istream &operator>>(istream &flux, NrRat &n);
	friend ostream &operator<<(ostream &flux, NrRat n);
	NrRat operator+(NrRat);
	NrRat operator-(NrRat);
	NrRat operator*(NrRat);
	NrRat operator/(NrRat);
};