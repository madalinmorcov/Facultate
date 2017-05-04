#include "Arb-avl.h"

AVL::AVL()
{
	nil = new node;
	nil->fb = 0;
	nil->left = nil->right = nil->p = nil;
	this->root = this->nil;
}

AVL::~AVL()
{
}


node * AVL::search(int z)
{
	node *q = this->root;
	while (q != nil && z != q->key)
	{
		if (z > q->key)
			q = q->right;
		else q = q->left;
	}
	return q;
}

void AVL::In_order(node * q)
{
		if (q == nil)
			return;
		In_order(q->left);
		cout<<q->key<<" ";
	In_order(q->right);
}

void AVL::Pre_order(node *q)
{
	if (q!= nil)
	{
		cout << q->key<<" ";
		if (q->left != nil)
			Pre_order(q->left);
		if (q->right != nil)
			Pre_order(q->right);
	}
}

void AVL::Rot_left(node * q)
{
	node *y;
	y = q->right;
	q->right = y->left;
	if (y->left != nil)
		y->left->p = q;
	y->p = q->p;
	if (q->p == nil)
		this->root = y;
	else
	{
		if (q == q->p->left)
			q->p->left = y;
		else q->p->right = y;

	}
	y->left = q;
	q->p = y;
}

void AVL::Rot_right(node * q)
{
	{
		node *y;
		y = q->left;
		q->left = y->right;
		if (y->right != nil)
			y->right->p = q;
		y->p = q->p;
		if (q->p == nil)
			this->root = y;
		else
		{
			if (q == q->p->right)
				q->p->right = y;
			else q->p->left = y;

		}
		y->right = q;
		q->p = y;
	}
}

void AVL::FB(node *q,int path)
{
	if (path == 0)
	{
		q->fb--;
		if (q->fb == -2)
			repair(q, path);
		else if (q->fb == 0)
			return;
		else
		{
			if (q->p != nil) {
				if (q->p->left == q)
					path = 0;
				else
					path = 1;
				FB(q->p, path);
			}
		}
	}
	else
		if (path == 1)
		{
			q->fb++;
			if (q->fb == 2)
				repair(q, path);
			else if (q->fb == 0)
				return;
			else
			{
				if (q->p != nil) {
					if (q->p->left == q)
						path = 0;
					else
						path = 1;
					FB(q->p, path);
				}
			}
		}
}


void AVL::insertie(int z)
{
	node *k;

	if (this->root == nil)
	{
		this->root = new node;
		this->root->p = nil;
		this->root->fb = 0;
		this->root->key = z;
		this->root->left = nil;
		this->root->right = nil;
	}
	else
	{
		node *q = new node;
		k = root;
		while (k != nil)
		{
			q = k;
			if (z > k->key )
			{
				k = k->right;
			}
			else {
				k = k->left;
			}

		}
		
		k = new node;
		k->key = z;
		k->fb = 0;
		k->left = nil;
		k->right = nil;
		k->p = q;
		if (q->key > k->key)
		{
			q->left = k;
			FB(k->p, 0);
		}
		else
		{
			q->right = k;
			FB(k->p, 1);
		}

		
	} 
	
}

void AVL::stergere(int z)
{
}

void AVL::repair(node * k,int path)
{
	
	if (k->fb == 0)
		return;
	if (k->fb != -2 && k->fb != 2)
	{
		if(k->p!=nil)
			if (k->p->left == k)
				path = 0;
			else 
				path = 1;
		return repair(k->p, path);
	}
	else if (k->fb == -2)
	{
		node *y;
		if(path==0)
		y = k->left;
		else y = k->right;
		if (y->fb == -1) {
			this->Rot_right(k);
			y->fb = 0;
			k->fb = 0;
		}
		else if (y->fb == 1)
		{
			this->Rot_left(y);
			y->fb = 0;
			y = y->p;
			this->Rot_right(k);
			y->fb = 0;
			k->fb = 1;
		}
		if (k->p != nil)
			if (k->p->left == k)
				path = 0;
			else 
				path = 1;
		return repair(k->p, path);
	}
	else if (k->fb == 2)
	{

		node *y;
		if (path == 0)
			y = k->left;
		else y = k->right;
		if (y->fb == 1) {
			this->Rot_left(k);
			y->fb = 0;
			k->fb = 0;
		}
		else if (y->fb == -1)
		{
			this->Rot_right(y);
			y->fb = 0;
			y = y->p;
			this->Rot_left(k);
			y->fb = 0;
			k->fb = -1;
		}
		if (k->p != nil)
			if (k->p->left == k)
				path = 0;
			else
				path = 1;
		return repair(k->p, path);
		
	}
	return;
}


