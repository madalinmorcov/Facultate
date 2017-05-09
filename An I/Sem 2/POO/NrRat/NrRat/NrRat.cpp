#include "NrRat.h"

NrRat::NrRat() {
	a = b = 0;
}

NrRat::NrRat(int d, int i) {
	a = d;
	b = i;
}

void NrRat::setA(int d) {
	a = d;
}

void NrRat::setB(int i) {
	b = i;
}

int NrRat::getA() {
	return a;
}

int NrRat::getB() {
	return b;
}

NrRat NrRat::operator+(NrRat n) {
	a = a*n.b + n.a*b;
	b = b*n.b;
	return (*this);
}

NrRat NrRat::operator-(NrRat n) {
	a = a*n.b - n.a*b;
	b = b*n.b;
	return (*this);
}

NrRat NrRat::operator*(NrRat n) {
	a = a*n.a;
	b = b*n.b;
	return (*this);
}

NrRat NrRat::operator/(NrRat n) {
	a = a*n.b;
	b = b*n.a;
	return (*this);
}

bool operator<(NrRat n)
{
	double x = (double)a/b;
	double y = (double)n.a/n.b;
	if(x<y)
		return true;
	return false;
}
istream & operator>>(istream & flux, NrRat & n) {
	cout << "Numarator: ";
	flux >> n.a;
	cout << "Numitor:";
	flux >> n.b;
	return flux;
}

ostream & operator<<(ostream & flux, NrRat n)
{
	// TODO: insert return statement here
	cout << n.a << "/" << n.b << "\n";
	return flux;
}
