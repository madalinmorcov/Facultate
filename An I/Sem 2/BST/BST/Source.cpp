#include <iostream>
#include <fstream>

using namespace std;

struct nod {
	int info;
	nod *st, *dr, *p;
	nod() {
		st = dr = p = NULL;
	}
};

struct arbore {
	nod *rad;
	arbore() {
		rad = NULL;
	}
	void insert(nod *z) {
		nod *x = new nod();
		x = rad;
		nod *y = NULL;
		while (x != NULL) {
			y = x;
			if (z->info > x->info)
				x = x->dr;
			else
				x = x->st;
		}
		z->p = y;
		if (y == NULL)
			rad = z;
		else
			if (y->info > z->info)
				y->st = z;
			else
				y->dr = z;
	}
	nod *cautare(int i) {
		nod *x = rad;
		while (x != NULL && x->info != i) {
			if (x->info > i)
				x = x->st;
			else
				x = x->dr;
		}
		return x;
	}

	nod *min(nod *x) {
		while (x->st != NULL)
			x = x->st;
		return x;
	}

	nod *max(nod *x) {
		while (x->dr != NULL)
			x = x->dr;
		return x;
	}

	nod *succesor(nod *x) {
		if (x->dr != NULL)
			return min(x->dr);
		else {
			nod *y = x->p;
			while (y != NULL && x == y->dr) {
				x = y;
				y = y->p;
			}
			return y;
		}
	}

	void translpant(nod *u, nod *v) {
		if (u->p == NULL)
			rad = v;
		else {
			if (u == u->p->st)
				u->p->st = v;
			else
				u->p->dr = v;
		}
		if (v != NULL)
			v->p = u->p;
	}

	void stergere(nod *z) {
		if (z->st == NULL)
			translpant(z, z->dr);
		else
			if (z->dr == NULL)
				translpant(z, z->st);
			else {
				nod *y = succesor(z);
				if (y != z->dr) {
					translpant(y, y->dr);
					y->dr = z->dr;
					z->dr->p = y;
				}
				translpant(z, y);
				y->st = z->st;
				z->st->p = y;
			}
			delete z;
	}

	void RSD(nod *x) {
		cout << x->info<<" ";
		if(x->st!=NULL)
			RSD(x->st);
		if(x->dr!=NULL)
			RSD(x->dr);
	}

	void SRD(nod *x) {
		
		if (x->st != NULL)
			SRD(x->st);
		cout << x->info << " ";
		if (x->dr != NULL)
			SRD(x->dr);
	}

	void SDR(nod *x) {
		
		if (x->st != NULL)
			SDR(x->st);
		if (x->dr != NULL)
			SDR(x->dr);
		cout << x->info << " ";
	}
};

int main() {
	arbore *T = new arbore();
	nod *x = new nod();
	int n, key;
	ifstream f("data.txt");
	f >> n;
	for (int i = 0; i < n; i++) {
		f >> key;
		x = new nod();
		x->info = key;
		T->insert(x);
	}
	x = new nod();
	x->info = 18;
	T->insert(x);
	T->stergere(T->cautare(22));
	
	T->RSD(T->rad);
	cout << endl;
	T->SRD(T->rad);
	cout << endl;
	T->SDR(T->rad);
	cout << endl;

	
	return 0;
}