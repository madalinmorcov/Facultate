#include <iostream>
#include <fstream>

using namespace std;

struct nod {
	int info, bh;
	char color;
	nod *p, *st, *dr;
};

struct ARN {
	nod *nil, *rad;
	ARN() {
		nil = new nod;
		nil->color = 'N';
		nil->st = nil->dr = nil;
		rad = nil;
	}

	void insert(nod *z) {
		nod *y = nil;
		nod *x = rad;
		while (x != nil) {
			y = x;
			if (z->info < x->info)
				x = x->st;
			else
				x = x->dr;
		}
		z->p = y;
		if (y == nil)
			rad = z;
		else
			if (z->info < y->info)
				y->st = z;
			else
				y->dr = z;
		z->st = z->dr = nil;
		z->color = 'R';
		ARN_insertRepair(z);
	}

	void ARN_insertRepair(nod *z) {
		nod *u;
		while (z->p->color == 'R') {
			if (z->p == z->p->p->st) {
				u = z->p->p->dr;
				if (u->color == 'R') {
					u->color = 'N';
					z->p->color = 'N';
					z->p->p->color = 'R';
					z = z->p->p;
				}
				else {
					if (z == z->p->dr) {
						z = z->p;
						RotSt(z);
					}
					z->p->color = 'N';
					z->p->p->color = 'R';
					RotDr(z->p->p);
				}
			}
			else {
				u = z->p->p->st;
				if (u->color == 'R') {
					u->color = 'N';
					z->p->color = 'N';
					z->p->p->color = 'R';
					z = z->p->p;
				}
				else {
					if (z == z->p->st) {
						z = z->p;
						RotDr(z);
					}
					z->p->color = 'N';
					z->p->p->color = 'R';
					RotSt(z->p->p);
				}
			}
		}
		rad->color = 'N';
	}

	void RotSt(nod *z) {
		nod *y;
		y = z->dr;
		z->dr = y->st;
		if (y->st != nil)
			y->st->p = z;
		y->p = z->p;
		if (z->p == nil) 
			rad = y;
		else
			if (z == z->p->st)
				z->p->st = y;
			else
				z->p->dr = y;
		y->st = z;
		z->p = y;
	}

	void RotDr(nod *z) {
		nod *y;
		y = z->st;
		z->st = y->dr;
		if (y->dr != nil)
			y->dr->p = z;
		y->p = z->p;
		if (z->p == nil)
			rad = y;
		else
			if (z == z->p->dr)
				z->p->dr = y;
			else
				z->p->st = y;
		y->dr = z;
		z->p = y;
	}

	nod *succesor(nod *x) {
		if (x->dr != nil)
			return min(x->dr);
		else {
			nod *y = x->p;
			while (y != nil && x == y->dr) {
				x = y;
				y = y->p;
			}
			return y;
		}
	}

	void transplant(nod *u, nod *v) {
		if (u->p == nil)
			rad = v;
		else {
			if (u == u->p->st)
				u->p->st = v;
			else
				u->p->dr = v;
		}
		v->p = u->p;
	}

	//============================================================================================
	void RBDeleteRepara(nod* x)
	{
		nod* F;
		while (x != rad && x->color == 'N')
			if (x->p->st == x)

			{
				F = x->p->dr;
				if (F->color == 'R')
				{
					F->color = 'N';
					x->p->color = 'R';
					RotSt(x->p);
					F = x->p->dr;
				}
				if (F->st->color == 'N' && F->dr->color == 'N')
				{
					F->color = 'R';
					x = x->p;
				}
				else
				{
					if (F->dr->color == 'N')
					{
						F->color = 'R';
						F->st->color = 'N';
						RotDr(F);
						F = x->p->dr;
					}
					F->color = x->p->color;
					x->p->color = 'N';
					F->dr->color = 'N';
					RotSt(x->p);
					x = rad;
				}
			}
			else
				if (x->p->dr == x)
				{
					F = x->p->st;
					if (F->color == 'R')
					{
						F->color = 'N';
						x->p->color = 'R';
						RotDr(x->p);
						F = x->p->st;
					}
					if (F->dr->color == 'N' && F->st->color == 'N')
					{
						F->color = 'R';
						x = x->p;
					}
					else
					{
						if (F->st->color == 'N')
						{
							F->color = 'R';
							F->dr->color = 'N';
							RotSt(F); //????
							F = x->p->st;
						}
						F->color = x->p->color;
						x->p->color = 'N';
						F->st->color = 'N';
						RotDr(x->p);
						x = rad;
					}
				}
		x->color = 'N';
	}


	void RBDelete(nod* z)
	{
		nod* y;
		nod* x;
		y = z;
		char y_org_color;
		y_org_color = y->color;
		if (z->st == nil)
		{
			x = z->dr;
			transplant(z, x);
		}
		else
		{
			if (z->dr == nil)
			{
				x = z->st;
				transplant(z, x);
			}
			else
			{
				y = succesor(z);
				y_org_color = y->color;
				x = y->dr;
				if (y->p == z)
					x->p = y;
				else
				{
					transplant(y, x);
					y->dr = z->dr;
					y->dr->p = y;
				}
				transplant(z, y);
				y->st = z->st;
				y->st->p = y;
				y->color = z->color;
			}
		}
		if (y_org_color == 'N')
			RBDeleteRepara(x);
	}


	//=================================================================================================
	nod *cautare(int i) {
		nod *x = rad;
		while (x != nil && x->info != i) {
			if (x->info > i)
				x = x->st;
			else
				x = x->dr;
		}
		return x;
	}

	nod *min(nod *x) {
		while (x->st != nil)
			x = x->st;
		return x;
	}

	nod *max(nod *x) {
		while (x->dr != nil)
			x = x->dr;
		return x;
	}

	void RSD(nod *x) {
		if (x != nil)
		{
			cout << x->info << " " << x->color << "; ";
			if (x->st != nil)
				RSD(x->st);
			if (x->dr != nil)
				RSD(x->dr);
		}
	}

};

int main() {
	ARN *T = new ARN;
	nod *z = new nod;
	ifstream fin("data.txt");
	fin >> z->info;
	while (z->info != -42) {
		T->insert(z);
		z = new nod;
		fin >> z->info;
	}
	z = new nod;
	z = T->cautare(11);
	T->RBDelete(z);
	T->RSD(T->rad);
	//	cout << T->rad->info << " "; cout << T->rad->st->info << " "; cout << T->rad->dr->info << " ";
}