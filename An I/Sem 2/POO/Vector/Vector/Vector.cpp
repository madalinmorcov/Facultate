#include "Vector.h"

istream & operator >> (istream & flux, Vector & v)
{
	flux >> v.size;
	for (int iterator = 0; iterator < v.size; iterator++)
		flux >> v.elements[iterator];
	return flux;
}

ostream & operator<<(ostream & flux, Vector v)
{
	flux << "Size: " << v.size;
	for (int iterator = 0; iterator < v.size; iterator++)
		flux << v.elements[iterator]<<" ";
	flux << endl;
	return flux;
}

void Vector::pushBack(double newElem)
{
	size++;
	realloc(elements, sizeof(double)*size);
	elements[size - 1] = newElem;
}

double Vector::operator!()
{
	double sum=0.0;
	for (int iterator = 0; iterator < size; iterator++)
		sum += elements[iterator]*elements[iterator];
	return sqrt(sum);
}

bool Vector::operator==(Vector v)
{
	for (int iterator = 0; iterator < size; iterator++)
		if(this->elements[iterator] != v.elements[iterator])
			return false;
	return true;
}
