#include "Arb-avl.h"
using namespace std;

void main()
{
	AVL t;
	t.insertie(7);
	t.insertie(10);
	t.insertie(14);
	t.insertie(3);
	t.insertie(9);
	t.insertie(8);
	t.insertie(11);
	t.insertie(25);
	
	t.Pre_order(t.root);
		
}