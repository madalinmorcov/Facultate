#include "Vector.h"

void main() 
{
	Vector myVect1,myVect2;
	myVect1.pushBack(4);
	myVect1.pushBack(3);

	myVect2.pushBack(4);
	myVect2.pushBack(3);

	if(myVect1==myVect2)
		cout<<!myVect1<<" "<<!myVect2<<endl;
}