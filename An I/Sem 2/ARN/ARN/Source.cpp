#include <iostream>
#include <fstream>

using namespace std;

struct nod {
	int key, bh;
	char color;
	nod *p, *left, *right;
};

struct RBT {
	nod *nil, *root;
	RBT() {
		nil = new nod;
		nil->color = 'N';
		nil->left = nil->right = nil;
		root = nil;
	}

	void insert(nod *z) {
		nod *y = nil;
		nod *x = root;
		while (x != nil) {
			y = x;
			if (z->key < x->key)
				x = x->left;
			else
				x = x->right;
		}
		z->p = y;
		if (y == nil)
			root = z;
		else
			if (z->key < y->key)
				y->left = z;
			else
				y->right = z;
		z->left = z->right = nil;
		z->color = 'R';
		RBT_insertRepair(z);
	}

	void RBT_insertRepair(nod *z) {
		nod *u;
		while (z->p->color == 'R') {
			if (z->p == z->p->p->left) {
				u = z->p->p->right;
				if (u->color == 'R') {
					u->color = 'N';
					z->p->color = 'N';
					z->p->p->color = 'R';
					z = z->p->p;
				}
				else {
					if (z == z->p->right) {
						z = z->p;
						Rot_Left(z);
					}
					z->p->color = 'N';
					z->p->p->color = 'R';
					Rot_Right(z->p->p);
				}
			}
			else {
				u = z->p->p->left;
				if (u->color == 'R') {
					u->color = 'N';
					z->p->color = 'N';
					z->p->p->color = 'R';
					z = z->p->p;
				}
				else {
					if (z == z->p->left) {
						z = z->p;
						Rot_Right(z);
					}
					z->p->color = 'N';
					z->p->p->color = 'R';
					Rot_Left(z->p->p);
				}
			}
		}
		root->color = 'N';
	}

	void Rot_Left(nod *z) {
		nod *y;
		y = z->right;
		z->right = y->left;
		if (y->left != nil)
			y->left->p = z;
		y->p = z->p;
		if (z->p == nil) 
			root = y;
		else
			if (z == z->p->left)
				z->p->left = y;
			else
				z->p->right = y;
		y->left = z;
		z->p = y;
	}

	void Rot_Right(nod *z) {
		nod *y;
		y = z->left;
		z->left = y->right;
		if (y->right != nil)
			y->right->p = z;
		y->p = z->p;
		if (z->p == nil)
			root = y;
		else
			if (z == z->p->right)
				z->p->right = y;
			else
				z->p->left = y;
		y->right = z;
		z->p = y;
	}

	nod *successor(nod *x) {
		if (x->right != nil)
			return min(x->right);
		else {
			nod *y = x->p;
			while (y != nil && x == y->right) {
				x = y;
				y = y->p;
			}
			return y;
		}
	}

	void transplant(nod *u, nod *v) {
		if (u->p == nil)
			root = v;
		else {
			if (u == u->p->left)
				u->p->left = v;
			else
				u->p->right = v;
		}
		v->p = u->p;
	}

	void RedBlackDeleteRepair(nod* x) {
		nod* y;
		while (x != root && x->color == 'N')
			if (x->p->left == x) {
				y = x->p->right;
				if (y->color == 'R') {
					y->color = 'N';
					x->p->color = 'R';
					Rot_Left(x->p);
					y = x->p->right;
				}
				if (y->left->color == 'N' && y->right->color == 'N') {
					y->color = 'R';
					x = x->p;
				}
				else {
					if (y->right->color == 'N') {
						y->color = 'R';
						y->left->color = 'N';
						Rot_Right(y);
						y = x->p->right;
					}
					y->color = x->p->color;
					x->p->color = 'N';
					y->right->color = 'N';
					Rot_Left(x->p);
					x = root;
				}
			}
			else
				if (x->p->right == x) {
					y = x->p->left;
					if (y->color == 'R') {
						y->color = 'N';
						x->p->color = 'R';
						Rot_Right(x->p);
						y = x->p->left;
					}
					if (y->right->color == 'N' && y->left->color == 'N') {
						y->color = 'R';
						x = x->p;
					}
					else {
						if (y->left->color == 'N') {
							y->color = 'R';
							y->right->color = 'N';
							Rot_Left(y);
							y = x->p->left;
						}
						y->color = x->p->color;
						x->p->color = 'N';
						y->left->color = 'N';
						Rot_Right(x->p);
						x = root;
					}
				}
		x->color = 'N';
	}

	void RedBlackDelete(nod* z) {
		nod* y;
		nod* x;
		y = z;
		char yOriginalColor;
		yOriginalColor = y->color;
		if (z->left == nil) {
			x = z->right;
			transplant(z, x);
		}
		else {
			if (z->right == nil) {
				x = z->left;
				transplant(z, x);
			}
			else {
				y = successor(z);
				yOriginalColor = y->color;
				x = y->right;
				if (y->p == z)
					x->p = y;
				else {
					transplant(y, x);
					y->right = z->right;
					y->right->p = y;
				}
				transplant(z, y);
				y->left = z->left;
				y->left->p = y;
				y->color = z->color;
			}
		}
		if (yOriginalColor == 'N')
			RedBlackDeleteRepair(x);
	}

	nod *search(int i) {
		nod *x = root;
		while (x != nil && x->key != i) {
			if (x->key > i)
				x = x->left;
			else
				x = x->right;
		}
		return x;
	}

	nod *min(nod *x) {
		while (x->left != nil)
			x = x->left;
		return x;
	}

	nod *max(nod *x) {
		while (x->right != nil)
			x = x->right;
		return x;
	}

	void RootLR(nod *x) {
		if (x != nil)
		{
			cout << x->key << " " << x->color << "; ";
			if (x->left != nil)
				RootLR(x->left);
			if (x->right != nil)
				RootLR(x->right);
		}
	}

};

int main() {
	RBT *Tree = new RBT;
	nod *z = new nod;
	ifstream inputFile("data.txt");
	inputFile >> z->key;
	while (z->key != -42) {
		Tree->insert(z);
		z = new nod;
		inputFile >> z->key;
	}
	z = new nod;
	z = Tree->search(11);
	Tree->RedBlackDelete(z);
	Tree->RootLR(Tree->root);
}