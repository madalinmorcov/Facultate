#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Vector
{
private:
	int size;
	double *elements;
public:
	Vector() { size = 0;  elements = new double[size]; };
	void SetSize(int newSize) { size = newSize; };
	int GetSize() { return size; };
	double GetElemAt(int position) { return elements[position]; };
	void pushBack(double newElem);
	friend istream &operator >> (istream &flux, Vector &v);
	friend ostream &operator<<(ostream &flux, Vector v);
	double operator!();
	bool operator==(Vector m);
};


